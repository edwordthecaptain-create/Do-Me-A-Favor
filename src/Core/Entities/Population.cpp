#include "Population.h"

void Population::AddResident(NPC* npc){
    if(npc == nullptr) return;

    for(int i = 0; i < residents.size(); i++){
        if(residents[i] == npc || residents[i]->GetName() == npc->GetName()){
            return;
        }
    }

    residents.push_back(npc);
}

void Population::RemoveResident(NPC* npc){
    for(int i = 0; i < residents.size(); i++){
        if(residents[i] == npc){
            residents.erase(residents.begin() + i);
            break;
        }
    }
}

bool Population::AssignTask(NPC* targetNPC, int cooldownTurns = 1){
    if(targetNPC == nullptr) return false;
    if(!targetNPC->IsAvailable()) return false;

    return targetNPC->AcceptTask(cooldownTurns);
}

void Population::UpdatePopulation(){
    for(int i = 0; i < residents.size();i++){
        NPC* npc = residents[i];

        if(npc->GetState() == NPCState::WORKING){
            npc->ReduceCooldown();
        }
    }
}

int Population::GetPopulationCount() const {
    return residents.size();
}