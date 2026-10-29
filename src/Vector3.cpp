#include "Vector3.h"
#include <iostream>

using namespace std;

Vector3::Vector3() {
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

Vector3::Vector3(double x, double y, double z) {
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

void Vector3::print() {
    cout << components[0] << "\t" << components[1] << "\t" << components[2] << "\n";
}
