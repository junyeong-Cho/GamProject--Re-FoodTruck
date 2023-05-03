/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Main_menu.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Sprite.h"
#include "Button.h"

class Main_menu : public CS230::GameState
{
public:
    Main_menu();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    void Clear();


    std::string GetName() override { return "Main_menu"; }

private:
    Button main_button;
};