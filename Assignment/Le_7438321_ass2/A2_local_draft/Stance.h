#include "Electorate.h"
#include "Simulation.h"

class Stance {
public:
	int _significance[3] = {};
	int _approach;
private:
    int getSignificance(int index);
	int getApproach();
	void setSignificance(int index);
	void setApproach();
    void show();
};