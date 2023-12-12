#include "Stance.h"

int Stance::getSignificance(int index) {
    return _significance[index];
}

int Stance::getApproach() {
    return _approach;
}

void setSignificance(int index) {

}

void Stance::setApproach() { 
    _approach = Random(0,5);
}

void Stance::show() {
    for (int i = 0; i<3; i++) {
        _significance[i] = Random(-2,2); 
    }
}