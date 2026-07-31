#include "Generator.h"

Generator::Generator(int init_strength, int init_power) : Protection(init_strength){
    max_power = 100;
    power = init_power;
}

void Generator::GainPower(int unit){
    power += unit;

    if(power > max_power){
        power = max_power;
    }
}

void Generator::LosePower(int unit){
    power -= unit;

    if(power < 0){
        power = 0;
    }
}

void Generator::Refuel(Consumable& consume) {}

int Generator::GetPower() const {
    return power;
}