#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "Operation.h"
#include "KitchenPosition.h"
#include "Slot.h"

#include "RecipeBook.h"
#include "RecipeName.h"

#include "IngredientTextureManager.h"

class Cook
{
public:
	Cook();
    void Load();
	void Update(double dt);
    void Draw();
	void Unload();
	void DrawScore();
	void SetScore(std::vector<Recipe*>& recipeBook);
	void DrawGage();
	Math::vec2 WhereISMouse();
	void GetOrder(RecipeName orderRecipe, std::vector<Recipe*>& recipeBook);
	int GetSideBwolSize(int index) { return seven_ingredients[index].size(); }
	void Refill(int index);
	

	//variables
	//CuttingBoard
	Math::vec2 cuttingBoardPos{ 60.0, 90.0 };
	Math::vec2 cuttingBoardSize{ 473.0, 327.0 };

	//Plate
	Math::vec2 platePos{ 580.0, 100.0 };
	Math::vec2 plateSize{ 300, 200.0 };

	//Plate Button
	Math::vec2 plateButtonPos{ 820.0, 80.0 };
	Math::vec2 plateButtonSize{ 60.0, 60.0 };

	//Complete Percent Text
	Math::vec2 percentTextPos{ 680.0, 55.0 };
	Math::vec2 percentTextSize{ 30.0, 0.0 };

	//Pot
	Math::vec2 potPos{ 920.0, 40.0 };
	Math::vec2 potSize{ 425.0, 400.0 };

	//Pot Button
	Math::vec2 potButtonPos{ 1305.0, 160.0 };
	Math::vec2 potButtonSize{ 60.0, 60.0 };

	//Pot GageBar
	Math::vec2 gageBarPos{ 920.0, 40.0 };
	Math::vec2 wholeGageBarSize{ 250.0, 50.0 };
	Math::vec2 gageBarTextPos{ 1290.0, 50.0 };
	Math::vec2 gageBarTextSize{ 30.0, 0 };

	//RecipeBook
	Math::vec2 recipeBookPos{ 580.0, 720.0 };
	Math::vec2 recipeBookSize{ 70.0, 80.0 };

	//OrderFrame
	Math::vec2 orderFramePos{ 700.0, 670.0 };
	Math::vec2 orderFrameSize{ 215.0, 130.0 };

	//OrderRecipe
	Math::vec2 orderRecipePos{ 745.0, 710.0 };
	Math::vec2 orderRecipeSize{ 120.0, 80.0 };

	//Bell
	Math::vec2 bellPos{ 1245.0, 450.0 };
	Math::vec2 bellSize{ 115.0, 115.0 };

	//SideBowl
	Math::vec2 sideBowlBoardFirstPos{ 65.0, 470.0 };
	Math::vec2 sideBowlSize{ 155.0, 145.0 };
	Math::vec2 sideBowlPadding{ 10.0,10.0 };

	//Ingredient
	Math::vec2 ingredientSize{ 100.0, 100.0 };
	Math::vec2 ingredientPadding{ 20.0, 30.0 };

	int ingredient_number{ 7 };
	void ClickBell();

private:

    
    KitchenPosition GetWhere(Math::vec2 pos);
    void SetIngredientsWhere();
    void Cutting();
    void CreateUsingIngredient();
    void FollowMouseIngredient();
    int WhatIndexMouseClick();
    void PutSlot();
    void DrawIngredients();
	void SlotDraw();
	void SetStoveOn();
	void PotToPlate();
	int ReturnScore() { return score; }
	void SetIngredient();
	Ingredient* CreateIngredient(int index);
	void TrashCan();
	void ToolTask();



    //using_ingredients 벡터 중 몇번째 인덱스를 가리키고 있는지.
    int whatMouseclickIndex = -1;

    std::vector<std::vector<Ingredient*>> seven_ingredients;
    std::vector<Ingredient*> using_ingredients;

	IngredientTextureManager ingredientTextureManager;
    Tool tool;
    Operation operation;
	Plate plate;
	Pot pot;
	int score = 0;
	double time = 0;
	bool stoveOn = false;
	std::string text = "Off";
	int potDrawIndex = 0;
	int plateDrawIndex = 0;
	bool checkDrawSoup = false;
	bool canCook = true;

	RecipeName order;
	int orderSize = 0;

	int refillNum = 3;
	int firstIngredientNum = 3;
};