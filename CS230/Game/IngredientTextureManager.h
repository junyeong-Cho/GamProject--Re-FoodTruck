/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  IngredientTextureManager.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    May 20, 2023
*/
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
	std::vector<std::vector <CS230::Texture*>> ingredientTexture;
};