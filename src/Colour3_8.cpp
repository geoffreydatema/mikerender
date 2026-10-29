#include "Colour3_8.h"
#include <iostream>

using namespace std;

Colour3_8::Colour3_8() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Colour3_8::Colour3_8(int x, int y, int z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

void Colour3_8::print() {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}
