#pragma once

#include <memory>
#include <vector>
#include "LightObject.h"

using namespace std;

class LightSet {
    private:
        vector<shared_ptr<LightObject>> light_objects;

    public:
        void add(shared_ptr<LightObject> object);
        const vector<shared_ptr<LightObject>>& get_lights() const;
};
