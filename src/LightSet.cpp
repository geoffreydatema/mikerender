#include "LightSet.h"

void LightSet::add(shared_ptr<LightObject> object) {
    light_objects.push_back(object);
}

const vector<shared_ptr<LightObject>>& LightSet::get_lights() const {
    return light_objects;
}
