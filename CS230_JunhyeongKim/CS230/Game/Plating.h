#pragma once
#include "Ingredient.h"
#include <vector>

class Plating
{
public: 
	Plating();
	void Load();
	void Draw();
	void Update();
	void Draw_Slot();
	void Unload();

private:
	double Width_raito = 0;
	double Height_raito = 0;
	double bowl_X = 0;
	double bowl_Y = 0;
	double bowl_width = 0;
	int slotVerticalNum = 4;
	int slotHorizontalNum = 3;
	double slotWidth = 0;

	double slotPadding = 0;
	double slotFirst_x = 0;
	double slotFirst_y = 0;
};