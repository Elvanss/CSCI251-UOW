#include "Header.h"


//Initialize the vector for parties, electorate and event
vector<Party> parties;
vector<Electorate> electorates;

//Random Engine
int Random(int lower, int upper) {
    static default_random_engine generator(random_device{}()); 
    uniform_int_distribution<int> distribution(lower, upper);
    return distribution(generator);
}

//-----------------------------------------------------------------------------------------------------
// Initialize the Stance randomly
Stance::Stance() {
    for (int i = 0; i < NUM_ISSUES; i++) { 
        _significance[i] = Random(0,10);
        _approach[i] = Random(0,5);
    }
} 

//getter and setter
int Stance::getSignificance(int index) const{return _significance[index];}

void Stance::setSignificance(int index, int value) {
    if (index >= 0 && index < NUM_ISSUES) _significance[index] = value;
}

int Stance::getApproach(int index) const {
    if (index >= 0 && index < NUM_ISSUES) {
        return _approach[index];
    }
    return -1;  
}

void Stance::setApproach(int index, int value) {
    if (index >= 0 && index < NUM_ISSUES) _approach[index] = value;
}

//Issue class components
Issue::Issue(string name, Stance stance) : _name(name), _stance(stance) {}
string Issue::getName() const { return _name; }
void Issue::setName(const string &name) { _name = name; }
Stance& Issue::getStance() {return _stance;}
void Issue::setStance(const Stance &stance) { _stance = stance; }
const Stance& Issue::getStance() const {return _stance;}



//Campaign member class components
CampaignMember::CampaignMember() {
    _popularity = Random(0,100);
}
double CampaignMember::getPopularity() const { return _popularity; }
void CampaignMember::setPopularity(double value) { _popularity = value; }
void CampaignMember::updatePopularity(double delta)  {_popularity += delta;}


//Leader class components
Leader::Leader() : CampaignMember() {
    _influence = Random(0,50);
}
double Leader::getInfluence() const { return _influence; }
void Leader::setInfluence(double value) { _influence = value; }

//Candidate class components
Candidate::Candidate() : CampaignMember(), _stance(Stance()) { 
        _loyalty = Random(0, 70);
    }
double Candidate::getLoyalty() const { return _loyalty; }
void Candidate::setLoyalty(double value) { _loyalty = value; }
const Stance& Candidate::getStance() const { return _stance; }

//Team class components
ManagementTeam::ManagementTeam() {
    _efficiency = Random(0,100);
}
double ManagementTeam::getEfficiency() const { return _efficiency; }
void ManagementTeam::setEfficiency(double value) { _efficiency = value; }

//Party class components
Party::Party(string name, Leader leader, vector<Candidate> candidates, ManagementTeam team)
    : _name(name), _leader(leader), _candidates(candidates), _team(team) {}
string Party::getName() const { return _name; }
void Party::setName(const string &name) { _name = name; }
// Leader Party::getLeader() const { return _leader; 
Leader& Party::getLeader() {return _leader;}
void Party::setLeader(const Leader &leader) { _leader = leader; }
const vector<Candidate>& Party::getCandidates() const {return _candidates;}
void Party::setCandidates(const vector<Candidate>& candidates) {_candidates = candidates;}
ManagementTeam Party::getManagementTeam() const {return _team;}
void Party::setManagementTeam(const ManagementTeam& team) {_team = team;}
const vector<Issue>& Party::getIssues() const {return _issues;}
void Party::setIssues(const vector<Issue>& issues) {_issues = issues;}
void Party::addIssue(const Issue& issue) {_issues.push_back(issue);}

//Electoral Division components
Electorate::Electorate(int division) : divisionNumber(division) {}
Electorate::~Electorate() {}
int Electorate::getDivisionNumber() const {return divisionNumber;}
vector<Issue>& Electorate::getIssues() {return issues;}
const vector<Issue>& Electorate::getIssues() const {return issues;}
void Electorate::addIssue(const Issue &issue) {issues.push_back(issue);}

Event::Event() {}

// Implement the getter and setter functions for Debate class
string Debate::getDebateEve() {return _debateEve;}

void Debate::setDebateEve(const string& debateEve) {_debateEve = debateEve;}

// Implement the simulateData function for Debate class
void Debate::debateType(Party& party1, Party& party2, Party& party3) {
    int candidateIndex = Random(0, party1.getCandidates().size() - 1);
    double p1Effect = calculateInDebate(party1, candidateIndex);
    double p2Effect = calculateInDebate(party2, candidateIndex);
    double p3Effect = calculateInDebate(party3, candidateIndex);
    int turn = Random(0,3);
    if (turn <= p1Effect) {
        party1._candidates[candidateIndex].updatePopularity(party1.getManagementTeam().getEfficiency());
        cout << "Candidate " << candidateIndex<<" of " << party1.getName() << " has won the debate! The popularity will increase to " << party1.getCandidates().at(candidateIndex).getPopularity() << endl;
    } else if (turn <=sum(p1Effect, p2Effect)) {
        party2._candidates[candidateIndex].updatePopularity(party2.getManagementTeam().getEfficiency());
        cout << "Candidate " << candidateIndex<<" of " << party2.getName() << " has won the debate! The popularity will increase to " << party2.getCandidates().at(candidateIndex).getPopularity()<< endl;
    } else {
        party2._candidates[candidateIndex].updatePopularity(party3.getManagementTeam().getEfficiency());
        cout << "Candidate " << candidateIndex<<" of " << party3.getName() << " has won the debate! The popularity will increase to " << party2.getCandidates().at(candidateIndex).getPopularity() << endl;
    }
}

string Leader1::getLeaderEve1() {return _leaderEve1;}
void Leader1::setLeaderEve1(const string& leaderEve1) {_leaderEve1 = leaderEve1;}
void Leader1::Leader1Type(Party& party1, Party& party2, Party& party3) {
    // Call a temporary vector
    vector<Party*> partyList;
    partyList.push_back(&party1);
    partyList.push_back(&party2);
    partyList.push_back(&party3);
    int random = Random(0, 1);
    for (int i = 0; i < partyList.size(); i++) {
        if (random == 0) {
            Leader& leader = partyList.at(i)->getLeader();
            leader.setPopularity(leader.getPopularity() + Random(0, 10));
            cout << "The popularity of the leader in " << partyList.at(i)->getName() << " has been increased to " << leader.getPopularity() << endl;
        } else {
            Leader& leader = partyList.at(i)->getLeader();
            leader.setPopularity(leader.getPopularity() - Random(0,10));
            cout << "The popularity of the leader in " << partyList.at(i)->getName() << " has been decreased to " << leader.getPopularity() << endl;
        }
    }
}

string Leader2::getLeaderEve2() {return _leaderEve2;}
void Leader2::setLeaderEve2(const string& leaderEve2) {_leaderEve2 = leaderEve2;}
void Leader2::Leader2Type(Party& party1, Party& party2, Party& party3) {
    // Call a temporary vector
    vector<Party*> partyList;
    partyList.push_back(&party1);
    partyList.push_back(&party2);
    partyList.push_back(&party3);
    //run randomly of 0 and other num
    for (int i = 0; i < partyList.size(); i++) {
        int random = Random(0, partyList.at(i)->getLeader().getInfluence());
        if (random == 0) {
            Leader& leader = partyList.at(i)->getLeader();
            leader.setPopularity(leader.getPopularity() + Random(0, 10));
            cout << "The popularity of the leader in " << partyList.at(i)->getName() << " has been increased to " << leader.getPopularity() <<endl;
        } else {
            Leader& leader = partyList.at(i)->getLeader();
            leader.setPopularity(leader.getPopularity() - Random(0,10));
            cout << "The popularity of the leader in " << partyList.at(i)->getName() << " has been decreased to " << leader.getPopularity() << endl;
        }
    }
}

//getter and setter
string Candidate1::getCanEve1() {return _canEve1;}
void Candidate1::setCanEve1(const string& canEve1) {_canEve1 = canEve1;}
void Candidate1::Candidate1Type(Party& party1, Party& party2, Party& party3) {
    int candidateIndex = Random(0, party1.getCandidates().size() - 1);
    //call a temporary vector
    vector<Party*> partyList;
    partyList.push_back(&party1);
    partyList.push_back(&party2);
    partyList.push_back(&party3);
    for (int i =0; i< partyList.size(); i++) {
        //2 options from 0 to 1
        int Coefficient = Random(0,1);
        if(Coefficient == 0) {
            partyList.at(i)->_candidates.at(candidateIndex).updatePopularity(Random(0, 20));
            cout << "Candidate " << candidateIndex<<" of " << partyList.at(i)->getName()<<" was increase to "<<partyList.at(i)->getCandidates().at(candidateIndex).getPopularity()<<endl;
        } else {
            partyList.at(i)->_candidates.at(candidateIndex).updatePopularity(Random(-10, 0));
            cout << "Candidate " << candidateIndex<<" of " << partyList.at(i)->getName()<<" was down to "<<partyList.at(i)->getCandidates().at(candidateIndex).getPopularity()<<endl;
        }
    }
}

//getter and setter
string Candidate2::getCanEve2() {return _canEve2;}
void Candidate2::setCanEve2(const string& canEve2) {_canEve2 = canEve2;}
void Candidate2::Candidate2Type(Party& party1, Party& party2, Party& party3) {
    int candidateIndex = Random(0, party1.getCandidates().size() - 1);
    //call a temporary vector
    vector<Party*> partyList;
    partyList.push_back(&party1);
    partyList.push_back(&party2);
    partyList.push_back(&party3);
    //run through from 1 to party 3
    for (int i =0; i< partyList.size(); i++) {
        //get the Coefficient from loyalty of candidates
        int Coefficient = Random(0, partyList.at(i)->getCandidates().at(candidateIndex).getLoyalty());
        if(Coefficient - partyList.at(i)->getCandidates().at(candidateIndex).getLoyalty() <0) {
            partyList.at(i)->_candidates.at(candidateIndex).updatePopularity(Random(0, 20));
            cout << "Candidate " << candidateIndex<<" of " << partyList.at(i)->getName()<<" was increase to "<<partyList.at(i)->getCandidates().at(candidateIndex).getPopularity()<<endl;
        } else {
            partyList.at(i)->_candidates.at(candidateIndex).updatePopularity(Random(-10, 0));
            cout << "Candidate " << candidateIndex<<" of " << partyList.at(i)->getName()<<" was down to "<<partyList.at(i)->getCandidates().at(candidateIndex).getPopularity()<<endl;
        }
    }
}

//getter and setter
string Issue1::getIssueEve1() {return _issueEve1;}
void Issue1::setIssueEve1(const string& issueEve1) {_issueEve1 = issueEve1;
}

//The methods can interact with the date processing
void Issue1::simulateData(Electorate& electoralDiv) {
    int iStanceIndex = Random(0,4);
    Stance& currentStance = electoralDiv.getIssues().at(iStanceIndex).getStance();
    int newSignificance = currentStance.getSignificance(iStanceIndex) + Random(0,10);
    currentStance.setSignificance(iStanceIndex, newSignificance);
    cout << " The " << electoralDiv.getIssues().at(iStanceIndex).getName() << " will be changed! The significance will be increased to " << currentStance.getApproach(iStanceIndex) << endl;
}

//getter and setter
string Issue2::getIssueEve2() {
    return _issueEve2;
}
void Issue2::setIssueEve2(const string& issueEve2) {
    _issueEve2 = issueEve2;
}
//The methods can interact with the date processing
void Issue2::simulateData(Electorate& electoralDiv) {
    int iStanceIndex = Random(0,4);
    Stance& currentStance = electoralDiv.getIssues().at(iStanceIndex).getStance();
    int newApproach = currentStance.getApproach(iStanceIndex) + Random(0,10);
    currentStance.setApproach(iStanceIndex, newApproach);
     cout << " The " << electoralDiv.getIssues().at(iStanceIndex).getName() << " will be changed! Its approach will be increased to " << currentStance.getApproach(iStanceIndex) << endl;
}



//-----------------------------------------------------------------------------------------------------
double sum (int val1, int val2) {return val1 + val2;}
void createObj(int electorateNum) {
    parties.clear();
    electorates.clear();

    //  list of issues (without specific stances)
    vector<Issue> issueList = {
        Issue("Climate Change", Stance()),
        Issue("Water Pollution", Stance()),
        Issue("Over Population", Stance()),
        Issue("equality", Stance()),
        Issue("Starvation", Stance())
    };

    // For Party 1
    Leader leader1;
    vector<Candidate> candidates1;
    for (int i = 0; i < electorateNum; ++i) {  // candidates for each party = electorate
        Candidate candidate;
        candidates1.push_back(candidate);
    }
    ManagementTeam team1;
    Party party1("Libertarian Party", leader1, candidates1, team1);
    for (Issue& issue : issueList) {
        party1.addIssue(Issue(issue.getName(), Stance()));
    }
    parties.push_back(party1);

    // For Party 2
    Leader leader2;
    vector<Candidate> candidates2;
    for (int i = 0; i < electorateNum; ++i) {
        Candidate candidate;
        candidates2.push_back(candidate);
    }
    ManagementTeam team2;
    Party party2("Green Party", leader2, candidates2, team2);
    for (Issue& issue : issueList) {
        party2.addIssue(Issue(issue.getName(), Stance()));
    }
    parties.push_back(party2);

    // For Party 3
    Leader leader3;
    vector<Candidate> candidates3;
    for (int i = 0; i < electorateNum; ++i) {
        Candidate candidate;
        candidates3.push_back(candidate);
    }

    ManagementTeam team3;
    Party party3("Constitution Party", leader3, candidates3, team3);
    for (Issue& issue : issueList) {
        party3.addIssue(Issue(issue.getName(), Stance()));
    }
    parties.push_back(party3);

    for (int i = 0; i < electorateNum; i++) {  
        Electorate electorate(i + 1);  
        for (Issue& issue : issueList) {
            electorate.addIssue(Issue(issue.getName(), Stance()));
        }
        electorates.push_back(electorate);
    }
    
}

void showInfo(int electorateNumber, int day) {
    createObj(electorateNumber);
cout<<"\n--------------------------------Initialize the Parties, Issues, and Divisions-------------------------------------\n"<<endl;
    // Display Party Information
    for (Party &party : parties) { // Change const Party to Party
        cout << "Political party name: " << party.getName() << "\n";
        Leader leader = party.getLeader(); 
        cout << "Leader: popularity: " << leader.getPopularity() << ", Influence: " << leader.getInfluence() << "\n";
        cout << "Candidate:\n";
        for (const Candidate &candidate : party.getCandidates()) {
            cout << "   Popularity: " << candidate.getPopularity() << ", Skill: " << candidate.getLoyalty() << "\n";
        }
        //Get the managerial team
        ManagementTeam team = party.getManagementTeam();
        cout << "Campaign team: efficiency: " << team.getEfficiency() << "\n";
        cout << "Stances:\n";
        //Get the significant and approach of each issue
        for (const Issue &issue : party.getIssues()) {
            Stance stance = issue.getStance();
            cout << "   Issue: " << issue.getName() << ", Significance: " << stance.getSignificance(0) << ", Approach: " << stance.getApproach(0) << "\n";
        }
        cout << "\n";
    }


    // Display Electorate Details
    for (const Electorate &electorate : electorates) {
        cout << "Division number: " << electorate.getDivisionNumber() << "\n";
        for (const Issue &issue : electorate.getIssues()) {
            Stance stance = issue.getStance();
            cout << "   Issue: " << issue.getName() << ", Significance: " << stance.getSignificance(0) << ", Approach: " << stance.getApproach(0) << "\n";
        }
        cout << "\n";
    }

   for (int i = 0; i < day; i++) {
    cout << "------------------------------------------------------------\n";
    cout << "Simulation for Day: " << (i + 1) << "\n";
    cout << "------------------------------------------------------------\n";

    for (Electorate& e : electorates) {
        cout << "Division: " << e.getDivisionNumber() << "\n";
        //Random with 2 choices
        int Chance = Random(0, 1);
        if (Chance == 1) {
            int oP = Random(1, 4);

            if (oP == 1) {
                Debate debate;
                debate.debateType(parties[0], parties[1], parties[2]); 
            } else if (oP == 2) {
                int separate = Random(0, 1);
                if (separate == 0) {
                    Candidate1 can1;
                    can1.Candidate1Type(parties[0], parties[1], parties[2]);
                } else {
                    Candidate2 can2;
                    can2.Candidate2Type(parties[0], parties[1], parties[2]); 
                }
            } else if (oP == 3) {
                int separate = Random(0, 1);
                if (separate == 0) {
                    Leader1 leader1;
                    leader1.Leader1Type(parties[0], parties[1], parties[2]); 
                } else {
                    Leader2 leader2;
                    leader2.Leader2Type(parties[0], parties[1], parties[2]); 
                }
            } else {
                int separate = Random(0, 1);
                if (separate == 0) {
                    Issue1 i1;
                    i1.simulateData(e);
                } else {
                    Issue2 i2;
                    i2.simulateData(e);
                }
            }
            cout << "\n";
        } else {
            cout << "No event in the division " << e.getDivisionNumber() << " on Day " << (i + 1) << ".\n\n";
        }
    }
    }
    cout<<"\n--------------------------------After Simulation-------------------------------------\n"<<endl;
    for (Party &party : parties) {
        cout << "Political party name: " << party.getName() << "\n";
        Leader leader = party.getLeader();
        cout << "Leader: popularity: " << leader.getPopularity() << ", Influence: " << leader.getInfluence() << "\n";
        cout << "Candidate:\n";
        for (const Candidate &candidate : party.getCandidates()) {
            cout << "   Popularity: " << candidate.getPopularity() << ", Skill: " << candidate.getLoyalty() << "\n";
        }
        ManagementTeam team = party.getManagementTeam();
        cout << "Campaign team: efficiency: " << team.getEfficiency() << "\n";
        cout << "Stances:\n";
        for (const Issue &issue : party.getIssues()) {
            Stance stance = issue.getStance();
            cout << "   Issue: " << issue.getName() << ", Significance: " << stance.getSignificance(0) << ", Approach: " << stance.getApproach(0) << "\n";
        }
        cout << "\n";
    }

    // Display Electorate Information
    cout << "Electorate Information:\n";
    for (const Electorate &electorate : electorates) {
        cout << "Division number: " << electorate.getDivisionNumber() << "\n";
        for (const Issue &issue : electorate.getIssues()) {
            Stance stance = issue.getStance();
            cout << "   Issue: " << issue.getName() << ", Significance: " << stance.getSignificance(0) << ", Approach: " << stance.getApproach(0) << "\n";
        }
        cout << "\n";
}
//get the winner:
    decideWinner();
}

/* External functions */
double calculateInDebate(const Party& party, int candidateIndex) {
    return party.getCandidates()[candidateIndex].getPopularity() + party.getManagementTeam().getEfficiency();
}

double computeVotingScore(const Candidate& candidate, const Electorate& electorate, const Leader& leader) {
    double euclideanDistance = 0;
    double avgDistance;

    for (int i = 0; i < NUM_ISSUES; i++) {
        double significanceDiff = candidate.getStance().getSignificance(i) - electorate.getIssues()[i].getStance().getSignificance(i);
        double approachDiff = candidate.getStance().getApproach(i) - electorate.getIssues()[i].getStance().getApproach(i);

        euclideanDistance += sqrt(pow(significanceDiff, 2) + pow(approachDiff, 2));
    }

    // Average stance Euclidean distance
    avgDistance = euclideanDistance / NUM_ISSUES;

    // max distance of candidates
    double maxDistance = sqrt(pow(10, 2) + pow(10, 2));  
    double normalizedDistance = 1 - (avgDistance / maxDistance);  

    // The average stance distance , candidate popularity, and leader popularity.
    return (0.6 * normalizedDistance * 100) + (0.3 * candidate.getPopularity()) + (0.1 * leader.getPopularity());
}

void decideWinner() {
    // Initialize vectors for tracking winner.
    vector<string> partyNames;
    vector<int> winsCount(parties.size(), 0);

    // party vector.
    for (Party& p : parties) {
        partyNames.push_back(p.getName());
    }

    for (Electorate& e : electorates) {
        // Use separate vectors for party scores.
        vector<double> partyScores;

        for (Party& p : parties) {
            //run through the candidate
            Candidate repCandidate = p.getCandidates()[e.getDivisionNumber() - 1];
            double score = computeVotingScore(repCandidate, e, p.getLeader());
            //add score to vector
            partyScores.push_back(score);
        }

        // Find the index of the max points.
        double maxScore = partyScores[0];
        int maxIndex = 0;
        for (int i = 1; i < partyScores.size(); i++) {
            if (partyScores[i] > maxScore) {
                maxScore = partyScores[i];
                maxIndex = i;
            }
        }

        // Update the wins count for the winning party.
        winsCount[maxIndex]++;

        // Display the winner for the division.
        cout << "In division " << e.getDivisionNumber() << ", the winner is " << partyNames[maxIndex] << " with a score is " << maxScore << endl;
    }

    // Display the number of wins for each party.
    cout << "\n-------------------------------- Party Wins Summary --------------------------------\n";
    for (int i = 0; i < partyNames.size(); i++) {
        cout << partyNames[i] << " has won " << winsCount[i] << " divisions.\n";
    }

    // Determine the overall winner.
    int maxWins = *max_element(winsCount.begin(), winsCount.end());
    int indexOfMaxWins = distance(winsCount.begin(), find(winsCount.begin(), winsCount.end(), maxWins));

    // Check if the overall winner has won more than 50% of the divisions.
    if (maxWins > electorates.size() / 2) {
        cout << "\nThe overall winner is " << partyNames[indexOfMaxWins] << ".\n";
    } else {
        cout << "\nNo party has won more than 50% of the divisions.\n";
    }
}

//-----------------------------------------------------------------------------------------------------