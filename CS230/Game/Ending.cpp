/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Ending.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "..\Engine\Engine.h"
#include "Ending.h"
#include "States.h"

Ending::Ending()
{

}

void Ending::Load()
{
	if (Engine::GetUnloadManager().GetRate() >= 200 || Engine::GetUnloadManager().GetMoney() >= 70)//good
	{
		background.Add("Assets/Endings/GGEnding.png");

	}
	else if(Engine::GetUnloadManager().GetRate() >= 100 && Engine::GetUnloadManager().GetMoney() >= 30)//soso
	{
		background.Add("Assets/Endings/SoSoEnding.png");
	}
	else // bad
	{
		background.Add("Assets/Endings/BadEnding.png");
	}
}

void Ending::Draw()
{
	Clear();
	background.Draw();

}

void Ending::Update(double dt)
{
	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Main_menu));
	}
}

void Ending::Unload()
{
	Engine::GetUnloadManager().Reset();
	background.Unload();
}

void Ending::Clear()
{
	Engine::GetWindow().Clear(0xFFFFFFF);

}