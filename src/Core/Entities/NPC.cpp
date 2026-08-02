#include "NPC.h"
#include "Dialogue/DialogueManager.h"

NPC::NPC(std::string name, Ability skill, Role role, NPCState state, int cooldown)
    :name(name), ability(skill), role(role), state(state), cooldownTurn(cooldown){}

NPC::~NPC(){}

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

void NPC::Talk(DialogueManager* dialogueManager, std::string context = ""){
    if (dialogueManager == nullptr || state == NPCState::DEAD || state == NPCState::LEFT || state == NPCState::MISSING) {
        return;
    }

    if (state == NPCState::WORKING) {
        context = "Busy";
    } else if (context == "") {
        context = "Default";
    }

    dialogueManager->StartDialogue(this, context);
}

bool NPC::AcceptTask(int cooldownTurns){
    if(!IsAvailable()){
        return false;
    }

    state = NPCState::WORKING;
    cooldownTurn = cooldownTurns;

    return true;
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