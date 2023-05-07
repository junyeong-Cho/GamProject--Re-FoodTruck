#include "RecipeBook.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include <iostream>

extern int wheel;
extern bool leftClick;
extern bool rightClick;

RecipeBook::RecipeBook()
{
	recipeBook.push_back(new LemonSalad(RecipeName::LemonSalad, 18));
	recipeBook.push_back(new SaltSalad(RecipeName::SaltSalad, 12));
	recipeBook.push_back(new LeafSalad(RecipeName::LeafSalad, 15));
	recipeBook.push_back(new AntSalad(RecipeName::AntSalad, 30));
	recipeBook.push_back(new DragonFruitSalad(RecipeName::DragonFruitSalad, 21));
	recipeBook.push_back(new MermaidScalesSalad(RecipeName::MermaidScalesSalad, 24));
	recipeBook.push_back(new WaterSoup(RecipeName::WaterSoup, 12));
	recipeBook.push_back(new AntSoup(RecipeName::AntSoup, 21));
	recipeBook.push_back(new StrongSoup(RecipeName::StrongSoup, 36));

}

void RecipeBook::Load()
{
	for (Recipe* recipe : recipeBook)
	{
		recipe->Load();
	}
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
}