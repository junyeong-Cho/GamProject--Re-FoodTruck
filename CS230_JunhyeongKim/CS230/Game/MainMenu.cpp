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
	for (int i = 0; i < 4; ++i)
	{
		if (counter != i)
		{
			//colors[i] = 0xFFDF77FF;
			colors[i] = 0xFFFFFFFF;
		}
	}
	shouldUpdateColors = false;
}


void MainMenu::DrawText()
{
	
	/*for (int i = 0; i < 4; ++i)
	{
		doodle::push_settings();
		if (i == counter)
		{
			doodle::set_fill_color(doodle::Color(255, 113, 119, 50));
		}
		else
		{
			doodle::set_fill_color(doodle::Color(255,223,119,30));
		}
		doodle::set_outline_color(doodle::Color(255, 255, 255));
		doodle::draw_ellipse(buttonCircleX[i], 320.0, 260.0);
		doodle::pop_settings();
	}*/

	doodle::push_settings();
	doodle::set_fill_color(doodle::Color(255, 113, 119, 50));
	doodle::set_outline_color(doodle::Color(255, 255, 255));
	doodle::draw_ellipse(buttonCircleX[counter], 320.0, 260.0);
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_outline_color(doodle::Color(0,0,0));
	doodle::set_fill_color(doodle::HexColor(colors[0]));
	doodle::draw_text("Start", (Engine::GetWindow().GetSize().x / 2 - Engine::GetWindow().GetSize().x / 3.0), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.5));
	doodle::pop_settings();


	doodle::push_settings();
	doodle::set_outline_color(doodle::Color(0, 0, 0));
	doodle::set_fill_color(doodle::HexColor(colors[1]));
	doodle::draw_text("How\n  to\nplay", (Engine::GetWindow().GetSize().x / 2 - Engine::GetWindow().GetSize().x / 6.5), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.65) + 22.0);
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_outline_color(doodle::Color(0, 0, 0));
	doodle::set_fill_color(doodle::HexColor(colors[2]));
	doodle::draw_text("Credit", (Engine::GetWindow().GetSize().x / 2 ), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.5));
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_outline_color(doodle::Color(0, 0, 0));
	doodle::set_fill_color(doodle::HexColor(colors[3]));
	doodle::draw_text("Exit", (Engine::GetWindow().GetSize().x / 2 + Engine::GetWindow().GetSize().x / 5.0), (Engine::GetWindow().GetSize().y - Engine::GetWindow().GetSize().y / 1.5));
	doodle::pop_settings();
}


void MainMenu::Update(double dt)
{
	GetGSComponent<CS230::MusicEffect>()->Play(0);

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Right))
	{
		counter = (counter + 1) % 4;
		shouldUpdateColors = true;
	}
	else if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Left))
	{
		counter = (counter - 1 + 4) % 4;
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
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Tutorial));
			break;

		case 2:
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Credit));
			break;

		case 3:
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


