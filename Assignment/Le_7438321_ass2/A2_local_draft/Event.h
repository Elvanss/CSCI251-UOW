#include "Party.h"
#include "Electorate.h"
#include "Issue.h"
#include "Simulation.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <iomanip>
#include <cmath>


using namespace std;

class Event {
    
protected:
    enum EventType {
        LOCAL_DEBATE,
        CANDIDATE_EVENT_TYPE_1,
        CANDIDATE_EVENT_TYPE_2,
        LEADER_EVENT_TYPE_1,
        LEADER_EVENT_TYPE_2,
        ISSUE_EVENT_TYPE_1,
        ISSUE_EVENT_TYPE_2
    };
    string _eventName;
    int _partyIndex;
    EventType _eventType;
    int _effect;
    string _effectType;
    //testing
    int electorateIndex;
    bool _happened;
public:
    Event();
    ~Event();
    virtual void simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues);
    string getEventName();
    //Done
    virtual void setEventName(string eventName);
    //Done
    int getPartyIndex();
    //Done
    void setPartyIndex();
    string getEffectType();
    void setEventType();
    int getEffect();
    void setEffect();
    string getEffectType();
    void setEffectType();
    bool getHappened();
    void setHappened();
    //simulation
    int chooseIssue();
    void manageElectorate();
    virtual void show();
    
};

class LocalDebateEvent : public Event {
public:
    LocalDebateEvent();
    void simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) override;
    void show() override;
};

class CandidateEvent : public Event {
public:
    CandidateEvent();
    void simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) override;
    void show() override;
};

class LeaderEvent : public Event {
public:
    LeaderEvent();
    void simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) override;
    void show() override;
};

class IssueEvent : public Event {
public:
    IssueEvent();
    void simulateData(vector<Electorate>& electorates, vector<Party>& parties, vector<Issue>& issues) override;
    void show() override;
};
