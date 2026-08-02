#pragma once
#include <vector>

class Evidence;
class Consumable;

class Inventory{
private:
    std::vector<Evidence*> evidence_item;
    std::vector<Consumable*> consume_item;
public:
    void AddEvidence(Evidence* evidence);
    void RemoveEvidence(Evidence* evidence);
    void AddConsume(Consumable* consumable);
    void RemoveConsume(Consumable* consumable);

    bool HasItem(int ItemId);
    Evidence* FindEvidence(int ItemId);
    Consumable* FindConsumable(int ItemId);

    const std::vector<Evidence*>& GetEvidence() const;
    const std::vector<Consumable*>& GetConsume() const;
};