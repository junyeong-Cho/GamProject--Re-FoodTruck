/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Ending.cpp
Project:    Gam150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "..\Engine\Engine.h"
#include "Ending.h"
#include "doodle/drawing.hpp"
#include "States.h"

Ending::Ending()
{

}

void Ending::Load()
{
}

void Ending::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFF);
	doodle::draw_text("Your Money: " + std::to_string(Engine::GetUnloadManager().GetMoney()), (Engine::GetWindow().GetSize().x / 1400.0) * 350, (Engine::GetWindow().GetSize().y / 800.0) * 450);
	doodle::draw_text("Thank you for playing \n play test!", (Engine::GetWindow().GetSize().x / 1400.0) * 350, (Engine::GetWindow().GetSize().y / 800.0) * 350);
}

void Ending::Update(double dt)
{
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Main_menu));
		//Engine::GetGameStateManager().ClearNextGameState();
	}
}

void Ending::Unload()
{

}