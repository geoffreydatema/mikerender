#include <limits>

#include "Interval.h"

using namespace std;

Interval::Interval() {
    double infinity = numeric_limits<double>::infinity();
    min = +infinity;
    max = -infinity;
}

Interval::Interval(double min_value, double max_value) {
    min = min_value;
    max = max_value;
}

double Interval::size() const {
    return max - min;
}

bool Interval::contains(double value) const {
    return min <= value && value <= max;
}

bool Interval::surrounds(double value) const {
    return min < value && value < max;
}

double Interval::clamp(double value) const {
    if (value < min) {
        return min;
    }

    if (value > max) {
        return max;
    }

    return value;
}
