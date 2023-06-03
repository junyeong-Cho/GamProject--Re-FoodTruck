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

#include "Refutation.h"
#include "Customer.h"
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
    void Draw_RecipeBook();
    void Draw_Order();
    void Draw_CounterButton();
    void Draw_Bell();
    void Draw_CuttingBoard();
	void Draw_PaltingSpot();
    void Draw_Frame_Text();


private:
    bool canLoad = true;
    bool canUnload = false;
    Cook cook;
    RecipeBook recipeBook;
    Button go_counter;
    std::vector<SideBowl> sideBowl;
    CS230::Texture* cuttingBoardTexture;
    CS230::Texture* kitchenBackgroundTexture;
    CS230::Texture* bellTexture;

    void SetSideBowl();
    void SetSideBowlRefill();

    //Draw frames
    CS230::GameObjectManager gameobjectmanager;

    //Draw refutation
    Refutation* refutation;
};