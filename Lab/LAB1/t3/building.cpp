#include <iostream>
#include "building.h"
using namespace std;

char materialAccepted() {
    char material;
    cout<<"The list of the materials "<<endl;
    cout << "w: Wooden\n" << "c: Concrete\n" << "b: Brick" << endl;
    cout << "Enter the material (w, c, or b): ";
    cin >> material;

    while (material != 'w' && material != 'c' && material != 'b') {
        cout << "Wrong material! Please enter 'w', 'c', or 'b': ";
        cin >> material;
    }

    return material;
}

void materialInfo(double &width, double &height, double &depth) {
    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the height: ";
    cin >> height;
    cout << "Enter the depth: ";
    cin >> depth;
}

double materialCalculation(double width, double height, double depth, char material) {
    double cost = 0;
    int coefficient = 0;

    switch (material) {
        case 'w':
            coefficient = 75;
            break;
        case 'c':
            coefficient = 150;
            break;
        case 'b':
            coefficient = 175;
            break;
        default:
            break;
    }

    cost = coefficient * (width * height * depth) + 200;
    return cost;
}

void printInformation(double cost) {
    cout << "The final cost is $" << cost << endl;
}
