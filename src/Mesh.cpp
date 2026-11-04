#include <iostream>
#include <cmath>
#include "Mesh.h"

using namespace std;

Mesh::Mesh(vector<Vector3> v, vector<uint32_t> p) {
    vertices = v;
    polygons = p;
}

void Mesh::print() {
    cout << "Mesh::print is not currently implemented";
}

bool Mesh::intersect_triangle(const Ray& ray, Interval ray_t, IntersectionRecord& record, size_t i) const {
    // Vertices
    Vector3 vertex_a = vertices[polygons[i]];
    Vector3 vertex_b = vertices[polygons[i + 1]];
    Vector3 vertex_c = vertices[polygons[i + 2]];

    // Edges
    Vector3 ab = vertex_b - vertex_a;
    Vector3 ac = vertex_c - vertex_a;

    // Normal
    Vector3 normal = cross(ab, ac);

    // Reject intersection test on backfaces
    if (dot(ray.get_direction(), normal) >= 0) {
        return false;
    }

    normal = normal / normal.magnitude();

    // Line plane intersection
    double numerator = dot((vertex_a - ray.get_origin()), normal);
    double denominator = dot(ray.get_direction(), normal);
    if (fabs(denominator) < 1e-8) {
        return false;
    }

    double t = numerator / denominator;
    if (!ray_t.surrounds(t)) {
        return false;
    }

    Vector3 intersection = ray.get_origin() + (t * ray.get_direction());
    // AB edge test
    Vector3 ab_edge_test = cross(ab, intersection - vertex_a);
    if (dot(ab_edge_test, normal) < 0) {
        return false;
    }
    
    // BC edge test
    Vector3 bc = vertex_c - vertex_b;
    Vector3 bc_edge_test = cross(bc, intersection - vertex_b);
    if (dot(bc_edge_test, normal) < 0) {
        return false;
    }
    
    // CA edge test
    Vector3 ca = vertex_a - vertex_c;
    Vector3 ca_edge_test = cross(ca, intersection - vertex_c);
    if (dot(ca_edge_test, normal) < 0) {
        return false;
    }
    record.set_t(t);
    record.set_point(intersection);
    record.set_normal(ray, normal);

    return true;
}

bool Mesh::get_intersection(const Ray& ray, Interval ray_t, IntersectionRecord& record) const {
    IntersectionRecord temp_record;
    bool hit_anything = false;
    double closest_so_far = ray_t.get_max();

    for (size_t i = 0; i < polygons.size(); i += 3) {
        if (intersect_triangle(ray, Interval(ray_t.get_min(), closest_so_far), temp_record, i)) {
            hit_anything = true;
            closest_so_far = temp_record.get_t();
            record = temp_record;
        }
    }

    return hit_anything;
}
