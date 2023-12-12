#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const int NUM_ISSUES = 5;

class Stance {
private:
    int _significance[NUM_ISSUES];
    int _approach[NUM_ISSUES];

public:
    Stance();
    int getSignificance(int index) const;
    void setSignificance(int index, int value);
    int getApproach(int index) const;
    void setApproach(int index, int value);
    void print() const;
};

class Issue {
private:
    string _name;
    Stance _stance;


public:
    Issue(string name, Stance stance);
    string getName() const;
    void setName(const string &name);
    Stance& getStance();
    void setStance(const Stance &stance);
    const Stance& getStance() const;
};

class CampaignMember {
private:
//The popularity for both leader and candidates
    double _popularity;
    vector<Issue> stances;
public:
    CampaignMember();
    double getPopularity() const; 
    void setPopularity(double value);
    void updatePopularity(double delta);
};



class Leader : public CampaignMember {
private:
//external variable for leader
    double _influence;
public:
    Leader();
    double getInfluence() const;
    void setInfluence(double value);
    // void print() const;
};

class Candidate : public CampaignMember {
private:
//external variable for candidates
    double _loyalty;
    Stance _stance;

public:
    Candidate();
    double getLoyalty() const;
    void setLoyalty(double value);
    const Stance& getStance() const;
    // void print() const;
};

class ManagementTeam {
private:
//external variable for team
    double _efficiency;

public:
    ManagementTeam();
    double getEfficiency() const;
    void setEfficiency(double value);
    // void print() const;
};

class Party {
private:
//Call of relate objects in parties
    string _name;
    Leader _leader;
    ManagementTeam _team; 
    vector<Issue> _issues; 
    Stance _partyStance;
public: 
    Party(string name, Leader leader, vector<Candidate> candidates, ManagementTeam team);
    string getName() const;
    void setName(const string &name);
    Leader& getLeader();
    void setLeader(const Leader &leader);
    const vector<Candidate>& getCandidates() const;
    void setCandidates(const vector<Candidate>& candidates);
    vector<Candidate> _candidates;
    ManagementTeam getManagementTeam() const;
    void setManagementTeam(const ManagementTeam& team);
    const vector<Issue>& getIssues() const; 
    void setIssues(const vector<Issue>& issues);
    void addIssue(const Issue& issue);
    // void print() const;
};

class Electorate {
private:
//Order of divisions with issues
    int divisionNumber;
    std::vector<Issue> issues;

public:
    Electorate(int division);
    ~Electorate();
    int getDivisionNumber() const;
    vector<Issue>& getIssues();
    const vector<Issue>& getIssues() const;
    void addIssue(const Issue &issue);
};

class Event {
public:
    Event();
};

class Debate: public Event {
private:
    string _debateEve;

public:
    string getDebateEve();
    void setDebateEve(const string& debateEve);
    void debateType(Party& party1, Party& party2, Party& party3);
};

class Leader1 : public Event{
private:
    string _leaderEve1; 

public:
    string getLeaderEve1();
    void setLeaderEve1(const string& leaderEve1);
    void Leader1Type(Party& party1, Party& party2, Party& party3);
};

class Leader2 : public Event{
private:
    string _leaderEve2; 

public:
    string getLeaderEve2();
    void setLeaderEve2(const string& leaderEve2);
    void Leader2Type(Party& party1, Party& party2, Party& party3);
};

class Candidate1 : public Event{
private:
    string _canEve1;
public:
    string getCanEve1();
    void setCanEve1(const string& canEve1);
    void Candidate1Type(Party& party1, Party& party2, Party& party3);
};

class Candidate2 : public Event{
private:
    string _canEve2; // No need for "std::"

public:
    string getCanEve2();
    void setCanEve2(const string& canEve2);

    void Candidate2Type(Party& party1, Party& party2, Party& party3);
};

class Issue1 {
private:
    string _issueEve1; 

public:
    // Getter for _issueEve1
    string getIssueEve1() ;
    // Setter for _issueEve1
    void setIssueEve1(const string& issueEve1);
    void simulateData(Electorate& electoralDiv);
};

class Issue2 {
private:
    string _issueEve2;

public:
    string getIssueEve2() ;
    void setIssueEve2(const string& issueEve2);
    void simulateData(Electorate& electoralDiv);
};


//External functions for simulation
extern vector<Party> parties;
extern vector<Electorate> electorates;
double calculateInDebate(const Party& party, int candidateIndex);
double sum (int val1, int val2);
double computeVotingScore(const Candidate& candidate, const Electorate& electorate, const Leader& leader);
void decideWinner();
void createObj(int electorateNumber);
void showInfo(int electorateNumber, int day);
#endif
