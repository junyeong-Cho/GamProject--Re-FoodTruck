#pragma once
#include "Ingredient.h"
#include "Tool.h"
#include <vector>


class Cook
{
public:
	Cook();
	std::vector<Ingredient*> seven_ingredients;
	std::vector<Ingredient*> using_ingredients; 

	void DrawGrid();
	void DrawCuttingBoard();
	void DrawBowl();
	void DrawStove();
	void DrawIngredients();

	Math::vec2 WhereISMouse();
	KitchenPosition GetWhere(Math::vec2 pos);
	void SetIngredientsWhere();
	void Cutting();
	void WriteCuttingNum();
	void CreateUsingIngredient();
	void FollowMouseIngredient();
	double GetPercentOfComplete();
	int WhatIndexMouseClick();

	void Update();

	static bool isMouseClick;
	static Tool whatTool;

private:
	double first_X{ 50.0 };
	double first_Y{ 10.0 };
	double width{ 150.0 };
	double height{ 120.0 };
	int ingredient_number{ 7 };

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

	int whatMouseclickIndex = -1;
	int cuttingBoardIndex = -1;
};
