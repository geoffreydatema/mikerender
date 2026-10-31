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
        Vector3 get_point() const;
        Vector3 get_normal() const;
        void set_point(const Vector3& intersection);
        void set_normal(const Ray& ray, const Vector3& outward_normal);
        double get_t() const;
        void set_t(double new_t);
};
