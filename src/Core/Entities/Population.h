#pragma once
#include "NPC.h"
#include <vector>

class Population{
private:
    std::vector<NPC> residents;
public:
    void AddResident(NPC npc);
    void RemoveResident(NPC npc);
    void AssignTask();
    void UpdatePopulation();

    int GetPopulationCount() const;
};