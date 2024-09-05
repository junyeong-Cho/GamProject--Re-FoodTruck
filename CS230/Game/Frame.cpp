/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Frame.cpp
Project:    GAM150
Author:     Junyeong cho
Created:    March 8, 2023
Updated:    May  28, 2023
*/

#include "Frame.h"
#include "../Engine/Engine.h"

Frame::Frame(Math::vec2 position, int size) : CS230::GameObject(position)
{
    switch (size)
    {
    case 1:
        sprite.Load("Assets/MainFrame.spt");
        break;
    case 2:
        sprite.Load("Assets/MoneyFrame.spt");
        break;
    default:
        break;
    }
}
