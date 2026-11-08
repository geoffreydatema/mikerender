#include <iostream>
#include "Camera.h"
#include "RenderSet.h"
#include "Mesh.h"

#define WIDTH 256
#define HEIGHT 256
#define SAMPLES 10
#define MAX_DEPTH 50

using namespace std;

int main() {
    Camera camera(WIDTH, HEIGHT, SAMPLES, MAX_DEPTH);

    LightSet light_set;

    RenderSet render_set;
    
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

    camera.render(render_set);

    return 0;
}
