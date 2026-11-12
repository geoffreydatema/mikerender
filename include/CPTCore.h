#pragma once

#include <iostream>
#include <string>
#include "Camera.h"

class CPTCore {
    private:
        

    public:
        Colour3_32 trace_ray(const Ray& ray, int depth, const RenderSet& render_set, const LightSet& light_set);
        void write_colour(ostream& file, const Colour3_32& pixel_colour);    
        void render(const Camera& camera, const RenderSet& render_set, const LightSet& light_set, const string& filename = "renders/render.uaf");
};