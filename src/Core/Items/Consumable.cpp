#include "Consumable.h"

Consumable::Consumable(int id, std::string name, int unit)
    :Items(id, name), unit(unit) {}

Consumable::~Consumable() {}

int Consumable::GetUnit() const {
    return unit;
}