/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SideBowl.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    May 23, 2023
Upeated:    June 2, 2023
*/
#pragma once
#include "../Engine/vec2.h"
#include "../Engine/Texture.h"
class SideBowl
{
public:
	SideBowl(Math::vec2 pos, std::string cost);
	void Draw();
	void Update(double dt);
	bool MouseOn(Math::vec2 mouse);
	bool Refill();
	void DrawCost();
	void DrawButton();
	void SetBowlNum(int num) { number = num; }
	void DrawRemainingNum();
	void Load();

private:
	Math::vec2 position;
	CS230::Texture* texture;
	std::string cost;
	int number = 3;
	bool changeColor = true;
	double timer = 0;
};