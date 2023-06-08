/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Giraffe.cpp
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    March 3, 2023
*/

#include "Giraffe.h"
#include "RecipeName.h"

Giraffe::Giraffe(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/giraffe.spt");

	Set_Oreder_recipe(RecipeName::LeafSalad);
	Set_Ingredient_num(6);
}