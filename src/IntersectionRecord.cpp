#include "IntersectionRecord.h"
#include "Vector3.h"

Vector3 IntersectionRecord::get_point() const {
    return point;
}

Vector3 IntersectionRecord::get_normal() const {
    return normal;
}

void IntersectionRecord::set_normal(const Ray& ray, const Vector3& outward_normal) {
    front_face = dot(ray.get_direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}

void IntersectionRecord::set_point(const Vector3& intersection) {
    point = intersection;
}

double IntersectionRecord::get_t() const {
    return t;
}

void IntersectionRecord::set_t(double new_t) {
    t = new_t;
}
