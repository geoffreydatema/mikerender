#include <cstdlib>
#include "NumberUtils.h"

using namespace std;

double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    return min + (max - min) * random_double();
}
