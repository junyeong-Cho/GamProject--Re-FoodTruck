/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  IngredientName.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 10, 2023
*/
#pragma once
enum class IngredientName
{
	Lemon,
	Lettuce,
	Ant,
	Leaf,
	Salt,
	DragonFruit,
	MermaidScales,
	Water,
	Nothing
};

inline IngredientName& operator+=(IngredientName& name, int value)
{
	if (name == IngredientName::Nothing)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == IngredientName::Water) ? IngredientName::Lemon : IngredientName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == IngredientName::Lemon) ? IngredientName::Water : IngredientName(static_cast<int>(name) + value);
	}
	return name;
}