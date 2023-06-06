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

#include "../Game/Sound.h"

#include "MainMenu.h"




MainMenu::MainMenu()
{

}

void MainMenu::Load()
{
	//UpdateMenuTextColors();
	//music_effect_main;

	AddGSComponent(new CS230::MusicEffect());

	GetGSComponent<CS230::MusicEffect>()->LoadFile("Assets/Sound/Theme/main_theme_pirot.ogg");
	GetGSComponent<CS230::MusicEffect>()->LoadFile("Assets/Sound/Theme/kitchen_theme.ogg");

	mainmenu_background = Engine::GetTextureManager().Load("Assets/MainmenuBackground.png");


}


void MainMenu::UpdateMenuTextColors()
{
	colors[counter] = 0xFF5733FF;
	for (int i = 0; i < 3; ++i)
	{
		if (counter != i)
		{
			colors[i] = 0xFFDF77FF;
		}
	}
	shouldUpdateColors = false;
}


void MainMenu::DrawText()
{
	/*
	doodle::push_settings();

	doodle::draw_text("Re:Truck", (Engine::GetWindow().GetSize().x / 2 - 200), (Engine::GetWindow().GetSize().y - 100));

	doodle::pop_settings();
	*/


	doodle::push_settings();
	doodle::set_outline_color(doodle::HexColor(colors[0]));
	doodle::draw_text("Start", (Engine::GetWindow().GetSize().x / 2 - Engine::GetWindow().GetSize().x / 11.0), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.75));
	doodle::pop_settings();


	doodle::push_settings();
	doodle::set_outline_color(doodle::HexColor(colors[1]));
	doodle::draw_text("Credit", (Engine::GetWindow().GetSize().x / 2 - Engine::GetWindow().GetSize().x / 11.0), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.43));
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_outline_color(doodle::HexColor(colors[2]));
	doodle::draw_text("Exit", (Engine::GetWindow().GetSize().x / 2 - Engine::GetWindow().GetSize().x / 11.0), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.20));
	doodle::pop_settings();
}


void MainMenu::Update(double dt)
{
	GetGSComponent<CS230::MusicEffect>()->Play(0);

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
			GetGSComponent<CS230::MusicEffect>()->Stop();
			break;

		case 1:
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Credit));
			break;

		case 2:
			Engine::GetGameStateManager().ClearNextGameState();
			break;
		
		}
	}
}

void MainMenu::Unload()
{

}

void MainMenu::Draw()
{
	Engine::GetWindow().Clear(0x000000FF);

	double scale_x = Engine::GetWindow().GetSize().x / static_cast<double>(mainmenu_background->GetSize().x);
	double scale_y = Engine::GetWindow().GetSize().y / static_cast<double>(mainmenu_background->GetSize().y);

	mainmenu_background->Draw(Math::TransformationMatrix() * Math::ScaleMatrix({ scale_x, scale_y }));


	DrawText();


}

void MainMenu::Clear()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
}


