/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Greendragon.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 1, 2023
*/

#include "Greendragon.h"

Greendragon::Greendragon(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/GreenDragon.spt");
	Set_Oreder_recipe(RecipeName::StrongSoup);
}