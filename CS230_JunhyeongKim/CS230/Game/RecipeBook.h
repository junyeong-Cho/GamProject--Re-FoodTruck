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

private:
	CS230::Texture* recipeBookIconTexture;

	std::vector<Recipe*> recipeBook;
	RecipeName page = RecipeName::LemonSalad;
	bool bookOpen = false;

	Math::vec2 recipeBookIconPos;

	CS230::Texture* exitButtonTexture;
	Math::vec2 exitButtonPos;
};