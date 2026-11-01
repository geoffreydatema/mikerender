#include <iostream>
#include "Camera.h"
#include "RenderSet.h"
#include "Triangle.h"

#define WIDTH 400
#define HEIGHT 200
#define SAMPLES 1
#define MAX_DEPTH 50

using namespace std;

int main() {
    Camera camera(WIDTH, HEIGHT, SAMPLES, MAX_DEPTH);

    RenderSet render_set;
    // i thought this was counter clockwise
    render_set.add(make_shared<Triangle>(Vector3(1, 2, -1), Vector3(-1, 2, -1), Vector3(-1, 0, -1)));

    //i thought this was clockwise
    render_set.add(make_shared<Triangle>(Vector3(-1, -2, -1), Vector3(-1, 0, -1), Vector3(1, 0, -1)));

    camera.render(render_set);

    return 0;
}
