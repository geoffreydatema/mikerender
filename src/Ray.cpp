#include "Ray.h"

Ray::Ray() {}

Ray::Ray(const Vector3& o, const Vector3& d) {
    origin = o;
    direction = d;
}

const Vector3& Ray::get_origin() const {
    return origin;
}

const Vector3 Ray::get_direction() const {
    return direction;
}

Vector3 Ray::at(double t) const {
    return origin + t * direction;
}
