#include "IntersectionRecord.h"
#include "Vector3.h"

void IntersectionRecord::set_face_normal(const Ray& ray, const Vector3& outward_normal) {
    front_face = dot(ray.get_direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
}

Vector3 IntersectionRecord::get_point() const {
    return point;
}

Vector3 IntersectionRecord::get_normal() const {
    return normal;
}
