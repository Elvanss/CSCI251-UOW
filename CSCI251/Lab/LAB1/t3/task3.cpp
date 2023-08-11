#include <iostream>
#include "building.h"

using namespace std;

int main() {
    char material;
    double width, height, depth;

    material = materialAccepted();
    materialInfo(width, height, depth);
    double cost = materialCalculation(width, height, depth, material);
    printInformation(cost);

    return 0;
}
