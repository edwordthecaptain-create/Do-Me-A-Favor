#pragma once
#include "Items/Evidence.h"
#include <vector>

class Notebook{
private:
    std::vector<Evidence*> evidences;
public:
    Notebook();
    ~Notebook();

    void AddEvidence(Evidence* evidence);
    void RemoveEvidence(Evidence* evidence);
    void FindEvidence(Evidence* evidence);
    
    const std::vector<Evidence*>& GetEvidence() const;
};