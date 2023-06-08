/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Zilien.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 1, 2023
*/

#include "Zilien.h"

Zilien::Zilien(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/ZilienNormal.spt");

	Set_Oreder_recipe(RecipeName::SaltSalad);
	Set_Ingredient_num(4);
}