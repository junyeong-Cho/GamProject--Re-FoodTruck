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

#pragma once

#include "../Engine/GameObject.h"


class Frame : public CS230::GameObject
{
public:
    Frame(Math::vec2 position, int size);
};