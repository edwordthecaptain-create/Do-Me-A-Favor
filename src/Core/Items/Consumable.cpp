#include "Consumable.h"

Consumable::Consumable(int id, std::string name, int unit)
    :Items(id, name), unit(unit) {}

int Consumable::GetUnit() const {
    return unit;
}