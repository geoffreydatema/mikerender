#pragma once

#include <iostream>
#include "Vector3.h"
#include "Ray.h"
#include "Colour3_32.h"
#include "RenderSet.h"
#include "LightSet.h"

using namespace std;

class Camera {
    private:
        int image_width;
        int image_height;
        int samples;
        int max_depth;
        double pixel_samples_scale;
        Vector3 position;
        Vector3 orientation_target;
        Vector3 up;
        Vector3 first_pixel;
        Vector3 pixel_delta_u;
        Vector3 pixel_delta_v;
        Vector3 sample_square() const;
        Colour3_32 trace_light_ray(const Ray& ray, const LightSet& light_set);
        
    public:
        Camera(int width, int height, int s, int md);
        void debug();
        int get_image_width() const;
        int get_image_height() const;
        int get_samples() const;
        int get_max_depth() const;
        double get_pixel_samples_scale() const;
        Ray get_ray(int i, int j) const;
};
