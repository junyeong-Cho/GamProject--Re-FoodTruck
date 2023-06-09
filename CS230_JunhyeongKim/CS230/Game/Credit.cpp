/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Credit.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    May 26, 2023
*/
#include "MainMenu.h"
#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "States.h"
#include "Credit.h"

Credit::Credit() : creditNum(0)
{

}

void Credit::Load()
{
	creditNum = 0;
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit1.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit2.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit3.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit4.png"));
}

void Credit::Update(double dt)
{
	Engine::GetWindow().Clear(0x000000FF);


	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		creditNum += 1;
	}

	if (creditNum == maxNum)
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Splash));
	}
}

void Credit::Draw()
{
	if (creditNum < maxNum)
	{
		credits[creditNum]->Draw(Math::TranslationMatrix({ (Engine::GetWindow().GetSize() - credits[creditNum]->GetSize()) / 2.0 }));
	}
}

void Credit::Unload()
{
	credits.clear();
}
