#pragma once

#include "Colour3_8.h"

class Colour3_32 {
    private:
        float components[3];

    public:
        Colour3_32();
        Colour3_32(float r, float g, float b);
        float r() const;
        float g() const;
        float b() const;
        void print() const;
        Colour3_32& operator+=(const Colour3_32& right_operand);
        Colour3_32 to_gamma_corrected_colour3_32() const;
        Colour3_8 to_gamma_corrected_colour3_8() const;
        Colour3_8 to_colour3_8() const;
};

Colour3_32 operator*(float left_operand, const Colour3_32& right_operand);
