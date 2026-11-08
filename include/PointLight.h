#pragma once

#include "LightObject.h"
#include "Vector3.h"
#include "Colour3_32.h"

using namespace std;

class PointLight : public LightObject {
    private:
        Vector3 position;

    public:
        PointLight(Vector3 p, float i, Colour3_32 c);
        Vector3 get_position() const;
        void set_position(Vector3 p);
};
