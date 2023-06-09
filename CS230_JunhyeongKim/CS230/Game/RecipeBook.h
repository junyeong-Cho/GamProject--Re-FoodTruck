/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  RecipeBook.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 20, 2023
Upeated:    June 2, 2023
*/
#pragma once
#include "Recipe.h"

class RecipeBook
{
public:
	RecipeBook();
	void Load();
	void Update();
	void Draw();
	void Unload();
	std::vector<Recipe*>& GetRecipeBook();
	bool BookOpen() { return bookOpen; }

private:
	std::vector<Recipe*> recipeBook;
	RecipeName page = RecipeName::LemonSalad;
	bool bookOpen = false;


	//variables
	//RecipeBook Icon
	CS230::Texture* recipeBookIconTexture;
	Math::vec2 recipeBookIconPos{ 600.0,710.0 };
	Math::vec2 recipeBookIconSize{ 70.0, 90.0 };

	//RecipeBook Exit Button
	CS230::Texture* exitButtonTexture;
	Math::vec2 exitButtonPos{ 1004.0, 620.0 };
	Math::vec2 exitButtonSize{50.0, 60.0};
};