#include "RecipeBook.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"

bool RecipeBook::rightClick = false;
int RecipeBook::wheel = 0;

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

void RecipeBook::Update()
{
	if (doodle::get_mouse_x() >= x && doodle::get_mouse_x() <= x + width &&
		doodle::get_mouse_y() >= y && doodle::get_mouse_y() <= y + height)
	{
		if (rightClick == true)
		{
			rightClick = false;
			bookOpen = true;
			page += wheel;
			wheel = 0;
		}
	}
}



void RecipeBook::Draw()
{
	if (bookOpen == true)
	{
		
		recipeBook[static_cast<int>(page)]->Draw();
	}
}

void RecipeBook::Unload()
{
	for (Recipe* recipe : recipeBook)
	{
		delete recipe;
	}
}

void on_mouse_wheel(int scroll_amount)
{
	if (scroll_amount > 0)
	{
		RecipeBook::wheel = -1;
	}
	else if (scroll_amount < 0)
	{
		RecipeBook::wheel = 1;
	}
	else
	{
		RecipeBook::wheel = 0;
	}
}

void on_mouse_pressed(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		RecipeBook::rightClick = true;
	}
}

void on_mouse_released(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		RecipeBook::rightClick = false;
	}
}