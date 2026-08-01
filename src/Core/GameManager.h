#pragma once
#include "Entities/Player.h"
#include "Shelter/Shelter.h"
#include "Dialogue/DialogueManager.h"

enum class EndingState{
    NONE,
    BARRICADE_DESTROYED,
    PLAYER_EXHAUSED,
    ALL_RESIDENTS_LOST
};

class GameManager{
private:
    Player player;
    Shelter shelter;
    DialogueManager dialogueManager;

    int currentTurn;
    int currentTime;
    bool IsGameOver;

    EndingState currentEnding;

public:
    GameManager();
    ~GameManager();

    void StartGame();
    void StartTurn();
    void EndTurn();
    void NextTurn();
    void CheckEndingCondition();

    void TriggerEnding(EndingState ending);
    int GetCurrentTurn() const;
    int GetCurrentTime() const;
    bool IsGameOver() const;
    EndingState GetCurrentEnding() const;
};