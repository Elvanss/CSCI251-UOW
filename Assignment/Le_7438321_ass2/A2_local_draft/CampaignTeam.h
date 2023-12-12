#ifndef CAMPAIGN_TEAM_H
#define CAMPAIGN_TEAM_H

#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class CampaignTeam {
protected:
    string _name;
    int _stance;

public:
    CampaignTeam();
    virtual ~CampaignTeam();

    string getName() const;
    int getStance() const;
    virtual void setName(string name);
    virtual void setStance(int stance);
};

#endif //CAMPAIGN_TEAM_H
