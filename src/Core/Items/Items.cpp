#include "Items.h"

Items::Items(int id, std::string name) :
    id(id), name(name) {}

Items::~Items() {}

int Items::GetID() const {
    return id;
}

const std::string Items::GetName() const {
    return name;
}