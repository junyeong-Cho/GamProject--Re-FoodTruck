#pragma once
#include "ToolName.h"
#include "IngredientName.h"
#include "PetPropertyName.h"
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