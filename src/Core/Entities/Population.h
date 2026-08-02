#pragma once
#include <vector>

class NPC;

class Population{
private:
    std::vector<NPC*> residents;
public:
    void AddResident(NPC* npc);
    void RemoveResident(NPC* npc);

    bool AssignTask(NPC* targetNPC, int cooldownTurns = 1);
    void UpdatePopulation();

    int GetPopulationCount() const;
};  