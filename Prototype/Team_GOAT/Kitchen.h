#pragma once
#include "Cook.h"

class Kitchen
{
public:
	Kitchen() {}

	Cook cook{ };

	void Draw_BackGround();
	void Draw_CuttingBoard();
	void Draw_Bowl();
	void Draw_Stove();
	void Draw_SideBowl();
	void Draw_Clock();
	void Draw_Receipt();
	void Draw_BackCounter();
	void Draw_ToolDrawer();
	void Draw_Refrigerator();
	void Draw_Bell();
	void SetVariables(double Width, double Height);
	void SetCookVariables();

	void Update(double Width, double Height);


	int ingredient_number{ 7 };

	double first_X{ 50.0 };
	double first_Y{ 10.0 };
	double width{ 150.0 };
	double height{ 120.0 };

	double cuttingBoard_X{ 50.0 };
	double cuttingBoard_Y{ 200.0 };
	double cuttingBoard_width{ 500.0 };
	double cuttingBoard_height{ 400.0 };

	double bowl_width{ 400 };
	double bowl_X{ 580.0 + bowl_width / 2 };
	double bowl_Y{ 200.0 + bowl_width / 2 };

	double stove_width{ 400 };
	double stove_X{ 1000.0 + stove_width / 2 };
	double stove_Y{ 200.0 + stove_width / 2 };

	double trashCan_X{ first_X + width * 6 + 50 };
	double trashCan_Y{ first_Y };
	double trashCan_width{ 100.0 };
	double trashCan_height{ height };

	double bell_X{ 50.0 };
	double bell_Y{ 200.0 };
	double bell_width{ 500.0 };
	double bell_height{ 400.0 };

private:
	double Width_raito = 0;
	double Height_raito = 0;
	
};