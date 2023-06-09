/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Tool.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    April 10, 2023
Upeated:    June 2, 2023
*/
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
    ToolName GetTool() { return toolname; }
    void Unload();
    
private:
    ToolName toolname = ToolName::HAND;
    std::vector<CS230::Texture*> texture;
    Math::vec2 pos;
    Math::vec2 size{ 70.0, 70.0 };
};