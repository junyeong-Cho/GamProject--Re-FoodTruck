/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Day_end.h
Project:    GAM150
Author:     Junhyeong Kim
Created:    May 7, 2023
*/
#pragma once
#include "..\Engine\GameState.h"
#include "../Game/Counter_Background.h"

class Day_end : public CS230::GameState
{
public:
	Day_end();
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	void Unload() override;
	void Clear();

	std::string GetName() override { return "Day_end"; }

private:
	Counter_Background background;
};