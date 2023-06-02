#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient(Math::vec2 pos)
	:position(pos)
{}

void Ingredient::Cut()
{
	if (cutNum > 1)
	{
		--cutNum;
	}
}

void Ingredient::SlotDraw(Math::vec2 pos, const std::vector<std::vector<CS230::Texture*>>& texture)
{
	double slotScale = 0.7;
	Math::TransformationMatrix matrix = Math::TranslationMatrix(pos) * Math::RotationMatrix(0) * Math::ScaleMatrix(scale * slotScale);
	if (cutNum <= 0)
	{
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->Draw(matrix);
	}
	else
	{
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->Draw(matrix);
	}
}

void Ingredient::Draw(const std::vector<std::vector<CS230::Texture*>>& texture)
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(scale);
	texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->Set_tint_color(0, 0, 255);

	if (cutNum <= 0)
	{
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->Draw(matrix);
	}
	else
	{
		texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->Draw(matrix);
	}
}

bool Ingredient::IsMouseOn(Math::vec2 mousePos, const std::vector<std::vector<CS230::Texture*>>& texture)
{
	Math::vec2 size{};

	if (cutNum <= 0)
	{
		size = Math::vec2{ (double)texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->GetSize().x,
				(double)texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - 1]->GetSize().y } *scale;
	}
	else
	{
		size = Math::vec2{ (double)texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->GetSize().x,
				(double)texture[static_cast<int>(name)][texture[static_cast<int>(name)].size() - cutNum]->GetSize().y } *scale;
	}

	if (mousePos.x >= position.x && mousePos.x <= position.x + size.x &&
		mousePos.y >= position.y && mousePos.y <= position.y + size.y)
	{
		return true;
	}
	return false;
}


Lemon::Lemon(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::Lemon;
	cutNum = 3;
	place = KitchenPosition::COUNTER1;
	
}
void Lemon::SetScale(Math::vec2 raito)
{
	if (cutNum == 3)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 2)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

Lettuce::Lettuce(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::Lettuce;
	cutNum = 4;
	place = KitchenPosition::COUNTER2;

}
void Lettuce::SetScale(Math::vec2 raito)
{
	if (cutNum == 4)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 3)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 2)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

Ant::Ant(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::Ant;
	cutNum = 1;
	place = KitchenPosition::COUNTER3;

}
void Ant::SetScale(Math::vec2 raito)
{
	if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

Leaf::Leaf(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::Leaf;
	cutNum = 1;
	place = KitchenPosition::COUNTER4;

}
void Leaf::SetScale(Math::vec2 raito)
{
	if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

Salt::Salt(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::Salt;
	cutNum = 3;
	place = KitchenPosition::COUNTER5;

}
void Salt::SetScale(Math::vec2 raito)
{
	if (cutNum == 3)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 2)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

DragonFruit::DragonFruit(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::DragonFruit;
	cutNum = 3;
	place = KitchenPosition::COUNTER6;

}
void DragonFruit::SetScale(Math::vec2 raito)
{
	if (cutNum == 3)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 2)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}

MermaidScales::MermaidScales(Math::vec2 pos) : Ingredient(pos)
{
	name = IngredientName::MermaidScales;
	cutNum = 3;
	place = KitchenPosition::COUNTER7;

}
void MermaidScales::SetScale(Math::vec2 raito)
{
	if (cutNum == 3)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum == 2)
	{
		scale = 0.1 * raito.x;
	}
	else if (cutNum <= 1)
	{
		scale = 0.1 * raito.x;
	}
}