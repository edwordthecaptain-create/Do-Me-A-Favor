#pragma once
#include "Items.h"
#include <string>

class Evidence : public Items {
private:
    bool Reliability;
    bool Belief;
public:
    Evidence(int id, std::string name, bool reliability, bool belief);
    ~Evidence();

    void ApplyEffect () override;
    bool GetReliability() const;
    bool GetBelief() const;
};