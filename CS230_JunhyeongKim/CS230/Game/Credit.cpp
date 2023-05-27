/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Credit.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    May 26, 2023
*/
#include "Main_menu.h"
#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "States.h"
#include "Credit.h"

Credit::Credit() : creditNum(0), state(true), buttonCheck(true), nextButton(600, 200, 250, 100)
{

}

void Credit::Load()
{
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit1.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit2.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit3.png"));
	credits.push_back(Engine::GetTextureManager().Load("Assets/Credit4.png"));
}

void Credit::Update(double dt)
{
	buttonCheck = false;

	Engine::GetWindow().Clear(0x000000FF);
	nextButton.update(doodle::get_mouse_x(), doodle::get_mouse_y());

	//state = true;

	if ((nextButton.checkMouse) && (buttonCheck == false))
	{
		creditNum += 1;
		buttonCheck = true;
	}

	if (creditNum == 4)
	{
		state = false;
		creditNum = 0;
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Splash));
	}
}

void Credit::Draw()
{
	if ((creditNum < 4))
	{
		credits[creditNum]->Draw(Math::TranslationMatrix({ (Engine::GetWindow().GetSize() - credits[creditNum]->GetSize()) / 2.0 }));
	}

	nextButton.draw("Next");
}

void Credit::Unload()
{
	credits.clear();
}
