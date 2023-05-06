#include "Ingredient.h"

Ingredient::Ingredient(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:name(id), position(pos), cutNum(cuttingNumber)
{

}



Lemon::Lemon(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
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
	if (cutNum <= 0)
	{
		texture[texture.size()-1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




Leggttuce::Leggttuce(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
{}
void Leggttuce::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leggttuce1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leggttuce2.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leggttuce3.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leggttuce4.png"));
}
void Leggttuce::Update(double dt)
{

}
void Leggttuce::Draw()
{
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




Ant::Ant(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
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
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




Leaf::Leaf(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
{}
void Leaf::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Leaf.png"));
}
void Leaf::Update(double dt)
{

}
void Leaf::Draw()
{
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




Salt::Salt(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
{}
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
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




DragonFruit::DragonFruit(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
{}
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
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}




MermaidScales::MermaidScales(IngredientName id, Math::vec2 pos, int cuttingNumber)
	:Ingredient(id, pos, cuttingNumber)
{}
void MermaidScales::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScales1.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScales2.png"));
}
void MermaidScales::Update(double dt)
{

}
void MermaidScales::Draw()
{
	if (cutNum <= 0)
	{
		texture[texture.size() - 1]->Draw(Math::TranslationMatrix(position));
	}
	else
	{
		texture[texture.size() - cutNum]->Draw(Math::TranslationMatrix(position));
	}
}

