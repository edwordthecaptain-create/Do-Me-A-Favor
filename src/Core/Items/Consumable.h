#pragma once
#include "Items.h"
#include <string>

class Player;

enum Class ConsumableType{
    PLAYER_STAT,
    GENERATOR_FUEL,
    REPAIR_MATERIAL
};

class Consumable : public Items {
private:
    int unit;
    int effectValue;
    ConsumableType Type;
public:
    Consumable(int id, std::string name, int unit, int effective, ConsumableType type);
    ~Consumable();

    void ApplyEffect() override;
    void Consume();

    int GetUnit() const;
    int GetEffectiveValue() const;
    const ConsumableType GetType() const;
};