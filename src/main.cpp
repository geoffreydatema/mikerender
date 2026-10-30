#include <iostream>
#include "Camera.h"
#include "RenderSet.h"
#include "Triangle.h"

#define WIDTH 256
#define HEIGHT 128
#define SAMPLES 1
#define MAX_DEPTH 50

using namespace std;

int main() {
    Camera camera(WIDTH, HEIGHT, SAMPLES, MAX_DEPTH);

    RenderSet render_set;
    render_set.add(make_shared<Triangle>(Vector3(1, 1, -1), Vector3(-1, 1, -1), Vector3(-1, -1, -1)));

    camera.render(render_set);

    return 0;
}
