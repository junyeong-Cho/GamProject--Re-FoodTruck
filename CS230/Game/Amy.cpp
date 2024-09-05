/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Amy.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#include "Amy.h"
#include "RecipeName.h"


Amy::Amy(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/Amy.spt");

	Set_Oreder_recipe(RecipeName::AntSoup);
	Set_Ingredient_num(6);
}