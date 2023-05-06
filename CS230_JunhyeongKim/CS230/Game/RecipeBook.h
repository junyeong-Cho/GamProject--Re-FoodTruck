#pragma once
#include "Recipe.h"

class RecipeBook
{
public:
	RecipeBook();
	
	void Draw();
	void Unload();
private:
	std::vector<Recipe*> recipeBook;
	RecipeName now = RecipeName::LemonSalad;
};