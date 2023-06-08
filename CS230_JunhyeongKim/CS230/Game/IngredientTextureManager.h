#pragma once
#include <vector>
#include "IngredientName.h"
#include "../Engine/Texture.h"

class IngredientTextureManager
{
public:
	IngredientTextureManager();
	void Load();
	void Unload();
	std::vector<std::vector<CS230::Texture*>> GetTexture() const;
private:
	int ingredientNum = 7;
	std::vector<std::vector <CS230::Texture*>> ingredientTexture{ ingredientNum };
};