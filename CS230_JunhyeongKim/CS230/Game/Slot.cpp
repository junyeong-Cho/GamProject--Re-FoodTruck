#include "Slot.h"
#include "doodle/drawing.hpp"

#include <iostream>

extern bool leftClick;

Slot::Slot(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize) 
	: position(pos), size(size), buttonPos(buttonPos), buttonSize(buttonSize)
{
	standardSlotRectPos.x += pos.x;
}

void Slot::SetSlotPos()
{
	int index = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			slotPos.insert(std::pair<int, Math::vec2>(index, Math::vec2(standardSlotRectPos.x + (standardSlotRectPadding.x + standardSlotRectSize.x) * j
				, standardSlotRectPos.y - (standardSlotRectPadding.y + standardSlotRectSize.y) * i)));
			++index;
		}
	}
}

Plate::Plate(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize) : Slot(pos, size, buttonPos, buttonSize)
{

	standardSlotRectPos.x += padding;
	SetSlotPos();
}

Pot::Pot(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize) : Slot(pos, size, buttonPos, buttonSize)
{
	standardSlotRectPos.x += padding;
	SetSlotPos();
}
void Plate::Load()
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

void Pot::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/StoveOffPot.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/StoveOnPot.png"));
}

void Slot::Draw(int index)
{
	Math::TransformationMatrix matrix = Engine::GetDrawManager().GetMatrix(texture[index], position, size);

	texture[index]->Draw(matrix);
}

void Slot::DrawIngredient(const std::vector<std::vector<CS230::Texture*>>& texture)
{
	for (int i = 0; i < vector.size(); ++i)
	{
		vector[i]->SlotDraw(slotPos[i], standardSlotRectSize, texture);
	}
}

void Slot::DrawSlotRect()
{
	doodle::Color slotColor{ 192,192,192,30 };

	for (int i = 0; i < putSize; ++i)
	{
		if (vector.size() <= i)
		{
			doodle::push_settings();
			doodle::set_fill_color(slotColor);
			doodle::draw_rectangle(Engine::GetDrawManager().Vec(slotPos[i]).x, Engine::GetDrawManager().Vec(slotPos[i]).y, 
				Engine::GetDrawManager().Vec(standardSlotRectSize).x, Engine::GetDrawManager().Vec(standardSlotRectSize).y);
			doodle::pop_settings();
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

bool Plate::PutIngredient(Ingredient* ingredient)
{
	if (vector.size() < putSize)
	{
		vector.push_back(ingredient);
		return true;
	}
	return false;
}

bool Pot::PutIngredient(Ingredient* ingredient)
{
	if (vector.size() < putSize)
	{
		ingredient->SetWet();
		vector.push_back(ingredient);
		return true;
	}
	return false;
}

void Slot::ButtonDraw()
{
	doodle::draw_ellipse(Engine::GetDrawManager().Vec(buttonPos).x, Engine::GetDrawManager().Vec(buttonPos).y, 
		Engine::GetDrawManager().Vec(buttonSize).x);
}


bool Slot::ButtonClick(Math::vec2 pos)
{
	if (Engine::GetDrawManager().CircleCollision(buttonPos, buttonSize, pos) == true)
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
