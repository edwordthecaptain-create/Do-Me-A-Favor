#pragma once
#include <string>
#include <vector>

class Dialogue{
private:
    int dialogueId;
    std::string dialogueText;
    std::vector<std::string> choices;
    int nextDialogueId;

public:
    Dialogue(int id, std::string text, std::vector<std::string> options, int nextId);
    ~Dialogue();

    int GetDialogueId() const;
    const std::string& GetDialogueText() const;
    const std::vector<std::string>& GetChoices() const;
    int GetNextDialogueId() const;
};