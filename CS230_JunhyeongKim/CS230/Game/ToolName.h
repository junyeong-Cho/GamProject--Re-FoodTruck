/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  ToolName.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    April 10, 2023
*/
#pragma once
enum class ToolName
{
	HAND,
	KNIFE,
	LADLE,
	SCOOP,
	TRASHCAN,
	Nothing
};

inline ToolName& operator+=(ToolName& name, int value)
{
	if (name == ToolName::Nothing)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == ToolName::TRASHCAN) ? ToolName::HAND : ToolName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == ToolName::HAND) ? ToolName::TRASHCAN : ToolName(static_cast<int>(name) + value);
	}
	return name;
}