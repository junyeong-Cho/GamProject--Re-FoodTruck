#pragma once
/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Ending.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    May 7, 2023
*/
#include "..\Engine\GameState.h"

class Ending : public CS230::GameState
{
public:
	Ending();
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	void Unload() override;
	void Clear();

	std::string GetName() override { return "Ending"; }
};