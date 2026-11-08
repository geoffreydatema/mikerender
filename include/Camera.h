#pragma once

#include <iostream>
#include <string>
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

        void initialize();
        Vector3 sample_square() const;
        Ray get_ray(int i, int j) const;
        Colour3_32 trace_light_ray(const Ray& ray, const LightSet& light_set);
        Colour3_32 trace_ray(const Ray& ray, int depth, const RenderSet& render_set, const LightSet& light_set);

    public:
        Camera(int w, int h, int s, int md);
        void debug();
        void write_colour(ostream& file, const Colour3_32& pixel_colour);
        void render(const RenderSet& render_set, const LightSet& light_set, const string& filename = "renders/render.uaf");
};
