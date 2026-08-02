#include "Notebook.h"
#include "Items/Evidence.h"

void Notebook::AddEvidence(Evidence* evidence) {
    if(evidence == nullptr) return;

    for(int i = 0; i < evidences.size(); i++){
        if(evidences[i] == evidence || evidences[i]->GetID() == evidence->GetID()){
            return;
        }
    }
    evidences.push_back(evidence);
}

void Notebook::RemoveEvidence(Evidence* evidence) {
    for(int i = 0; i < evidences.size(); i++){
        if(evidences[i] == evidence){
            evidences.erase(evidences.begin() + i);
            break;
        }
    }
}

Evidence* Notebook::FindEvidence(int ItemId) {
    for(int i = 0; i < evidences.size(); i++){
        if(evidences[i]->GetID() == ItemId){
            return evidences[i];
        }
    }

    return nullptr;
}

const std::vector<Evidence*>& Notebook::GetEvidence() const {
    return evidences;
}