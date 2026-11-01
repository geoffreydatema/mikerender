#pragma once

#include <iostream>
#include <cstdint>

using namespace std;

class Colour3_8 {
    private:
        uint8_t components[3];

    public:
        Colour3_8();
        Colour3_8(uint8_t r, uint8_t g, uint8_t b);
        static Colour3_8 from_colour3_32(float r, float g, float b);
        uint8_t r() const;
        uint8_t g() const;
        uint8_t b() const;
        void print() const ;
        Colour3_8& operator+=(const Colour3_8& right_operand);
        friend ostream& operator<<(ostream& stream, const Colour3_8& colour);
};

Colour3_8 operator*(uint8_t left_operand, const Colour3_8& right_operand);
