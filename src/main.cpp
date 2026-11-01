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
    render_set.add(make_shared<Triangle>(Vector3(1, 4, 2), Vector3(-1, 4, 2), Vector3(-1, 4, 0)));
    render_set.add(make_shared<Triangle>(Vector3(-1, 4, -2), Vector3(-1, 4, 0), Vector3(1, 4, 0)));

    camera.render(render_set);

    return 0;
}
