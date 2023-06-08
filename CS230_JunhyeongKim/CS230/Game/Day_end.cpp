/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Day_end.cpp
Project:    Gam150
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

	doodle::draw_text(std::to_string(Engine::GetUnloadManager().GetMoney()), (Engine::GetWindow().GetSize().x / 1400.0) * 350, (Engine::GetWindow().GetSize().y / 800.0) * 450);
	std::string Day = std::to_string(Engine::GetUnloadManager().GetDay());
	doodle::draw_text(Day, (Engine::GetWindow().GetSize().x / 1400.0) * 350, (Engine::GetWindow().GetSize().y / 800.0) * 350);
}

void Day_end::Update(double dt)
{
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Counter));
		//Engine::GetGameStateManager().ClearNextGameState();
	}
}

void Day_end::Unload()
{
	background.Unload();
}