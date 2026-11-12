#include <iostream>
#include <fstream>
#include <limits>
#include "CPTCore.h"
#include "NumberUtils.h"
#include "PointLight.h"

using namespace std;

Colour3_32 CPTCore::trace_ray(const Ray& ray, int depth, const RenderSet& render_set, const LightSet& light_set) {
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

void CPTCore::write_colour(ostream& file, const Colour3_32& pixel_colour) {
    Colour3_8 gamma_corrected_bytes = pixel_colour.to_gamma_corrected_colour3_8();

    file << gamma_corrected_bytes << '\n';
}

void CPTCore::render(const Camera& camera, const RenderSet& render_set, const LightSet& light_set, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open output file: " << filename << "\n";
        return;
    }

    file << "::{\n";
    file << "!!uafheader { version 0.1 };\n";
    file << "!!uafimage { width " << camera.get_image_width() << " height " << camera.get_image_height() << " }\n";

    for (int j = 0; j < camera.get_image_height(); j++) {
        cout << "\rScanning line " << (camera.get_image_height() - j) << "\n";
        for (int i = 0; i < camera.get_image_width(); i++) {
            Colour3_32 pixel_colour(0, 0, 0);
            for (int sample = 0; sample < camera.get_samples(); sample++) {
                Ray ray = camera.get_ray(i, j);
                pixel_colour += trace_ray(ray, camera.get_max_depth(), render_set, light_set);
                if (i == 0 && j == 0 && sample == 0) {
                    std::cout << "Ray origin: "; ray.get_origin().print();
                    std::cout << "Ray dir: "; ray.get_direction().print();
                    std::cout << "Scale: " << camera.get_pixel_samples_scale() << "\n";
                }
            }
            write_colour(file, camera.get_pixel_samples_scale() * pixel_colour);
        }
    }

    file << ";\n";
    file << "}";
    file.close();
    cout << "Render complete: " << filename << "\n";
}
