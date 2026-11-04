#pragma once

#include "Ray.h"
#include "Interval.h"
#include "IntersectionRecord.h"

class RenderObject {
    public:
        virtual ~RenderObject() = default;
        virtual bool get_intersection(const Ray& r, Interval ray_t, IntersectionRecord& rec) const = 0;
        virtual bool intersect_triangle(const Ray& r, Interval ray_t, IntersectionRecord& rec, size_t i) const = 0;
};
