#pragma once
#include "ToolName.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#include "InventoryTexture.h"
#include <vector>

class Tool 
{
public:
    void Load();
    void Draw();
    void ChangeTool(InventoryTexture toolName);
    ToolName GetTool() { return tool; }
    
private:
    ToolName tool = ToolName::HAND;
    std::vector<CS230::Texture*> texture;
};