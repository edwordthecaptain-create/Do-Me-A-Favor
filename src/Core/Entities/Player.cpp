#include "Player.h"

Player::Player(int init_energy, int init_stress) {
    max_energy = 100;
    max_stress = 100;
    
    energy = init_energy;
    stress = init_stress;
}

void Player::ConsumeEnergy(int amount){
    if(energy >= 40 && energy < 60){
        amount = static_cast<int>(amount * 1.1f);
    }
    else if(energy >= 20 && energy < 40){
        amount = static_cast<int>(amount * 1.2f);
    }
    else if(energy >= 0 && energy < 20){
        amount = static_cast<int>(amount * 1.3f);
    }

    energy -= amount;

    if(energy < 0){
        energy = 0;
    }
}

void Player::RecoverEnergy(int amount){
    energy += amount;

    if(energy > max_energy){
        energy = max_energy;
    }
}

void Player::AddStress(int amount){
    stress += amount;

    if(stress > max_stress){
        stress = max_stress;
    }
}

void Player::ReduceStress(int amount){
    stress -= amount;

    if(stress < 0){
        stress = 0;
    }
}

void Player::TakeANap(int energy_unit, int stress_unit){
    RecoverEnergy(energy_unit);
    ReduceStress(stress_unit);
}
void Player::ConsumeItem(){} //TODO

int Player::GetEnergy() const {
    return energy;
}

int Player::GetStress() const {
    return stress;
}