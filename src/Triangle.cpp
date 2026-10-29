#include "Triangle.h"

Triangle::Triangle(Vector3 a, Vector3 b, Vector3 c) {
    vertex_a = a;
    vertex_b = b;
    vertex_c = c;

    print();
}

void Triangle::print() {
    vertex_a.print();
    vertex_b.print();
    vertex_c.print();
}

bool Triangle::hit(const Ray& r, Interval ray_t, IntersectionRecord& rec) const {
    return false;
}
