#include "RenderSet.h"
        
void RenderSet::add(std::shared_ptr<RenderObject> object) {
    render_objects.push_back(object);
}

bool RenderSet::hit(const Ray& r, Interval ray_t, IntersectionRecord& rec) const {
    return false;
}
