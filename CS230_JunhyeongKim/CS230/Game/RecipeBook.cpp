/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  RecipeBook.cpp
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 20, 2023
Upeated:    June 2, 2023
*/
#include "RecipeBook.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"

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

	for (int i = 0; i < recipeBook.size(); ++i)
	{
		recipeBook[i]->Load();
	}
}

void RecipeBook::Update()
{
	Math::vec2 mouse{ (double)doodle::get_mouse_x(), (double)doodle::get_mouse_y() };
	if (Engine::GetDrawManager().RectCollision(recipeBookIconPos, recipeBookIconSize, mouse) == true)
	{
		if (leftClick == true)
		{
			leftClick = false;
			bookOpen = true;
		}
	}

	if (bookOpen == true)
	{
		if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Right))
		{
			wheel = 1;
		}
		else if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Left))
		{
			wheel = -1;
		}
		page += wheel;
		wheel = 0;
		if (Engine::GetDrawManager().RectCollision(exitButtonPos, exitButtonSize, Math::vec2{ (double)doodle::get_mouse_x(), (double)doodle::get_mouse_y() }) == true)
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
		exitButtonTexture->Draw(Engine::GetDrawManager().GetMatrix(exitButtonTexture, exitButtonPos, exitButtonSize));
	}

	recipeBookIconTexture->Draw(Engine::GetDrawManager().GetMatrix(recipeBookIconTexture, recipeBookIconPos, recipeBookIconSize));
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