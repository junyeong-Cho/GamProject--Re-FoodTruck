/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Operation.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    April 12, 2023
Upeated:    June 2, 2023
*/
#pragma once
#include "ToolName.h"
#include "IngredientName.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#include "doodle/input.hpp"

class Operation
{
public:
	Operation();
	void Load();
	void Update();
	void Draw();
	ToolName Return();
	void Unload();

private:
	std::vector<CS230::Texture*> operationTexture;

	ToolName textureIndex = ToolName::HAND;
}; 