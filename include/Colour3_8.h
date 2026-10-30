#pragma once

class Colour3_8 {
    private:
        double components[3];

    public:
        Colour3_8();
        Colour3_8(double x, double y, double z);
        double r() const;
        double g() const;
        double b() const;
        void print();
        Colour3_8& operator+=(const Colour3_8& right_operand);
};

Colour3_8 operator*(double left_operand, const Colour3_8& right_operand);
