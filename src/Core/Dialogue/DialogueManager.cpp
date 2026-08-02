#include "DialogueManager.h"
#include "Entities/NPC.h"
#include "DialogueSet.h"
#include "Dialogue"

DialogueManager::DialogueManager(){
    currentNPC = nullptr;
    currentDialogueSet = nullptr;
    currentDialogue = nullptr;
    isDialogueActive = false;
}

DialogueManager::~DialogueManager(){}

void DialogueManager::StartDialogue(NPC* targetNPC, const std::string& currentString) {
    currentNPC = targetNPC;
    isDialogueActive = true;

    if(currentDialogueSet != nullptr){
        if(currentDialogueSet->GetDialogues().size() > 0){
            int firstDialogueId = currentDialogueSet->GetDialogues()[0].GetDialogueId();
            currentDialogue = currentDialogueSet->FindDialogue(firstDialogueId);
        }
    }
}

void DialogueManager::NextDialogue() {
    if(currentDialogue != nullptr && currentDialogueSet != nullptr){
        int nextId = currentDialogue->GetNextDialogueId();

        if(nextId == -1){
            EndDialogue();
        }else{
            currentDialogue = currentDialogueSet->FindDialogue(nextId);

            if(currentDialogue == nullptr){
                EndDialogue();
            }
        }
    }
    else{
        EndDialogue();
    }
}
void DialogueManager::EndDialogue() {
    isDialogueActive = false;
    currentNPC = nullptr;
    currentDialogue = nullptr;
}

int DialogueManager::SelectChoice(int selectedChoice){
    if(currentDialogue != nullptr){
        return currentDialogue->GetNextDialogueId();
    }
    return -1;
}

bool DialogueManager::IsDialogueActive() const {
    return IsDialogueActive;
}

const Dialogue* DialogueManager::GetCurrentDialogue() const {
    return currentDialogue;
}

const NPC* DialogueManager::GetCurrentNPC() const {
    return currentNPC;
}