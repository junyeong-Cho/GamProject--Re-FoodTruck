#include "Slot.h"
#include "doodle/drawing.hpp"
#include <math.h>

#include <iostream>

extern bool leftClick;

Slot::Slot(Math::vec2 pos) : position(pos)
{
	int index = 0;
	double standardX = pos.x + 40.0;
	double standardY = pos.y + 210.0;
	double padding = 60.0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			slotPos.insert(std::pair<int, Math::vec2>(index, Math::vec2(standardX + padding * j
				, standardY - padding * i)));
			++index;
		}
	}
}

Plate::Plate(Math::vec2 pos) : Slot(pos)
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/EmptyPlate.png")); // 0

	texture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Good.png")); //1
	texture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Soso.png")); //2
	texture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Bad.png")); //3

	texture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Good.png")); //4
	texture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Soso.png")); //5
	texture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Bad.png")); //6

	texture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Good.png")); //7
	texture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Soso.png")); //8
	texture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Bad.png")); //9

	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Good.png")); //10
	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Soso.png")); //11
	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Bad.png")); //12

	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Good.png")); //13
	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Soso.png")); //14
	texture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Bad.png")); //15

	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Good.png")); //16
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Soso.png")); //17
	texture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Bad.png")); //18

	texture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Good.png")); //19
	texture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Soso.png")); //20
	texture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Bad.png")); //21

	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Good.png")); //22
	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Soso.png")); //23
	texture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Bad.png")); //24

	texture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Good.png")); //25
	texture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Soso.png")); //26
	texture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Bad.png")); //27
}

Pot::Pot(Math::vec2 pos) : Slot(pos)
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/EmptyPot.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/FullPot.png"));
}
void Plate::Load()
{
}

void Pot::Load()
{
}

void Plate::Draw(int index)
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.5);

	texture[index]->Draw(matrix);
}
void Pot::Draw(int index)
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(position) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.3);
	
	texture[index]->Draw(matrix);
}

void Slot::DrawIngredient(const std::vector<std::vector<CS230::Texture*>>& texture)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		vector[i]->SlotDraw(slotPos[i], texture);
	}
}

void Slot::DrawSlotRect()
{
	for (int i = 0; i < putSize; ++i)
	{
		if (vector.size() <= i)
		{
			doodle::draw_rectangle(slotPos[i].x, slotPos[i].y, 50, 50);
		}
	}
}

void Slot::Update(double dt, int size)
{
	putSize = size;
}

void Slot::Unload()
{
	for (Ingredient* i : vector)
	{
		delete i;
	}
	vector.clear();
}

bool Slot::PutIngredient(Ingredient* ingredient)
{
	if (vector.size() < putSize)
	{
		vector.push_back(ingredient);
		return true;
	}
	return false;
}

void Plate::ButtonDraw()
{
	doodle::draw_ellipse(910, 40, 60);
}

void Pot::ButtonDraw()
{
	doodle::draw_ellipse(1350, 40, 60);
} 

bool Plate::ButtonClick(Math::vec2 pos)
{
	if (std::sqrt((std::pow((pos.x - 910), 2) + (std::pow((pos.y - 40), 2)))) <= 60)
	{
		if (leftClick == true)
		{
			leftClick = false;
			return true;
		}
	}
	return false;
}

bool Pot::ButtonClick(Math::vec2 pos)
{
	if (std::sqrt((std::pow((pos.x - 1350), 2) + (std::pow((pos.y - 40), 2)))) <= 60)
	{
		if (leftClick == true)
		{
			leftClick = false;
			return true;
		}
	}
	return false;
}

std::vector<Ingredient*>& Slot::GetIngredientVec()
{
	return vector;
}