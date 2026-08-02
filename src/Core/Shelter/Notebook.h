#pragma once
#include <vector>

class Evidence;

class Notebook{
private:
    std::vector<Evidence*> evidences;
public:
    Notebook();
    ~Notebook();

    void AddEvidence(Evidence* evidence);
    void RemoveEvidence(Evidence* evidence);
    Evidence* FindEvidence(int ItemId);
    
    const std::vector<Evidence*>& GetEvidence() const;
};