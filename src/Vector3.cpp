#include "Vector3.h"
#include <iostream>

using namespace std;

Vector3::Vector3() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Vector3::Vector3(double x, double y, double z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

double Vector3::x() const {
    return components[0];
}

double Vector3::y() const {
    return components[1];
}

double Vector3::z() const {
    return components[2];
}

void Vector3::print() const {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}

Vector3 operator+(const Vector3& left_operand, const Vector3& right_operand) {
    return Vector3(left_operand.x() + right_operand.x(), left_operand.y() + right_operand.y(), left_operand.z() + right_operand.z());
}

Vector3 operator-(const Vector3& left_operand, const Vector3& right_operand) {
    return Vector3(left_operand.x() - right_operand.x(), left_operand.y() - right_operand.y(), left_operand.z() - right_operand.z());
}

Vector3 operator*(double left_operand, const Vector3& right_operand) {
    return Vector3(left_operand * right_operand.x(), left_operand * right_operand.y(), left_operand * right_operand.z());
}

Vector3 operator*(const Vector3& left_operand, double right_operand) {
    return right_operand * left_operand;
}

Vector3 operator/(const Vector3& left_operand, double right_operand) {
    return (1 / right_operand) * left_operand;
}
