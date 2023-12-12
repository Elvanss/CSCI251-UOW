#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <random>
#include "Simulation.h"
#include "Issue.h"
#include "Electorate.h"
#include "Party.h"

using namespace std;

//Set up the vectors to store the data from Party, Issue and Electorate Division
vector<Party> parties;
vector<Issue> issues;
vector<Electorate> electorates;

//generate random engine
int Random(int lower, int upper) {
    static default_random_engine generator(random_device{}()); 
    uniform_int_distribution<int> distribution(lower, upper);
    return distribution(generator);
}

//Initialize all components
void setParty() {
    vector<string> partyList = {"Party 1", "Party 2", "Party 3"};
    vector<string> leaderList = {"Leader 1", "Leader 2", "Leader 3"};
    vector<string> candidateList ={"Candidate 1", "Candidate 2", "Candidate 3"};

    for (int i = 0; i < partyList.size(); i++) {
        Party party;
        party.Initialize();
        party.setPartyName(partyList[i]);
        party.setLeaderName(leaderList[i]);
        party.setCandidateName(candidateList[i]);
        parties.push_back(party);
    }
}

// void setIssue() {
//     // add issues to Vector:
//     vector<string> issueList = {
//         "Issue 1", 
//         "Issue 2", 
//         "Issue 3",
//         "Issue 4", 
//         "Issue 5"
//     };

//     for(const auto& name : issueList) {
//         Issue issue;
//         issue.show();
//         issue.setIssueName(name);
//         issues.push_back(issue);
//     }
// }

// void setElectorate(int electorateNum) {
//     for(int id = 0; id <electorateNum; id++) {
//         Electorate electorate;
//         electorate.show();
//         electorate.setEnum(id);
//         electorates.push_back(electorate);
//     }
// }

// //===============================PART 1: INITIALIZE THE REPORT===============================
// void showInfo(int electorateNum)
// {
//     //calling relevant methods:
//     setParty();
//     setIssue();
//     setElectorate(electorateNum);

//     cout<<"-----------------------Party List---------------------------------------"<<endl;
// 	for(int i = 0; i < 3; i++)
// 	{
// 		Party party = parties.at(i);
// 		cout<<"Party "<<i<<endl;
// 		cout<<"Party name: "<<party.getPartyName()<<endl;
// 		cout<<"Leader name: "<<party.getLeaderName()<<endl;
// 		cout<<"Candidate name: "<<party.getCandidateName()<<endl;
// 		cout<<"Leader stance: "<<party.getLeaderStance()<<endl;
// 		cout<<"Candidate stance: "<<party.getCandidateStance()<<endl;
// 		cout<<"Local Campaign  stance: "<<party.getLManagerStance()<<endl;
// 		cout<<"National campaign manager stance: "<<party.getNManagerStance()<<endl;
//         cout<<"Current stance of each party: "<<party.getMutualStance()<<endl;
// 		cout<<endl;
// 	}

// 	cout<<"-----------------------Issue Appropriation---------------------------------------"<<endl;
// 	cout<<left<<setw(30)<<"Issue name";
// 	cout<<left<<setw(30)<<"Party 1 Party 2 Party 3"<<endl;

// 	for(int i = 0; i < 5; i++)
// 	{
// 		Issue obj = issues.at(i);
// 		obj.setApproach();
// 		cout<<left<<setw(30)<<obj.getIssueName();
// 		cout<<left<<setw(10)<<obj.getSignificance(0)<<" ";
// 		cout<<left<<setw(5)<<obj.getSignificance(1)<<" ";
// 		cout<<left<<setw(5)<<obj.getSignificance(2)<<endl; 
// 	}
// 	cout<<endl;
// 	cout<<"-----------------------Electorate Appropriation---------------------------------------"<<endl;
// 	cout<<left<<setw(30)<<"Electorate ID";
// 	cout<<left<<setw(30)<<"Party 1 Party 2 Party 3"<<endl;
// 	for(int i = 0; i < electorateNum; i++) {   
//         Electorate e = electorates.at(i);
//         cout<<left<<setw(30)<<e.getEnum();
//         cout<<left<<setw(5)<<e.getStance(0)<<"  ";
//         cout<<left<<setw(5)<<e.getStance(1)<<"  ";
//         cout<<left<<setw(5)<<e.getStance(2)<<endl; 
//     }
    
// 	cout<<endl;
//     return;
// }

//===============================PART 1: SIMULATE THE CYBERTRON===============================

void simulation(int electorateNum, int day) {
    for (int current =0; current <day; current++) {
        cout<<"The day "<<current<<" in simulation:"<<endl;
        
    }
}


