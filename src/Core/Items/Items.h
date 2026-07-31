#pragma once
#include <string>

class Items{
protected:
    int id;
    std::string name;
public:
    Items(int id, std::string name);
    ~Items();

    virtual void ApplyEffect() = 0;
    int GetID() const;
    const std::string GetName() const;
};