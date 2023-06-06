#pragma once
#include "ToolName.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#include <vector>

class Tool 
{
public:
    Tool();
    void Load();
    void Draw();
    void Update(ToolName toolName);
    ToolName GetTool() { return tool; }
    
private:
    ToolName tool = ToolName::HAND;
    std::vector<CS230::Texture*> texture;
    Math::vec2 pos;
    Math::vec2 size{ 70.0, 70.0 };
};