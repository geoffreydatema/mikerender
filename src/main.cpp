#include "Camera.h"
#include "LightSet.h"
#include "RenderSet.h"
#include "Mesh.h"
#include "PointLight.h"
#include "NumberUtils.h"
#include "CPTCore.h"

using namespace std;

int main() {
    
    Camera camera(Constants::DEFAULT_IMAGE_WIDTH, Constants::DEFAULT_IMAGE_HEIGHT, Constants::DEFAULT_SAMPLES, Constants::DEFAULT_RAY_DEPTH);
    RenderSet render_set;
    LightSet light_set;
    
    // Plane
    vector<Vector3> plane_vertices = {
        {-3, -3, -1},
        {3, -3, -1},
        {-3, 3, -1},
        {3, 3, -1}
    };

    vector<uint32_t> plane_polygons = {
        1, 2, 0,
        1, 3, 2
    };

    // Cube
    vector<Vector3> cube_vertices = {
        {-1, -1, -1},
        {-1, -1, 1},
        {-1, 1, -1},
        {-1, 1, 1},
        {1, -1, -1},
        {1, -1, 1},
        {1, 1, -1},
        {1, 1, 1}
    };

    vector<uint32_t> cube_polygons = {
        0, 1, 2,
        2, 3, 6,
        6, 7, 4,
        5, 0, 4,
        0, 2, 6,
        5, 7, 3,
        1, 3, 2,
        3, 7, 6,
        7, 5, 4,
        5, 1, 0,
        6, 4, 0,
        1, 5, 3
    };

    render_set.add(make_shared<Mesh>(plane_vertices, plane_polygons));
    render_set.add(make_shared<Mesh>(cube_vertices, cube_polygons));

    light_set.add(make_shared<PointLight>(Vector3(1.5, 0, 1.5), 1.0, Colour3_32(1, 1, 1)));

    CPTCore cpt_core;
    cpt_core.render(camera, render_set, light_set);

    return 0;
}
