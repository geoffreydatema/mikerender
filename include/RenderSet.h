#pragma once

#include <memory>
#include <vector>
#include "RenderObject.h"
#include "Ray.h"
#include "Interval.h"
#include "IntersectionRecord.h"

class RenderSet {
    private:
        std::vector<std::shared_ptr<RenderObject>> render_objects;

    public:
        void add(std::shared_ptr<RenderObject> object);
        bool hit(const Ray& r, Interval ray_t, IntersectionRecord& rec) const;
};
