#pragma once

class Vector3 {
    private:
        double components[3];

    public:
        Vector3();
        Vector3(double x, double y, double z);
        double x() const;
        double y() const;
        double z() const;
        void print() const;
        Vector3 operator-() const;
        double magnitude() const;
        double length_squared() const;
        static Vector3 random(double min, double max);
        static Vector3 random_unit();
};

Vector3 operator+(const Vector3& left_operand, const Vector3& right_operand);
Vector3 operator-(const Vector3& left_operand, const Vector3& right_operand);
Vector3 operator*(double left_operand, const Vector3& right_operand);
Vector3 operator*(const Vector3& left_operand, double right_operand);
Vector3 operator/(const Vector3& left_operand, double right_operand);
double dot(const Vector3& left_operand, const Vector3& right_operand);
