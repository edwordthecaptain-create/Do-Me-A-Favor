#include "Generator.h"
#include "Items/Consumable.h"

Generator::Generator(int init_strength, int init_power) : Protection(init_strength){
    max_power = 100;
    power = init_power;
}

Generator::~Generator() {}

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

void Generator::Refuel(Consumable& fuel) {
    if(fuel.GetUnit() <= 0 return);

    if(fuel.GetType() == ConsumableType::GENERATOR_FUEL){
        power += fuel.GetEffectiveValue();
        if(power > max_power) power = max_power;

        fuel.Consume();
    }
}

int Generator::GetPower() const {
    return power;
}

int Generator::GetMaxPower() const {
    return max_power;
}