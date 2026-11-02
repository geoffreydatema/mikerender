#include <iostream>
#include "Camera.h"
#include "RenderSet.h"
#include "Triangle.h"

#define WIDTH 256
#define HEIGHT 256
#define SAMPLES 1
#define MAX_DEPTH 50

using namespace std;

int main() {
    Camera camera(WIDTH, HEIGHT, SAMPLES, MAX_DEPTH);

    RenderSet render_set;

    // Cube
    render_set.add(make_shared<Triangle>(Vector3(1.41421, 4.42642, 0.819152), Vector3(-1.41421, 4.42642, 0.819152), Vector3(0, 3.26797, 0.007992)));
    render_set.add(make_shared<Triangle>(Vector3(1.41421, 4.42642, 0.819152), Vector3(0, 5.58488, 1.63031), Vector3(-1.41421, 4.42642, 0.819152)));
    render_set.add(make_shared<Triangle>(Vector3(1.41421, 4.42642, 0.819152), Vector3(0, 4.41512, -1.63031), Vector3(1.41421, 5.57358, -0.819152)));
    render_set.add(make_shared<Triangle>(Vector3(1.41421, 4.42642, 0.819152), Vector3(0, 3.26797, 0.007992), Vector3(0, 4.41512, -1.63031)));
    render_set.add(make_shared<Triangle>(Vector3(0, 3.26797, 0.007992), Vector3(-1.41421, 4.42642, 0.819152), Vector3(-1.41421, 5.57358, -0.819152)));
    render_set.add(make_shared<Triangle>(Vector3(0, 3.26797, 0.007992), Vector3(-1.41421, 5.57358, -0.819152), Vector3(0, 4.41512, -1.63031)));
    render_set.add(make_shared<Triangle>(Vector3(-1.41421, 4.42642, 0.819152), Vector3(0, 6.73203, -0.819152), Vector3(-1.41421, 5.57358, -0.819152)));
    render_set.add(make_shared<Triangle>(Vector3(-1.41421, 4.42642, 0.819152), Vector3(0, 5.58488, 1.63031), Vector3(0, 6.73203, -0.007992)));
    render_set.add(make_shared<Triangle>(Vector3(0, 5.58488, 1.63031), Vector3(1.41421, 5.57358, -0.819152), Vector3(0, 6.73203, -0.007992)));
    render_set.add(make_shared<Triangle>(Vector3(0, 5.58488, 1.63031), Vector3(1.41421, 4.42642, 0.819152), Vector3(1.41421, 5.57358, -0.819152)));
    render_set.add(make_shared<Triangle>(Vector3(0, 6.73203, -0.007992), Vector3(1.41421, 5.57358, -0.819152), Vector3(0, 4.41512, -1.63031)));
    render_set.add(make_shared<Triangle>(Vector3(0, 6.73203, -0.007992), Vector3(0, 4.41512, -1.63031), Vector3(-1.41421, 5.57358, -0.819152)));

    // Plane
    render_set.add(make_shared<Triangle>(Vector3(-2.4, 3, 2), Vector3(-2.4, 3, -2), Vector3(-1.4, 7, -2)));
    render_set.add(make_shared<Triangle>(Vector3(-1.4, 7, 2), Vector3(-2.4, 3, 2), Vector3(-1.4, 7, -2)));

    camera.render(render_set);

    return 0;
}
