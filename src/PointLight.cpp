#include "PointLight.h"

PointLight::PointLight(Vector3 p, float i, Colour3_32 c) {
    position = p;
    set_intensity(i);
    set_colour(c);
}

Vector3 PointLight::get_position() const {
    return position;
}

void PointLight::set_position(Vector3 p) {
    position = p;
}
