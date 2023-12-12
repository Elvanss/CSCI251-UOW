#include "Event.h"


using namespace std;

Event::Event() {}
Event::~Event() {}

string Event::getEventName() {
    return _eventName;
}

void Event::setEventName(string eventName) {
   _eventName = eventName;
}

int Event::getPartyIndex() {
    return _partyIndex;
}

// void Event::setPartyIndex() {
//     _partyIndex = Random(0,3);
// }


//Derived classes tesing
LocalDebateEvent::LocalDebateEvent() {
    _eventType = EventType::LOCAL_DEBATE;
}

void LocalDebateEvent::simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) {
    Party& p = parties.at(_partyIndex);
    Electorate& e = electorates.at(electorateIndex);
    e.setStances(_partyIndex, _effect);
    p.setMutualStance();
}

void LocalDebateEvent::show() {
    cout << "Electorate " << electorateIndex << " watch local debate in which all party candidates participate. Because " << _eventName << " has " << _effectType << " performance." << endl;
    cout << "His supportation for the " << _eventName << " changes by " << _effect << " point." << endl;
}

CandidateEvent::CandidateEvent() {
    _eventType = (Random(1, 2) == 1) ? EventType::CANDIDATE_EVENT_TYPE_1 : EventType::CANDIDATE_EVENT_TYPE_2;
    _effectType = (_eventType == EventType::CANDIDATE_EVENT_TYPE_1) ? "positive" : "negative";
}

void CandidateEvent::simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) {
    Party& p = parties.at(_partyIndex);
    Electorate& e = electorates.at(electorateIndex);
    e.setStances(_partyIndex, _effect);
    p.setMutualStance();
}

void CandidateEvent::show() {
    cout << "Electorate " << simulateData << " has a " << _effectType << " effect by " << _eventName << "'s event. " << endl;
    cout << "His supportation for the " << _eventName << " changes by " << _effect << " point." << endl;
}

LeaderEvent::LeaderEvent() {
    _eventType = (Random(1, 2) == 1) ? EventType::LEADER_EVENT_TYPE_1 : EventType::LEADER_EVENT_TYPE_2;
    _effectType = (_eventType == EventType::LEADER_EVENT_TYPE_1) ? "positive" : "negative";
}

void LeaderEvent::simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) {
    Party& p = parties.at(_partyIndex);
    Electorate& e = electorates.at(electorateIndex);
    e.setStances(_partyIndex, _effect);
    p.setMutualStance();
}

void LeaderEvent::show() {
    cout << "Electorate " << electorateIndex << " has a " << _effectType << " effect by " << _eventName << "'s event. " << endl;
    cout << "His supportation for the " << _eventName << " changes by " << _effect << " point." << endl;
}

IssueEvent::IssueEvent() {
    _eventType = (Random(1, 2) == 1) ? EventType::ISSUE_EVENT_TYPE_1 : EventType::ISSUE_EVENT_TYPE_2;
    _effectType = (_eventType == EventType::ISSUE_EVENT_TYPE_1) ? "positive" : "negative";
}

void IssueEvent::simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) {
    Party& p = parties.at(_partyIndex);
    Issue& i = issues.at(_effect);
    // i.setStance(effect_type);
}

void IssueEvent::show() {
    cout << "Electorate " << electorateIndex << " has a " << _effectType << " effect by " << _eventName << "'s approach for " << _effect << " issue." << endl;
    cout << "His supportation for the " << _eventName << " changes by " << _effect << " point." << endl;
}