/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  MainMenu.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    March 8,  2023
Updated:    May  17, 2023
*/

#include "doodle/drawing.hpp"

#include "..\Engine\Engine.h"

#include "MainMenu.h"


MainMenu::MainMenu()
{

}

void MainMenu::Load()
{
	//UpdateMenuTextColors();
}


void MainMenu::UpdateMenuTextColors()
{

	uint32_t colors[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
	colors[counter] = 0x7EFACBFF;


	doodle::set_outline_color(doodle::HexColor{ colors[counter] });




	/*
	side_scroller = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("Side Scroller", colors[0]);
	Space_shotter = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("Space Shotter", colors[1]);
	exit		  = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("Exit", colors[2]);
	*/
}


void MainMenu::DrawText()
{
	doodle::push_settings();

	UpdateMenuTextColors();

	doodle::set_outline_color(0, 102, 153);
	doodle::draw_text("Re:Truck", (Engine::GetWindow().GetSize().x / 2 - 200), (Engine::GetWindow().GetSize().y - 100));

	doodle::pop_settings();

	doodle::push_settings();

	doodle::set_outline_color(0, 102, 153);
	doodle::draw_text("Start", (Engine::GetWindow().GetSize().x / 2 - 200), (Engine::GetWindow().GetSize().y - 300));

	doodle::pop_settings();

	doodle::push_settings();

	doodle::set_outline_color(0, 102, 153);
	doodle::draw_text("Exit", (Engine::GetWindow().GetSize().x / 2 - 200), (Engine::GetWindow().GetSize().y - 400));

	doodle::pop_settings();

	doodle::push_settings();


	doodle::set_outline_color(0, 102, 153);
	doodle::draw_text("Credit", (Engine::GetWindow().GetSize().x / 2 - 200), (Engine::GetWindow().GetSize().y - 500));

	doodle::pop_settings();
}


void MainMenu::Update(double dt)
{
	bool shouldUpdateColors = false;

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Down))
	{
		counter = (counter + 1) % 3;
		shouldUpdateColors = true;
	}
	else if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Up))
	{
		counter = (counter - 1 + 3) % 3;
		shouldUpdateColors = true;
	}

	
	if (shouldUpdateColors)
	{
		UpdateMenuTextColors();
	}
	

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		switch (counter)
		{
		case 0:
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Counter));
			break;
		case 1:
			Engine::GetGameStateManager().ClearNextGameState();
			break;
		case 2:
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Splash));
			break;
		}
	}
}

void MainMenu::Unload()
{
	//Unload Mode1

	//Unload Mode2
}

void MainMenu::Draw()
{
	//Make a title that is in a third color with a nice background color or texture. 
	Engine::GetWindow().Clear(0xFFFFFFFF);

	DrawText();
}

void MainMenu::Clear()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
}


