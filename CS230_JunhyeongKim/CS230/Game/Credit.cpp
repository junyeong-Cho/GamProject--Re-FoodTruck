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

Credit::Credit() : creditNum(0), state(true)
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
	Engine::GetWindow().Clear(0x000000FF);

	//state = true;

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		creditNum += 1;
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
	

	/*
	doodle::push_settings();

	doodle::set_outline_color(255);
	doodle::set_fill_color(0);
	doodle::draw_text("Press Enter for the next credit!", Engine::GetWindow().GetSize().x / 2.0 - Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 2.0 - Engine::GetWindow().GetSize().y / 1.9);

	doodle::pop_settings();
	*/
}

void Credit::Unload()
{
	credits.clear();
}
