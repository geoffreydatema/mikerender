#pragma once

#include "Vector3.h"
#include "Ray.h"

class IntersectionRecord {
    private:
        Vector3 point;
        Vector3 normal;
        double t;
        bool front_face;

    public:
        void set_face_normal(const Ray& ray, const Vector3& outward_normal);
        Vector3 get_point() const;
        Vector3 get_normal() const;
};
