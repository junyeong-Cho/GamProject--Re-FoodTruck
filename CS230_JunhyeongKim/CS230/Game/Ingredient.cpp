#include "Ingredient.h"
#include <iostream>

Ingredient::Ingredient(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:name(id), position(pos), cutNum(cuttingNumber), place(place)
{

}

void Ingredient::SlotDraw(Math::vec2 pos)
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(pos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}

bool Ingredient::IsMouseOn(Math::vec2 mousePos)
{
	if (position.x - 50 < mousePos.x && position.x + 50 > mousePos.x
		&& position.y - 50 < mousePos.y && position.y + 50 > mousePos.y)
	{
		return true;
	}
	return false;
}

Lemon::Lemon(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{}
void Lemon::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lemon1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lemon2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lemon3.png"));
}
void Lemon::Update(double dt)
{

}
void Lemon::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size()-1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




Lettuce::Lettuce(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
}
void Lettuce::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lettuce1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lettuce2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lettuce3.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Lettuce4.png"));
}
void Lettuce::Update(double dt)
{

}
void Lettuce::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




Ant::Ant(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{}
void Ant::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Ant.png"));
}
void Ant::Update(double dt)
{

}
void Ant::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




Leaf::Leaf(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
	
}
void Leaf::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leaf.png"));
}
void Leaf::Update(double dt)
{

}
void Leaf::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




Salt::Salt(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
	
}
void Salt::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Salt1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Salt2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Salt3.png"));
}
void Salt::Update(double dt)
{

}
void Salt::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




DragonFruit::DragonFruit(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
	
}
void DragonFruit::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruit1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruit2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruit3.png"));
}
void DragonFruit::Update(double dt)
{

}
void DragonFruit::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}




MermaidScales::MermaidScales(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
	
}
void MermaidScales::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScales1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScales2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScales3.png"));
}
void MermaidScales::Update(double dt)
{

}
void MermaidScales::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}

Water::Water(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place)
	:Ingredient(id, pos, cuttingNumber, place)
{
	
}
void Water::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Ingredient_Water.png"));
}
void Water::Update(double dt)
{

}
void Water::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.1);
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(matrix);
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(matrix);
	}
}