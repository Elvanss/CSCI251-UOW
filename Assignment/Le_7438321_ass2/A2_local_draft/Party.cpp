#include "Party.h"
#include "Simulation.h" 

Party::Party(){} //constructor
Party::~Party(){}//destructor

void Party::Initialize() {
    _leader.setStance(Random(0,10));
    _candidate.setStance(Random(0,10));
    _cManager.setStance(Random(0,10));
    _mutualStance = 0; 
}

string Party::getPartyName() {
    return _partyName;
}

string Party::getLeaderName() {
    return _leader.getName();
}

string Party::getCandidateName() {
    return _candidate.getName();
}

int Party::getLeaderStance() {
    return _leader.getStance();
}

int Party::getCandidateStance() {
    return _candidate.getStance();
}

int Party::getLManagerStance() {
    return _cManager.getStance();
}

int Party::getNManagerStance() {
    return _nManager.getStance();
}

int Party::getMutualStance() {
    return _mutualStance;
}

void Party::setPartyName(string partyName) {
    _partyName = partyName;
}

void Party::setLeaderName(string leaderName) {
    _leader.setName(leaderName);
}

void Party::setCandidateName(string candidateName) {
    _candidate.setName(candidateName);
}

void Party::setLeaderStance(int stance) {
    _leader.setStance(stance); 
}

void Party::setMutualStance() { // Removed the default value since it was not used.
    _mutualStance = _mutualStance + 1;
}
