#include <iostream>
#include "RenderSet.h"

void RenderSet::add(shared_ptr<RenderObject> object) {
    render_objects.push_back(object);
}

bool RenderSet::hit(const Ray& ray, Interval ray_t, IntersectionRecord& record) const {
    IntersectionRecord temp_record;
    bool hit_anything = false;
    double closest_so_far = ray_t.get_max();

    for (const shared_ptr<RenderObject>& render_object : render_objects) {
        if (render_object->hit(ray, Interval(ray_t.get_min(), closest_so_far), temp_record)) {
            hit_anything = true;
            closest_so_far = temp_record.get_t();
            record = temp_record;
        }
    }
    
    return hit_anything;
}
