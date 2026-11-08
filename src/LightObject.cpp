#include "LightObject.h"
#include "Colour3_32.h"

float LightObject::get_intensity() const {
    return intensity;
}

void LightObject::set_intensity(double value) {
    intensity = value;
}

Colour3_32 LightObject::get_colour() const {
    return colour;
}

void LightObject::set_colour(Colour3_32 c) {
    colour = c;
}
