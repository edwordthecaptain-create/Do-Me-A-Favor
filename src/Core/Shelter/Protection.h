#pragma once

class Consumable;
class Tool;

class Protection{
private:
    int durability;
    int max_durability;
public:
    Protection(int init_strength = 100);
    ~Protection();

    void IncreaseDurability(int unit);
    void DecreaseDurability(int unit);

    void TakeDamage(int amount);
    void Repair(Consumable& material, const Tool* tool = nullptr); // TODO

    int GetDurability() const;
    int GetMaxDurability() const;
};