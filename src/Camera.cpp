#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>
#include "Camera.h"
#include "NumberUtils.h"
#include "Ray.h"
#include "IntersectionRecord.h"
#include "NumberUtils.h"
#include "Vector3.h"
#include "PointLight.h"

using namespace std;

void Camera::initialize() {
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

Colour3_32 Camera::trace_ray(const Ray& ray, int depth, const RenderSet& render_set, const LightSet& light_set) {
    if (depth <= 0) {
        return Colour3_32(0, 0, 0);
    }

    IntersectionRecord record;

    // If the ray hit geometry
    if (render_set.get_intersection(ray, Interval(Constants::EPSILON, numeric_limits<double>::infinity()), record)) {

        Colour3_32 direct_light(0, 0, 0);

        for (const shared_ptr<LightObject>& light_object : light_set.get_lights()) {
            auto light = static_pointer_cast<PointLight>(light_object);
    
            Vector3 vector_to_light = light->get_position() - record.get_point();
            double distance_to_light = vector_to_light.magnitude();
            Vector3 direction_to_light = vector_to_light / distance_to_light;
            
            Ray shadow_ray(record.get_point(), direction_to_light);
            IntersectionRecord shadow_record;
            Interval shadow_interval(Constants::EPSILON, distance_to_light - Constants::EPSILON);

            if (!render_set.get_intersection(shadow_ray, shadow_interval, shadow_record)) {
                // No interesection with geometry, the point ray is not in shadow
                double cos_theta = max(0.0, dot(record.get_normal(), direction_to_light));
                double attenuation = 1.0 / (distance_to_light * distance_to_light);

                direct_light = direct_light + (light->get_colour() * (light->get_intensity() * cos_theta * attenuation));
            }
        }

        // Indirect lighting (recursive bounce)
        Vector3 direction = record.get_normal() + Vector3::random_unit();
        Colour3_32 indirect_light = trace_ray(Ray(record.get_point(), direction), depth - 1, render_set, light_set);

        // Hard coded albedo for now
        float albedo = 0.5;

        return albedo * (direct_light + indirect_light);
    }

    // If the ray did not hit any geometry and went straight to the background
    Colour3_32 background_colour(Constants::DEFAULT_BACKGROUND_COLOUR[0], Constants::DEFAULT_BACKGROUND_COLOUR[1], Constants::DEFAULT_BACKGROUND_COLOUR[2]);
    return background_colour;
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

void Camera::write_colour(ostream& file, const Colour3_32& pixel_colour) {
    Colour3_8 gamma_corrected_bytes = pixel_colour.to_gamma_corrected_colour3_8();

    file << gamma_corrected_bytes << '\n';
}

void Camera::render(const RenderSet& render_set, const LightSet& light_set, const string& filename) {
    initialize();

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open output file: " << filename << "\n";
        return;
    }

    file << "::{\n";
    file << "!!uafheader { version 0.1 };\n";
    file << "!!uafimage { width " << image_width << " height " << image_height << " }\n";

    for (int j = 0; j < image_height; j++) {
        cout << "\rScanning line " << (image_height - j) << "\n";
        for (int i = 0; i < image_width; i++) {
            Colour3_32 pixel_colour(0, 0, 0);
            for (int sample = 0; sample < samples; sample++) {
                Ray ray = get_ray(i, j);
                pixel_colour += trace_ray(ray, max_depth, render_set, light_set);
            }
            write_colour(file, pixel_samples_scale * pixel_colour);
        }
    }

    file << ";\n";
    file << "}";
    file.close();
    cout << "Render complete: " << filename << "\n";
}
