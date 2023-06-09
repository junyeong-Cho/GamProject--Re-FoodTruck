/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  DrawManager.cpp
Project:    GAM150
Author:     Yeaseul Lim
Created:    June  6, 2023
*/

#include "DrawManager.h"
#include <math.h>

void CS230::DrawManager::Update(const Math::ivec2& windowSize)
{
	unit.x = (double)windowSize.x / windowRate.x;
	unit.y = (double)windowSize.y / windowRate.y;
}

Math::TransformationMatrix CS230::DrawManager::GetMatrix(CS230::Texture* texture, const Math::vec2& pos, const Math::vec2& size)
{
	Math::TranslationMatrix position{ Vec(pos)};

	double scaleX = Vec(size).x * 1 / (double)texture->GetSize().x ;
	double scaleY = Vec(size).y * 1 / (double)texture->GetSize().y;
	Math::ScaleMatrix scale{ Math::vec2{scaleX, scaleY} };

	return position * scale;
}

bool CS230::DrawManager::RectCollision(const Math::vec2& pos, const Math::vec2& size, const Math::vec2& mouse)
{
	if (Vec(pos).x <= mouse.x && Vec(pos).x + Vec(size).x >= mouse.x &&
		Vec(pos).y <= mouse.y && Vec(pos).y + Vec(size).y >= mouse.y)
	{
		return true;
	}
	return false;
}

bool CS230::DrawManager::CircleCollision(const Math::vec2& pos, const Math::vec2& size, const Math::vec2& mouse)
{
	if (std::sqrt((std::pow((mouse.x - Vec(pos).x), 2) + (std::pow((mouse.y - Vec(pos).y), 2)))) <= Vec(size).x)
	{
		return true;
	}
	return false;
}

Math::vec2 CS230::DrawManager::Vec(const Math::vec2& vec)
{
	return Math::vec2{ vec.x * unit.x, vec.y * unit.y };
}