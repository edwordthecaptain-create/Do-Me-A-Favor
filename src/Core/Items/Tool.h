#pragma once
#include <string>
#include "Items.h"

enum class ToolType{
    HAMMER,
    WRENCH,
    MULTI_TOOL
};

class Tool : public Items {
private:
    ToolType type;
    int efficiency;
public:
    Tool(int id, std::string name, ToolType type, int efficiency);
    ~Tool();

    const ToolType GetType() const;
    int GetEfficiency() const;
}