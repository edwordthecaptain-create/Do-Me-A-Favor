#include "Dialogue.h"

Dialogue::Dialogue(int id, std::string text, std::vector<std::string> options, int nextId)
    : dialogueId(id), dialogueText(text), choices(options), nextDialogueId(nextId) {}

Dialogue::~Dialogue() {}

int Dialogue::GetDialogueId() const {
    return dialogueId;
}

const std::string& Dialogue::GetDialogueText() const {
    return dialogueText;
}

const std::vector<std::string>& Dialogue::GetChoices() const {
    return choices;
}

int Dialogue::GetNextDialogueId() const {
    return nextDialogueId;
}