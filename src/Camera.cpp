#include "Camera.h"
#include <iostream>

using namespace std;

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
void Camera::render(const RenderSet& render_set) {
    return;
}