#pragma once

#include "Vector3.h"

class Ray {
    private:
        Vector3 origin;
        Vector3 direction;

    public:
        Ray();
        Ray(const Vector3& o, const Vector3& d);
        const Vector3& get_origin() const;
        const Vector3 get_direction() const;
        Vector3 at(double t) const;
};