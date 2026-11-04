#pragma once

#include "Vector3.h"

namespace Constants {
    constexpr double DEFAULT_CAMERA_POSITION[3] = {4, -5, 2};
    constexpr double DEFAULT_ORIENTATION_TARGET[3] = {0, 0, 0};
    constexpr double DEFAULT_FOCAL_LENGTH = 18.0;
    constexpr double DEFAULT_SENSOR_SIZE = 24.0;

    constexpr double MILLIMETER = 0.001;
    constexpr double CENTIMETER = 0.01;
    constexpr double METER = 1.0;
    constexpr double EPSILON = 0.1 * MILLIMETER;
}

double random_double();
double random_double(double min, double max);
