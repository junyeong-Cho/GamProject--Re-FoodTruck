/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Elf.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    March 3, 2023
*/

#include "Elf.h"
#include "RecipeName.h"

Elf::Elf(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/Elf.spt");

	Set_Oreder_recipe(RecipeName::DragonFruitSalad);
	Set_Ingredient_num(7);

}