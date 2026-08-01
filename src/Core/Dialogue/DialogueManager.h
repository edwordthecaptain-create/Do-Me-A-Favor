#pragma once
#include "Entities/NPC.h"
#include "DialogueSet.h"
#include "Dialogue"
#include <string>

class DialogueManager{
private:
    NPC* currentNPC;
    DialogueSet* currentDialogueSet;
    Dialogue* currentDialogue;
    bool isDialogueActive;
public:
    DialogueManager();
    ~DialogueManager();

    void StartDialogue(NPC* currentNPC, const std::string& currentString);
    void NextDialogue();
    void EndDialogue();
    int SelectChoice(int selectedChoice);
    bool IsDialogueActive() const;

    const Dialogue* GetCurrentDialogue() const;
    const NPC* GetCurrentNPC() const;
}