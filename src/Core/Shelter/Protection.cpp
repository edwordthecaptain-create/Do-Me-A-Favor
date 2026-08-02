#include "Protection.h"
#include "Items/Consumable.h"
#include "Items/Tool.h"

Protection::Protection(int init_strength){
    max_durability = 100;
    durability = init_strength;
}

Protection::~Protection() {}

void Protection::IncreaseDurability(int unit){
    durability += unit;

    if(durability > max_durability){
        durability = max_durability;
    }
}

void Protection::DecreaseDurability(int unit){
    durability -= unit;

    if(durability < 0){
        durability = 0;
    }
}

void Protection::TakeDamage(int amount){
    DecreaseDurability(amount);
}

void Protection::Repair(Consumable& material, const Tool* tool) {
    if(material.GetUnit() <= 0){
        return;
    }

    int multiplier = 1;
    if(tool != nullptr){
        multiplier = tool->GetEfficiency();
    }

    int totalRepairAmount = material.GetEffectiveValue() * multiplier;

    IncreaseDurability(totalRepairAmount);
    material.Consume();
} //TODO

int Protection::GetDurability() const {
    return durability;
}