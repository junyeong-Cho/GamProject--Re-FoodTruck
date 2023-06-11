/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Kitchen.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 10, 2023
Updated:    June 9, 2023
*/
#pragma once


#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Engine/Engine.h"
#include "States.h"
#include "Button.h"
#include "Cook.h"
#include "RecipeBook.h"
#include "SideBowl.h"

#include "Reputation.h"
#include "Frame.h"

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
    void Draw_Order();
    void Draw_CounterButton();
    void Draw_Bell();
    void Draw_CuttingBoard();
	void Draw_PaltingSpot();
    void Draw_Frame_Text();
    void SetOrder();



private:
    bool canLoad = true;
    bool canUnload = false;
    Cook cook;
    RecipeBook recipeBook;
    Button go_counter;
    Math::vec2 go_counterPos{ 990.0, 720.0 };
    Math::vec2 go_counterSize{ 120.0, 80.0 };

    std::vector<SideBowl> sideBowl;
    CS230::Texture* cuttingBoardTexture;
    CS230::Texture* kitchenBackgroundTexture;
    CS230::Texture* bellTexture;
    RecipeName orderRecipe;
    std::vector<CS230::Texture*> orderRecipeTexture;
    CS230::Texture* orderUI;

    void SetSideBowl();
    void SetSideBowlRefill();

    //Draw frames
    CS230::GameObjectManager gameobjectmanager;

    //Draw refutation
    Reputation* refutation;
};