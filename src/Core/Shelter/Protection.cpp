#include "Protection.h"

Protection::Protection(int init_strength){
    max_durability = 100;
    durability = init_strength;
}

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

void Protection::Repair() {} //TODO

int Protection::GetDurability() const {
    return durability;
}