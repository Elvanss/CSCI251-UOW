#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Electorate { 
    private:
        int _eNum;
        int _candidate = 0;
        int _stances[3] = {}; // initialize the stance that represent for each party (Random)
    public: 
        //contructor
        Electorate();
        //destructor
        // ~Electorate(){};
        //getter 
        int getEnum();
        int getCandidate();
		int getStance(int party);//show the credit points by party index
        //setter
		void setEnum(int eNum);
        void setCandidate(int party);//according to the largest of credit points to choose the candidate
		void setStances(int party, int credit);//change by index of party and stance
        void show();
};