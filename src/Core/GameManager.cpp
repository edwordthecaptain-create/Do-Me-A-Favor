#include "GameManager.h"

GameManager::GameManager()
    : currentTurn(1), currentTime(0), IsGameOver(false) {}

GameManager::~GameManager() {}

void GameManager::StartGame() {
    currentTurn = 1;
    currentTime = 0;
    IsGameOver = false;
    currentEnding = EndingState::NONE;

    StartTurn();
}

void GameManager::StartTurn() {
    if(IsGameOver) return;
}

void GameManager::EndTurn() {
    if(IsGameOver) return;

    shelter.GetPopulation().UpdatePopulation();

    CheckEndingCondition();

    if(IsGameOver) return;

    NextTurn();
}

void GameManager::NextTurn() {
    if(IsGameOver) return;

    currentTurn++;
    currentTime += 15;

    StartTurn();
}

bool GameManager::CheckEndingCondition() {
    if(shelter.GetBarricade().GetDurability() <= 0){
        TriggerEnding(EndingState::BARRICADE_DESTROYED);
        return;
    }

    if(player.GetEnergy() <= 0){
        TriggerEnding(EndingState::PLAYER_EXHAUSED);
        return;
    }

    if(shelter.GetPopulation().GetPopulationCount() <= 0){
        TriggerEnding(EndingState::ALL_RESIDENTS_LOST);
        return;
    }
}

void GameManager::TriggerEnding(EndingState ending) {
    IsGameOver = true;
    currentEnding = ending

    if(dialogueManager.IsDialogueActive()){
        dialogueManager.EndDialogue();
    }

    switch (currentEnding) {
        case EndingState::BARRICADE_DESTROYED:
            break;

        case EndingState::PLAYER_EXHAUSTED:
            break;

        case EndingState::ALL_RESIDENTS_LOST:
            break;

        default:
            break;
    }
}

int GameManager::GetCurrentTime() const {
    return currentTime;
}

int GameManager::GetCurrentTurn() const {
    return currentTurn;
}