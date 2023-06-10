/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  RecipeName.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 20, 2023
*/
#pragma once
enum class RecipeName
{
	LemonSalad, //0
	SaltSalad, //1
	LeafSalad, //2
	AntSalad, //3
	DragonFruitSalad, //4
	MermaidScalesSalad, //5
	WaterSoup, //6
	AntSoup, //7
	StrongSoup //8
};

inline RecipeName& operator+=(RecipeName& name, int value)
{
	if (value > 0)
	{
		name = (name == RecipeName::StrongSoup) ? RecipeName::StrongSoup : RecipeName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == RecipeName::LemonSalad) ? RecipeName::LemonSalad : RecipeName(static_cast<int>(name) + value);
	}
	return name;
}