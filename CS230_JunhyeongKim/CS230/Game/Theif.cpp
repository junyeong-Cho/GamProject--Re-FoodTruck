/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Theif.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#include "Theif.h"
#include "RecipeName.h"


Theif::Theif(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/Theif.spt");
	Set_Oreder_recipe(RecipeName::WaterSoup);
	Set_Ingredient_num(3);
}