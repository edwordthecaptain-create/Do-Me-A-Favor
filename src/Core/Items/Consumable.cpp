#include "Consumable.h"

Consumable::Consumable(int id, std::string name, int unit, int effectiveValue, ConsumableType type)
    :Items(id, name), unit(unit), effectValue(effectValue), ConsumableType(type) {}

Consumable::~Consumable() {}

void Consumable::ApplyEffect(){}

void Consumable::Consume(){
    if(unit > 0) unit--;
}

int Consumable::GetEffectiveValue() const {
    return effectValue;
}

int Consumable::GetUnit() const {
    return unit;
}

const ConsumableType Consumable::GetType() const {
    return type;
}
