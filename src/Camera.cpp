#include "Camera.h"
#include <iostream>
#include <fstream>

using namespace std;

void Camera::initialize() {
    pixel_samples_scale = 1.0 / samples;

    center = Vector3(0, 0, 0);

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);

    Vector3 viewport_u = Vector3(viewport_width, 0, 0);
    Vector3 viewport_v = Vector3(0, -viewport_height, 0);

    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    Vector3 viewport_upper_left = center - Vector3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    first_pixel = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

Ray Camera::get_ray(int i, int j) {
    Ray ray;
    return ray;
}

Vector3 Camera::sample_square() {
    Vector3 v;
    return v;
}

Colour3_8 Camera::ray_colour(const Ray& ray, int depth, const RenderSet& render_set) {
    Colour3_8 c;
    return c;
}

Camera::Camera(int w, int h, int s, int md) {
    image_width = w;
    image_height = h;
    samples = s;
    max_depth = md;
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

void Camera::render(const RenderSet& render_set, const string& filename) {
    initialize();

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open output file: " << filename << "\n";
        return;
    }

    file << "hi mike";

    file.close();
    clog << "Render complete: " << filename << "\n";
}
