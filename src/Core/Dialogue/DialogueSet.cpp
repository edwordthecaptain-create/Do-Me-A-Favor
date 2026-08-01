#include "DialogueSet.h"

DialogueSet::DialogueSet(std::string name){
    setName = name;
}

DialogueSet::~DialogueSet() {}

void DialogueSet::AddDialogue(const Dialogue& dialogue) {
    for(int i = 0; i < dialogues.size(); i++){
        if(dialogues[i].GetDialogueId() == dialogue.GetDialogueId()){
            return;
        }
    }
    dialogues.push_back(dialogue);
}

void DialogueSet::RemoveDialogue(int dialogueId){
    for(int i = 0; i < dialogues.size(); i++){
        if(dialogues[i].GetDialogueId() == dialogueId){
            dialogues.erase(dialogues.begin() + i);
            break;
        }
    }
}

Dialogue* DialogueSet::FindDialogue(int dialogueId){
    for(int i = 0; i < dialogues.size(); i++){
        if(dialogues[i].GetDialogueId() == dialogueId){
            return &dialogues[i];
        }
    }
    return nullptr;
}

const std::vector<Dialogue>& DialogueSet::GetDialogues() const {
    return dialogues;
}

const std::string DialogueSet::GetSetName() const {
    return setName;
}