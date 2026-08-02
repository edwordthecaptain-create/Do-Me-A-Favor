#pragma once
#include <string>

class DialogueManager;

enum class Role{
    ALLY,
    SCAMMER,
    RANDOM
};

enum class NPCState{
    WAITING,
    WORKING,
    MISSING,
    DEAD,
    LEFT
};

enum class Ability{
    NONE,
    ENGINEER,
    BUILDER,
    SCAVENGER,
    MEDIC,
    GUARD
};

class NPC{
private:
    std::string name;
    Ability ability;
    Role role;
    NPCState state;
    int cooldownTurn;
public:
    NPC(std::string name, Ability skill, Role role, NPCState state, int cooldown);
    ~NPC();

    void SetState(NPCState SetState);
    void SetCooldown(int turns);
    void ReduceCooldown();
    bool IsAvailable();
    bool IsAlive();
    
    bool Die();
    void Talk(DialogueManager* dialogueManager, std::string context = "");
    bool AcceptTask(int cooldownTurns);
    bool CompleteTask();
    bool LeaveShelter();

    const NPCState GetState() const;
    const Ability GetAbility() const;
    const Role GetRole() const;
    std::string GetName() const;
};