#pragma once
#include "Protection.h"

class Consumable;

class Generator : public Protection{
private:
    int power;
    int max_power;
public:
    Generator(int init_strength = 100, int init_power = 100);
    ~Generator();

    void GainPower(int unit);
    void LosePower(int unit);

    void Refuel(Consumable& consume);
    int GetPower() const;
    int GetMaxPower() const;
};