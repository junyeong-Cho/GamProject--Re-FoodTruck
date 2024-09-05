/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Fireman.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    May 24, 2023
*/

#include "Fireman.h"

Fireman::Fireman(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/FireMan.spt");
	Set_Oreder_recipe(RecipeName::MermaidScalesSalad);
	Set_Ingredient_num(8);
}