#include "Ingredient.h"
#include <iostream>
#include "doodle/drawing.hpp"

Ingredient::Ingredient(Math::vec2 pos, Math::vec2 size)
	:position(pos), size(size)
{}

void Ingredient::Cut()
{
	if (cutNum > 1)
	{
		--cutNum;
	}
}

void Ingredient::SlotDraw(Math::vec2 pos, Math::vec2 size, const std::vector<std::vector<CS230::Texture*>>& texture)
{
	doodle::Color wetColor{ 51, 153, 255, 240 };
	Math::TransformationMatrix matrix;
	if (cutNum <= 0)
	{
		doodle::push_settings();
		if (wet == true)
		{
			doodle::set_tint_color(wetColor);
		}

		matrix = Engine::GetDrawManager().GetMatrix(texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1], pos, size);
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->Draw(matrix);
		doodle::pop_settings();
	}
	else
	{
		doodle::push_settings();
		if (wet == true)
		{
			doodle::set_tint_color(wetColor);
		}

		matrix = Engine::GetDrawManager().GetMatrix(texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum], pos, size);
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->Draw(matrix);
		doodle::pop_settings();
	}
}

void Ingredient::Draw(const std::vector<std::vector<CS230::Texture*>>& texture)
{
	Math::TransformationMatrix matrix;
	
	if (cutNum <= 0)
	{
		matrix = Engine::GetDrawManager().GetMatrix(texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1], position, size);
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->Draw(matrix);
	}
	else
	{
		matrix = Engine::GetDrawManager().GetMatrix(texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum], position, size);
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->Draw(matrix);
	}
	doodle::push_settings();
	doodle::no_fill();
	doodle::draw_rectangle(position.x, position.y, size.x, size.y);
	doodle::pop_settings();
}

bool Ingredient::IsMouseOn(Math::vec2 mousePos, const std::vector<std::vector<CS230::Texture*>>& texture)
{
	if (Engine::GetDrawManager().RectCollision(position, size, mousePos) == true)
	{
		return true;
	}
	return false;
}


Lemon::Lemon(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::Lemon;
	cutNum = 3;
	place = KitchenPosition::COUNTER1;
	
}

Lettuce::Lettuce(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::Lettuce;
	cutNum = 4;
	place = KitchenPosition::COUNTER2;

}

Ant::Ant(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::Ant;
	cutNum = 1;
	place = KitchenPosition::COUNTER3;

}

Leaf::Leaf(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::Leaf;
	cutNum = 1;
	place = KitchenPosition::COUNTER4;

}

Salt::Salt(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::Salt;
	cutNum = 3;
	place = KitchenPosition::COUNTER5;

}

DragonFruit::DragonFruit(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::DragonFruit;
	cutNum = 3;
	place = KitchenPosition::COUNTER6;

}

MermaidScales::MermaidScales(Math::vec2 pos, Math::vec2 size) : Ingredient(pos, size)
{
	name = IngredientName::MermaidScales;
	cutNum = 3;
	place = KitchenPosition::COUNTER7;

}