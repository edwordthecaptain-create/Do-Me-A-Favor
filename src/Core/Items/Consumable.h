#pragma once
#include "Items.h"
#include <string>

class Consumable : public Items {
private:
    int unit;
public:
    Consumable(int id, std::string name, int unit);
    ~Consumable();

    void ApplyEffect() override;
    int GetUnit() const;
};