#pragma once

class Interval {
    private:
        double min;
        double max;

    public:
        Interval();
        Interval(double min, double max);
        double size() const;
        bool contains(double value) const;
        bool surrounds(double value) const;
        double clamp(double value) const;
};
