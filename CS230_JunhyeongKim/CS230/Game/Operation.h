#pragma once
#include "InventoryName.h"
#include "ToolName.h"
#include "IngredientName.h"
#include "PetPropertyName.h"
#include "..\Engine\Texture.h"
#include "InventoryTexture.h"
#include "..\Engine\Engine.h"
#include "doodle/input.hpp"

class Operation
{
public:
	void Load();
	void Update();
	void Draw();
	InventoryTexture Return();

	static int wheel;
	static bool leftClick;
	static bool rightClick;

private:
	std::vector<CS230::Texture*> operationTexture;

	InventoryTexture textureIndex = InventoryTexture::ToolBox;
}; 