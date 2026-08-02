#pragma once 
#include <string>
#include <vector>

class Dialogue;

class DialogueSet{
private:
    std::string setName;
    std::vector<Dialogue> dialogues;
public:
    DialogueSet(std::string name);
    ~DialogueSet();

    void AddDialogue(const Dialogue& dialogue);
    void RemoveDialogue(int dialogueId);

    Dialogue* FindDialogue(int dialogueId);
    const std::vector<Dialogue>& GetDialogues() const;
    const std::string& GetSetName() const;
};