#include "Inventory.h"

void Inventory::AddEvidence(Evidence* evidence){
    if(evidence == nullptr) return;

    for(int i = 0; i < evidence_item.size(); i++){
        if(evidence_item[i] == evidence || evidence_item[i]->GetID() == evidence->GetID()){
            return;
        }
    }

    evidence_item.push_back(evidence);
}

void Inventory::RemoveEvidence(Evidence* evidence){
    for(int i = 0; i < evidence_item.size(); i++){
        if(evidence_item[i] == evidence){
            evidence_item.erase(evidence_item.begin() + i);
            break;
        }
    }
}

void Inventory::AddConsume(Consumable* consumable){
    if(consumable == nullptr) return;

    for(int i = 0; i < consume_item.size(); i++){
        if(consume_item[i] == consumable || consume_item[i]->GetID() == consumable->GetID()){
            return;
        }
    }

    consume_item.push_back(consumable);
}

void Inventory::RemoveConsume(Consumable* consumable){
    for(int i = 0; i < consume_item.size(); i++){
        if(consume_item[i] == consumable){
            consume_item.erase(consume_item.begin() + i);
            break;
        }
    }
}

bool Inventory::HasItem(std::string ItemName){
    for(int i = 0; i < evidence_item.size(); i++){
        if(evidence_item[i]->GetName() == ItemName){
            return true;
        }
    }

    for(int i = 0; i < consume_item.size(); i++){
        if(consume_item[i]->GetName() == ItemName){
            return true;
        }
    }

    return false;
}

Evidence* Inventory::FindEvidence(std::string EvidenceName){
    for(int i = 0; i < evidence_item.size(); i++){
        if(evidence_item[i]->GetName() == EvidenceName){
            return evidence_item[i];
        }
    }

    return nullptr;
}

Consumable* Inventory::FindConsumable(std::string ConsumeName){
    for(int i = 0; i < consume_item.size();i++){
        if(consume_item[i]->GetName() == ConsumeName){
            return consume_item[i];
        }
    }

    return nullptr;
}