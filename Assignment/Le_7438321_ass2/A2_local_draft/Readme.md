Execute program:
g++ -std=c++17 Issue.cpp Electorate.cpp CampaignTeam.cpp Leader.cpp Candidate.cpp LocalManager.cpp NationalManager.cpp Party.cpp Simulation.cpp A2.cpp -o APE
./ APE m n (m and n are represent for electorate division and day/days respectively)

test:
1. set type of event
- check happened
- from 1 to x
if founded number = ?? => type

2. set happened in event
from 1 to 4 to get 1 from 4 (probability)

3. effect type:
check type(neg, 0, pos)

4. set effect
- ab1, ab2, index
- if index > 4, effect = random + ab1 + ab2 |candidate, leader, Manager|
- create obj for issue
- set approach for obj
effect = significant + approach

g++ Stance.cpp Issue.cpp Electorate.cpp CampaignMember.cpp Leader.cpp Candidate.cpp ManagerialTeam.cpp Party.cpp Electorate.cpp Event.cpp Debate.cpp Leader1.cpp Leader2.cpp Candidate1.cpp Candidate2.cpp Issue1.cpp Issue2.cpp A2.cpp -std=c++17 -o APE