#include "Tool.h"

Tool::Tool(int id, std::string name, ToolType type, int efficiency)
    : Items(id, name), type(type), efficiency(efficiency) {}

Tool::~Tool() {}

ToolType Tool::GetType() const {
    return type;
}

const int Tool::GetEfficiency() const {
    return efficiency
}