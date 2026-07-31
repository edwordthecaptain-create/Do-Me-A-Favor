#pragma once
#include "Evidence.h"
#include "Consumable.h"
#include <vector>

class Inventory{
private:
    std::vector<Evidence*> evidence_item;
    std::vector<Consumable*> consume_item;
public:
    void AddEvidence(Evidence* evidence);
    void RemoveEvidence(Evidence* evidence);
    void AddConsume(Consumable* consumable);
    void RemoveConsume(Consumable* consumable);

    bool HasItem(std::string ItemName);
    Evidence* FindEvidence(std::string evidence);
    Consumable* FindConsumable(std::string consumable);

    const std::vector<Evidence*>& GetEvidence() const;
    const std::vector<Consumable*>& GetConsume() const;
};