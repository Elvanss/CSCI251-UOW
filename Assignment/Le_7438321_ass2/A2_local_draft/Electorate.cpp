#include "Electorate.h"
#include "Simulation.h"

using namespace std;

Electorate::Electorate() {}
// Electorate::~Electorate() {}
int Electorate::getEnum() {
    return _eNum;
}

int Electorate::getCandidate() {
    return _candidate;
}

int Electorate::getStance(int party) {
    return _stances[party];
}

void Electorate::setEnum(int eNum) {
    _eNum = eNum;
}

// void Electorate::setCandidate(int party) {
    
// }

void Electorate::setStances(int party, int credit) {
    _stances[party] += credit;
}

void Electorate::show() {
    for (int i = 0; i<3; i++) {
        //The initial points of each electorate of each party is 0 respectively
        _stances[i] = Random(0,5);
    }
}
