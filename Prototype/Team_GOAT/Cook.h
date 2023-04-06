#pragma once
#include "Ingredient.h"
#include "Tool.h"
#include <vector>


class Cook
{
public:
	Cook();
	std::vector<std::vector<Ingredient*>> seven_ingredients;
	std::vector<Ingredient*> using_ingredients;
	std::vector<Ingredient*> inBowl;

	void DrawIngredients();

	Math::vec2 WhereISMouse();
	KitchenPosition GetWhere(Math::vec2 pos);
	void SetIngredientsWhere();
	void Cutting();
	void WriteCuttingNum();
	void CreateUsingIngredient();
	void FollowMouseIngredient();
	int GetPercentOfComplete();
	int WhatIndexMouseClick();
	void DrawToolName();
	void ChangeIngredientSize();
	void Salad();
	void PutBowl();
	void Draw_CompletePoint();
	void PutBell();
	void DrawStoveText();

	void Update();

	static bool isMouseClick;
	static Tool whatTool;
	int completePoint{ 0 };

	int ingredient_number{ 7 };

	double first_X{ 150.0 };
	double first_Y{ 300.0 };
	double width{ 170.0 };
	double height{ 120.0 };

	double cuttingBoard_X{ 50.0 };
	double cuttingBoard_Y{ 200.0 };
	double cuttingBoard_width{ 500.0 };
	double cuttingBoard_height{ 400.0 };

	double bowl_width{ 400 };
	double bowl_X{ 580.0 + bowl_width / 2 };
	double bowl_Y{ 200.0 + bowl_width / 2 };

	double stove_width{ 400 };
	double stove_height{ 0.0 };
	double stove_X{ 1000.0 + stove_width / 2 };
	double stove_Y{ 200.0 + stove_width / 2 };

	double bell_X{ 0.0 };
	double bell_Y{ 0.0 };
	double bell_width{ 0.0 };

private:

	//using_ingredients 벡터 중 몇번째 인덱스를 가리키고 있는지.
	int whatMouseclickIndex = -1;


	double Width_raito = 0;
	double Height_raito = 0;
};
