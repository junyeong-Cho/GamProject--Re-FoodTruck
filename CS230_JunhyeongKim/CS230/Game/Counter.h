/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter.h
Project:    Gam150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Engine/GameObjectManager.h"
#include "Button.h"

class Customor;

class Counter : public CS230::GameState
{
public:


    Counter();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    void Clear();
    void Draw_UI();

    std::string GetName() override { return "Counter"; }
private:
    //CS230::Texture* guest_image;
    //Math::vec2 guest_position;


    CS230::GameObjectManager gameobjectmanager;

    Customor* front_customor = nullptr;
    Button yes_button;
    int customors = 5;
    int last_timer = 100;

};