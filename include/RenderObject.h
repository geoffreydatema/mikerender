#pragma once

#include "Ray.h"
#include "Interval.h"
#include "IntersectionRecord.h"

class RenderObject {
    public:
        virtual ~RenderObject() = default;
        virtual bool get_intersection(const Ray& r, Interval ray_t, IntersectionRecord& rec) const = 0;
};
