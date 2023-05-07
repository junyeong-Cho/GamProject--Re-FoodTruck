#include "Plating.h"
#include "doodle/drawing.hpp"

extern bool leftClick;

Plating::Plating()
{

}

void Plating::Load()
{

}

void Plating::Draw()
{
	
}

void Plating::Draw_Slot()
{
	for (int i = 0; i < slotVerticalNum; ++i)
	{
		for (int j = 0; j < slotHorizontalNum; ++j)
		{
			doodle::draw_rectangle(slotFirst_x + slotPadding * i, slotFirst_y + slotPadding * j, slotWidth, slotWidth);
		}
	}
}

void Plating::Update()
{
	Width_raito = Engine::GetWindow().GetSize().x / 1400.0;
	Height_raito = Engine::GetWindow().GetSize().y / 800.0;
	bowl_X = Width_raito * 800.0;
	bowl_Y = Height_raito * 220.0;
	bowl_width = Width_raito * 280.0;
	slotWidth = Width_raito * 50.0;
	slotFirst_x = Width_raito * 500.0;
	slotFirst_y = Height_raito * 300.0;
	slotPadding = Width_raito * 70.0;
}

void Plating::Unload()
{

}