/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Day_end.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "..\Engine\Engine.h"
#include "Day_end.h"
#include "doodle/drawing.hpp"
#include "States.h"

Day_end::Day_end()
{

}

void Day_end::Load()
{
	if (Engine::GetUnloadManager().GetDay() == 1)
	{
		background.Add("Assets/Dates/Day1EndScreen.png");

	}
	else if (Engine::GetUnloadManager().GetDay() == 2)
	{
		background.Add("Assets/Dates/Day1EndScreen.png");
	}
	else if (Engine::GetUnloadManager().GetDay() == 3)
	{
		background.Add("Assets/Dates/Day2EndScreen.png");
	}
	else
	{
		background.Add("Assets/Dates/Day3EndScreen.png");
	}
}

void Day_end::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFF);
	
	background.Draw();

	doodle::draw_text(std::to_string(Engine::GetUnloadManager().GetMoney()), (Engine::GetWindow().GetSize().x / 1400.0) * 750, (Engine::GetWindow().GetSize().y / 800.0) * 375);
	std::string Refutation = std::to_string(Engine::GetUnloadManager().GetRate());
	doodle::draw_text(Refutation, (Engine::GetWindow().GetSize().x / 1400.0) * 760, (Engine::GetWindow().GetSize().y / 800.0) * 150);
}

void Day_end::Update(double dt)
{
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Counter));
	}
}

void Day_end::Unload()
{
	background.Unload();
}