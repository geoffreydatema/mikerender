#include <iostream>
#include "RenderSet.h"
#include "Triangle.h"

using namespace std;

int main() {
    RenderSet render_set;

    render_set.add(make_shared<Triangle>(Vector3(1, 1, -1), Vector3(-1, 1, -1), Vector3(-1, -1, -1)));

    return 0;
}
