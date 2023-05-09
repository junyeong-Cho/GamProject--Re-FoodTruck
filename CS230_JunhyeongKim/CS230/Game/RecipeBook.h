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
	std::vector<Recipe*> GetRecipeBook() { return recipeBook; }

private:
	std::vector<Recipe*> recipeBook;
	RecipeName page = RecipeName::LemonSalad;
	bool bookOpen = false;
	int x = 50;
	int y = 50;
	int width = 50;
	int height = 50;

	int closeX = 100;
	int closeY = 50;
	int closeWidth = 50;
	int closewHeight = 50;
};