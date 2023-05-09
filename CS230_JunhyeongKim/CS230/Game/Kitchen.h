#pragma once

#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Engine/Engine.h"
#include "States.h"
#include "Button.h"
#include "Cook.h"
#include "RecipeBook.h"

class Kitchen : public CS230::GameState
{
public:
    Kitchen();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    std::string GetName() override { return "Kitchen"; }

    void Draw_UI();
    void Draw_Background();
    void Draw_Clock();
    void Draw_Money();
    void Draw_RecipeBook();
    void Draw_Order();
    void Draw_CounterButton();
    void Draw_Bell();
    void Draw_IngredientBowl();
    void Draw_CuttingBoard();
	void Draw_PaltingSpot();


private:
    Cook cook;
    RecipeBook recipeBook;
    Button go_counter;
};