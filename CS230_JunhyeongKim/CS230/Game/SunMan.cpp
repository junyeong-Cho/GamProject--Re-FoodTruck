/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SunMan.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#include "SunMan.h"
#include "RecipeName.h"


SunMan::SunMan(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/SunMan.spt");
	Set_Oreder_recipe(RecipeName::LemonSalad);
	Set_Ingredient_num(6);
}