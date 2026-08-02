#include "Evidence.h"

Evidence::Evidence(int id, std::string name, bool reliability, bool belief)
    : Items(id, name), Reliability(reliability), Belief(belief) {}

Evidence::~Evidence() {}

void Evidence::ApplyEffect() {}

bool Evidence::GetReliability() const {
    return Reliability;
}

bool Evidence::GetBelief() const {
    return Belief;
}