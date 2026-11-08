#include <iostream>
#include <cmath>
#include "Colour3_32.h"
#include "Colour3_8.h"

using namespace std;

Colour3_32::Colour3_32() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Colour3_32::Colour3_32(float r, float g, float b) {
    components[0] = r;
    components[1] = g;
    components[2] = b;
}

float Colour3_32::r() const {
    return components[0];
}

float Colour3_32::g() const {
    return components[1];
}

float Colour3_32::b() const {
    return components[2];
}

void Colour3_32::print() const {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}

Colour3_32& Colour3_32::operator+=(const Colour3_32& right_operand) {
    components[0] += right_operand.r();
    components[1] += right_operand.g();
    components[2] += right_operand.b();
    return *this;
}

Colour3_32 Colour3_32::to_gamma_corrected_colour3_32() const {
    float r = components[0] > 0.0 ? sqrt(components[0]) : 0.0;
    float g = components[1] > 0.0 ? sqrt(components[1]) : 0.0;
    float b = components[2] > 0.0 ? sqrt(components[2]) : 0.0;

    return Colour3_32(r, g, b);
}

Colour3_8 Colour3_32::to_gamma_corrected_colour3_8() const {
    Colour3_32 gamma_corrected_colour = to_gamma_corrected_colour3_32();
    
    return Colour3_8::from_colour3_32(gamma_corrected_colour.r(), gamma_corrected_colour.g(), gamma_corrected_colour.b());
}

Colour3_8 Colour3_32::to_colour3_8() const {
    return Colour3_8::from_colour3_32(components[0], components[1], components[2]);
}

Colour3_32 operator+(const Colour3_32& left_operand, const Colour3_32& right_operand) {
    return Colour3_32(left_operand.r() + right_operand.r(), left_operand.g() + right_operand.g(), left_operand.b() + right_operand.b());
}

Colour3_32 operator*(float left_operand, const Colour3_32& right_operand) {
    return Colour3_32(left_operand * right_operand.r(), left_operand * right_operand.g(), left_operand * right_operand.b());
}

Colour3_32 operator*(const Colour3_32& left_operand, float right_operand) {
    return Colour3_32(left_operand.r() * right_operand, left_operand.g() * right_operand, left_operand.b() * right_operand);
}
