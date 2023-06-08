/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Tutorial.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    May 26, 2023
*/

#pragma once
#include "../Engine/GameState.h"
#include "../Engine/Sprite.h"
#include "Button.h"

class Tutorial : public CS230::GameState
{
public:
    Tutorial();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;


    std::string GetName() override { return "Tutorial"; }

private:
    //Check which picture printed
    int tutorialNum;

    //Check how many pictures are there
    short maxNum = 4;

    //Contain the images which is allocated with creid
    std::vector< CS230::Texture*> tutorials;



};