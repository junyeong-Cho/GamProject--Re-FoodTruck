#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "Operation.h"
#include "KitchenPosition.h"

class Cook
{
public:
	Cook();
    void Load();
	void Update(double dt);
    void Draw();
    

	double Width_raito = 0;
	double Height_raito = 0;





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
	double endWidth{ 0.0 };
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

	double toolExplain_X{ 0.0 };
	double toolExplain_Y{ 0.0 };
	double toolExplain_width{ 0.0 };
	double toolExplain_height{ 0.0 };


	int ingredient_number{ 7 };
	void Set_Variables();

private:

    Math::vec2 WhereISMouse();
    KitchenPosition GetWhere(Math::vec2 pos);
    void SetIngredientsWhere();
    void Cutting();
    void CreateUsingIngredient();
    void FollowMouseIngredient();
    int WhatIndexMouseClick();
    void PutBowl();
    void DrawIngredients();

    //using_ingredients 벡터 중 몇번째 인덱스를 가리키고 있는지.
    int whatMouseclickIndex = -1;

    std::vector<std::vector<Ingredient*>> seven_ingredients;
    std::vector<Ingredient*> using_ingredients;
    std::vector<Ingredient*> inPlate;
    std::vector<Ingredient*> inPot;

    Tool tool;
    Operation operation;

};