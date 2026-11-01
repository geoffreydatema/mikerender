#include <iostream>
#include <cmath>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(Vector3 a, Vector3 b, Vector3 c) {
    vertex_a = a;
    vertex_b = b;
    vertex_c = c;
}

void Triangle::print() {
    vertex_a.print();
    vertex_b.print();
    vertex_c.print();
}

bool Triangle::hit(const Ray& ray, Interval ray_t, IntersectionRecord& record) const {

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
