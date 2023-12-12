#include "CampaignTeam.h"

using namespace std;

CampaignTeam::CampaignTeam() : _name(""), _stance(0) {}
CampaignTeam::~CampaignTeam() {}

string CampaignTeam::getName() const { 
    return _name; 
}

int CampaignTeam::getStance() const {
    return _stance; 
}
void CampaignTeam::setName(string name) { 
    _name = name; 
}
void CampaignTeam::setStance(int stance) { 
    _stance = stance; 
}