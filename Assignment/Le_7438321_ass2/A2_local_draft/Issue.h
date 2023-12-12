#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Issue{
	private:
		string _issueName; 
	public:
		Issue();//construction
		string getIssueName();//return the issue name
        void setIssueName(string issueName);
};
