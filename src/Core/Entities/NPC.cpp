#include "NPC.h"

void NPC::SetState(NPCState newState){
    state = newState;
}

void NPC::SetCooldown(int turns){
    if(turns >= 0){
        cooldownTurn = turns;
    }
}

void NPC::ReduceCooldown(){
    if(cooldownTurn > 0){
        cooldownTurn--;
    }

    if(cooldownTurn == 0 && state == NPCState::WORKING){
        state = NPCState::WAITING;
    }
}

bool NPC::IsAvailable(){
    return (state == NPCState::WAITING && cooldownTurn == 0);
}

bool NPC::IsAlive(){
    return (state != NPCState::DEAD);
}

bool NPC::Die(){
    if(IsAlive()){
        state = NPCState::DEAD;
        cooldownTurn = 0;
        return true;
    }

    return false;
}

void NPC::Talk(){}

bool NPC::AcceptTask(){
    if(IsAvailable()){
        state = NPCState::WORKING;
        return true;
    }

    return false;
}

bool NPC::CompleteTask(){
    if(state == NPCState::WORKING){
        state = NPCState::WAITING;
        cooldownTurn = 0;
        return true;
    }

    return false;
}

bool NPC::LeaveShelter(){
    if(state != NPCState::DEAD && state != NPCState::LEFT){
        state = NPCState::LEFT;
        return true;
    }
    return false;
}