#pragma once

#include "Colour3_32.h"

class LightObject {
    private:
        float intensity;
        Colour3_32 colour;

    public:
        virtual ~LightObject() = default;
        float get_intensity() const;
        void set_intensity(double value);
        Colour3_32 get_colour() const;
        void set_colour(Colour3_32 c);
};
