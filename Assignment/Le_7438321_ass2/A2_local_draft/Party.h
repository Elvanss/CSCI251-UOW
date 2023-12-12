#include "CampaignTeam.h"
#include "Leader.h"
#include "Candidate.h"
#include "ManagerialTeam.h"


#include <iostream>
#include <vector>
#include <string>
#include <random>


using namespace std;

class Party{
	private:
		string _partyName;
		Leader _leader;
		vector<Candidate> _candidate;
    	ManagerialTeam _cManager;
		int _mutualStance;
	public:
		Party(); //construction
        ~Party();//destruction
        void Initialize(); 	
		string getPartyName();
		string getLeaderName();
		string getCandidateName();
		int getLeaderStance();
		int getCandidateStance();
		int getLManagerStance();
		int getNManagerStance();
		int getMutualStance();
		void setPartyName(string partyName);
		void setLeaderName(string leaderName);
		void setCandidateName(string candidateName);
    	void setLeaderStance(int stance);
		void setMutualStance(); //set the electorate supported number 
};