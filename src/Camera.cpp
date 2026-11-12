#include <iostream>
#include <fstream>
#include <cmath>
#include "Camera.h"
#include "NumberUtils.h"
#include "Ray.h"
#include "NumberUtils.h"
#include "Vector3.h"
#include "PointLight.h"

using namespace std;

Vector3 Camera::sample_square() const {
    return Vector3(random_double() - 0.5, random_double() - 0.5, 0);
}

Ray Camera::get_ray(int i, int j) const {
    Vector3 offset = sample_square();
    Vector3 pixel_sample = first_pixel + ((i + offset.x()) * pixel_delta_u) + ((j + offset.y()) * pixel_delta_v);
    Vector3 ray_origin = position;
    Vector3 ray_direction = pixel_sample - ray_origin;

    return Ray(ray_origin, ray_direction);
}

Colour3_32 Camera::trace_light_ray(const Ray& ray, const LightSet& light_set) {
    return Colour3_32(0.5, 0.5, 0.5);
}

Camera::Camera(int width, int height, int s, int md) {
    image_width = width;
    image_height = height;
    samples = s;
    max_depth = md;

    position = Vector3(Constants::DEFAULT_CAMERA_POSITION[0], Constants::DEFAULT_CAMERA_POSITION[1], Constants::DEFAULT_CAMERA_POSITION[2]);
    orientation_target = Vector3(0, 1, 0);
    up = Vector3(0, 0, 1);
    
    pixel_samples_scale = 1.0 / samples;

    double focal_length = Constants::DEFAULT_FOCAL_LENGTH * Constants::MILLIMETER;
    double sensor_height = Constants::DEFAULT_SENSOR_SIZE * Constants::MILLIMETER;

    double aspect_ratio = double(image_width) / double(image_height);
    double sensor_width = sensor_height * aspect_ratio;

    double viewport_height = sensor_height;
    double viewport_width = sensor_width;

    Vector3 w = (orientation_target - position).to_unit_vector();
    Vector3 u = cross(w, up).to_unit_vector();
    Vector3 v = cross(u, w);

    Vector3 viewport_u = viewport_width * u;
    Vector3 viewport_v = -viewport_height * v;

    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    Vector3 viewport_center = position + (focal_length * w);
    Vector3 viewport_upper_left = viewport_center - (viewport_u / 2.0) - (viewport_v / 2.0);

    first_pixel = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void Camera::debug() {
    cout << "--------------------------------\n";
    cout << "Camera Info\n";
    cout << "--------------------------------\n";
    cout << "image_width:\t" << image_width << "\n";
    cout << "image_height:\t" << image_height << "\n";
    cout << "samples:\t" << samples << "\n";
    cout << "max_depth:\t" << max_depth << "\n";
    cout << "--------------------------------\n\n";
}

int Camera::get_image_width() const {
    return image_width;
}

int Camera::get_image_height() const {
    return image_height;
}

int Camera::get_samples() const {
    return samples;
}

int Camera::get_max_depth() const {
    return max_depth;
}

double Camera::get_pixel_samples_scale() const {
    return pixel_samples_scale;
}
