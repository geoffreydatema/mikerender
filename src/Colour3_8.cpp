#include <iostream>
#include <cmath>
#include "Colour3_8.h"
#include "Interval.h"

using namespace std;

Colour3_8::Colour3_8() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Colour3_8::Colour3_8(uint8_t r, uint8_t g, uint8_t b) {
    components[0] = r;
    components[1] = g;
    components[2] = b;
}

Colour3_8 Colour3_8::from_colour3_32(float r, float g, float b) {
    static const Interval intensity(0, 0.999);
    
    return Colour3_8(
        static_cast<uint8_t>(256.0f * intensity.clamp(r)),
        static_cast<uint8_t>(256.0f * intensity.clamp(g)),
        static_cast<uint8_t>(256.0f * intensity.clamp(b))
    );
}

uint8_t Colour3_8::r() const {
    return components[0];
}

uint8_t Colour3_8::g() const {
    return components[1];
}

uint8_t Colour3_8::b() const {
    return components[2];
}

void Colour3_8::print() const {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}

Colour3_8& Colour3_8::operator+=(const Colour3_8& right_operand) {
    components[0] += right_operand.r();
    components[1] += right_operand.g();
    components[2] += right_operand.b();
    return *this;
}

Colour3_8 operator*(uint8_t left_operand, const Colour3_8& right_operand) {
    return Colour3_8(left_operand * right_operand.r(), left_operand * right_operand.g(), left_operand * right_operand.b());
}

ostream& operator<<(ostream& stream, const Colour3_8& colour) {
    stream << static_cast<int>(colour.r()) << ' ' << static_cast<int>(colour.g()) << ' ' << static_cast<int>(colour.b());
    return stream;
}
