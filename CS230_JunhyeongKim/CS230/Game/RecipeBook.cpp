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

}

void RecipeBook::Update()
{
	for (Recipe* recipe : recipeBook)
	{
		recipe->Update();
	}

	if (doodle::get_mouse_x() >= x && doodle::get_mouse_x() <= x + width &&
		doodle::get_mouse_y() >= y && doodle::get_mouse_y() <= y + height)
	{
		if (leftClick == true)
		{
			leftClick = false;
			bookOpen = true;
		}
	}
	else if (doodle::get_mouse_x() >= closeX && doodle::get_mouse_x() <= closeX + closeWidth &&
		doodle::get_mouse_y() >= closeY && doodle::get_mouse_y() <= closeY + closewHeight)
	{
		if (leftClick == true)
		{
			leftClick = false;
			bookOpen = false;
			page = RecipeName::LemonSalad;
		}
	}
	if (bookOpen == true)
	{
		page += wheel;
		wheel = 0;
	}
}



void RecipeBook::Draw()
{
	if (bookOpen == true)
	{
		recipeBook[static_cast<int>(page)]->Draw();
	}
	doodle::draw_rectangle(x, y, width, height);
	doodle::draw_rectangle(closeX, closeY, closeWidth, closewHeight);

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