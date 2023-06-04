#include "RecipeBook.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include <iostream>

extern int wheel;
extern bool leftClick;
extern bool rightClick;

RecipeBook::RecipeBook()
{}

void RecipeBook::Load()
{
	recipeBook.push_back(new LemonSalad());
	recipeBook.push_back(new SaltSalad());
	recipeBook.push_back(new LeafSalad());
	recipeBook.push_back(new AntSalad());
	recipeBook.push_back(new DragonFruitSalad());
	recipeBook.push_back(new MermaidScalesSalad());
	recipeBook.push_back(new WaterSoup());
	recipeBook.push_back(new AntSoup());
	recipeBook.push_back(new StrongSoup());

	exitButtonTexture = Engine::GetTextureManager().Load("Assets/Recipe_Button.png");
	recipeBookIconTexture = Engine::GetTextureManager().Load("Assets/Recipe_book_icon.png");

	Recipe* currentRecipe = recipeBook[static_cast<int>(page)];
	Math::vec2 pagePos = currentRecipe->GetRecipeTexturePos();
	Math::vec2 pageSize = static_cast<Math::vec2>(currentRecipe->GetRecipeTextureSize());
	Math::vec2 buttonGap{ 100.0, 80.0 };
	exitButtonPos = pagePos + pageSize - buttonGap;

	recipeBookIconPos = Math::vec2(0, 0);
}

void RecipeBook::Update()
{
	for (Recipe* recipe : recipeBook)
	{
		recipe->Update();
	}

	if (doodle::get_mouse_x() >= recipeBookIconPos.x && doodle::get_mouse_x() <= recipeBookIconPos.x + recipeBookIconTexture->GetSize().x &&
		doodle::get_mouse_y() >= recipeBookIconPos.y && doodle::get_mouse_y() <= recipeBookIconPos.y + recipeBookIconTexture->GetSize().y)
	{
		if (leftClick == true)
		{
			leftClick = false;
			bookOpen = true;
		}
	}

	if (bookOpen == true)
	{
		page += wheel;
		wheel = 0;
		if (doodle::get_mouse_x() >= exitButtonPos.x && doodle::get_mouse_x() <= exitButtonPos.x + exitButtonTexture->GetSize().x &&
			doodle::get_mouse_y() >= exitButtonPos.y && doodle::get_mouse_y() <= exitButtonPos.y + exitButtonTexture->GetSize().y)
		{
			if (leftClick == true)
			{
				leftClick = false;
				bookOpen = false;
				page = RecipeName::LemonSalad;
			}
		}
	}
}



void RecipeBook::Draw()
{
	if (bookOpen == true)
	{
		recipeBook[static_cast<int>(page)]->Draw();

		Math::TransformationMatrix buttonMat = Math::TranslationMatrix(exitButtonPos) * Math::RotationMatrix(0) * Math::ScaleMatrix(1.0);
		exitButtonTexture->Draw(buttonMat);
	}

	Math::TransformationMatrix recipeIconMat = Math::TranslationMatrix(recipeBookIconPos) * Math::RotationMatrix(0) * Math::ScaleMatrix(1.0);
	recipeBookIconTexture->Draw(recipeIconMat);

}

void RecipeBook::Unload()
{
	for (Recipe* recipe : recipeBook)
	{
		recipe->Unload();
		delete recipe;
	}
	recipeBook.clear();

}

std::vector<Recipe*>& RecipeBook::GetRecipeBook()
{

	return recipeBook;
}