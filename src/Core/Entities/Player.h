#pragma once

class Player{
private:
    int energy;
    int stress;

    int max_energy;
    int max_stress;

public:
    Player(int init_energy = 100, int init_stress = 0);
    ~Player();

    void ConsumeEnergy(int amount);
    void RecoverEnergy(int amount);
    void AddStress(int amount);
    void ReduceStress(int amount);

    void TakeANap(int energy_unit, int stress_unit);
    void ConsumeItem();

    int GetEnergy() const;
    int GetStress() const;
};