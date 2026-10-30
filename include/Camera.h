#pragma once

#include <string>
#include "Vector3.h"
#include "Ray.h"
#include "Colour3_8.h"
#include "RenderSet.h"

using namespace std;

class Camera {
    private:
        int image_width;
        int image_height;
        int samples;
        int max_depth;
        double pixel_samples_scale;
        Vector3 center;
        Vector3 first_pixel;
        Vector3 pixel_delta_u;
        Vector3 pixel_delta_v;

        void initialize();
        Ray get_ray(int i, int j);
        Vector3 sample_square();
        Colour3_8 ray_colour(const Ray& ray, int depth, const RenderSet& render_set);

    public:
        Camera(int w, int h, int s, int md);
        void debug();
        void render(const RenderSet& render_set, const string& filename = "renders/render.ppm");
};
