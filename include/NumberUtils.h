#pragma once

#include <cstdint>

namespace Constants {
    constexpr float DEFAULT_CAMERA_POSITION[3] = {0, -5, 2};
    constexpr float DEFAULT_ORIENTATION_TARGET[3] = {0, 0, 0};
    constexpr float DEFAULT_FOCAL_LENGTH = 18.0;
    constexpr float DEFAULT_SENSOR_SIZE = 24.0;
    constexpr uint32_t DEFAULT_IMAGE_WIDTH = 256;
    constexpr uint32_t DEFAULT_IMAGE_HEIGHT = 256;
    constexpr uint32_t DEFAULT_SAMPLES = 3;
    constexpr uint32_t DEFAULT_RAY_DEPTH = 10;
    constexpr float DEFAULT_BACKGROUND_COLOUR[3] = {0.5, 0.5, 0.5};

    constexpr float MILLIMETER = 0.001;
    constexpr float CENTIMETER = 0.01;
    constexpr float METER = 1.0;
    constexpr float EPSILON = 0.1 * MILLIMETER;
}

double random_double();
double random_double(double min, double max);
