#include <iostream>

#include "Colour3_8.h"

using namespace std;

Colour3_8::Colour3_8() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Colour3_8::Colour3_8(double x, double y, double z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

double Colour3_8::r() const {
    return components[0];
}

double Colour3_8::g() const {
    return components[1];
}

double Colour3_8::b() const {
    return components[2];
}

void Colour3_8::print() {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}

Colour3_8& Colour3_8::operator+=(const Colour3_8& right_operand) {
    components[0] += right_operand.r();
    components[1] += right_operand.g();
    components[2] += right_operand.b();
    return *this;
}

Colour3_8 operator*(double left_operand, const Colour3_8& right_operand) {
    return Colour3_8(left_operand * right_operand.r(), left_operand * right_operand.g(), left_operand * right_operand.b());
}
