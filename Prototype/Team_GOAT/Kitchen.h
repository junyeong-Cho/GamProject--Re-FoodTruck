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
	void SetVariables();
	void SetCookVariables();

	void Update(double Width, double Height);


	int ingredient_number{ 7 };

	double first_X{ 0.0 };
	double first_Y{ 0.0 };
	double width{ 0.0 };
	double height{ 0.0 };

	double cuttingBoard_X{ 0.0 };
	double cuttingBoard_Y{ 0.0 };
	double cuttingBoard_width{ 0.0 };
	double cuttingBoard_height{ 0.0 };

	double bowl_width{ 0.0 };
	double bowl_X{ 0.0 };
	double bowl_Y{ 0.0 };

	double stove_width{ 0.0 };
	double stove_height{ 0.0 };
	double stove_X{ 0.0 };
	double stove_Y{ 0.0 };

	double trashCan_X{ 0.0 };
	double trashCan_Y{ 0.0 };
	double trashCan_width{ 0.0 };
	double trashCan_height{ 0.0 };

	double bell_X{ 0.0 };
	double bell_Y{ 0.0 };
	double bell_width{ 0.0 };

	double zero{ 0.0 };
	double endWidth{ 0.0};
	double endHeight{ 0.0 };

	double topBackground_X1{ 0.0 };
	double topBackground_Y1{ 0.0 };
	double topBackground_X2{ 0.0 };
	double topBackground_Y2{ 0.0 };
	double topBackground_X3{ 0.0 };
	double topBackground_Y3{ 0.0 };
	double topBackground_X4{ 0.0 };
	double topBackground_Y4{ 0.0 };

	double bottomBackground_X1{ 0.0 };
	double bottomBackground_Y1{ 0.0 };
	double bottomBackground_X2{ 0.0 };
	double bottomBackground_Y2{ 0.0 };
	double bottomBackground_X3{ 0.0 };
	double bottomBackground_Y3{ 0.0 };
	double bottomBackground_X4{ 0.0 };
	double bottomBackground_Y4{ 0.0 };

	double clock_X{ 0.0 };
	double clock_Y{ 0.0 };
	double clock_width{ 0.0 };
	double clock_height{ 0.0 };

	double receipt_X{ 0.0 };
	double receipt_Y{ 0.0 };
	double receipt_width{ 0.0 };
	double receipt_height{ 0.0 };

	double backCounter_X{ 0.0 };
	double backCounter_Y{ 0.0 };
	double backCounter_width{ 0.0 };
	double backCounter_height{ 0.0 };

	double toolDrawer_X{ 0.0 };
	double toolDrawer_Y{ 0.0 };
	double toolDrawer_width{ 0.0 };
	double toolDrawer_height{ 0.0 };

	double refrigerator_X{ 0.0 };
	double refrigerator_Y{ 0.0 };
	double refrigerator_width{ 0.0 };
	double refrigerator_height{ 0.0 };
	


private:
	double Width_raito = 0;
	double Height_raito = 0;
	
};