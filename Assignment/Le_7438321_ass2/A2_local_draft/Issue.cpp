#include "Issue.h"
#include "Simulation.h"

using namespace std;

Issue::Issue() {}

string Issue::getIssueName() {
    return _issueName;
}


void Issue::setIssueName(string issueName) {
    _issueName = issueName;
}

