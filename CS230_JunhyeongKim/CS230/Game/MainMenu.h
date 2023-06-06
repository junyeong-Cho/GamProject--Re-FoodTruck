/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  MainMenu.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    March 8,  2023
Updated:    May  17, 2023
*/


#pragma once

#include "../Game/States.h"

//#include "../Engine/SoundComponentManager.h"
#include "../Engine/GameObjectManager.h"
#include "../Engine/TextureManager.h"
#include "../Engine/Texture.h"
#include "../Engine/GameState.h"
#include "../Engine/Sprite.h"

#include "../Engine/ComponentManager.h"
#include "../Engine/GameObject.h"
#include "..\Engine\Engine.h"



class MainMenu : public CS230::GameState
{
public:
	MainMenu();

	void Load()				override;
	void Update(double dt)  override;
	void Unload()	        override;
	void Draw()				override;
	void Clear();
	void DrawText();



	std::string GetName() override { return "MainMenu"; }

	void UpdateMenuTextColors();

private:
	//Background background;

	std::string main_title;
	std::string side_scroller;
	std::string Space_shotter;
	std::string exit;

	CS230::Texture* mainmenu_background;


	//CS230::MusicEffect music_effect_main = CS230::MusicEffect("Assets/Sound/Theme/main_theme_pirot.ogg");


	int counter = 0;

	uint32_t colors[4] = { 0xFF5733FF, 0xFFDF77FF, 0xFFDF77FF, 0xFFDF77FF };
	bool shouldUpdateColors = false;
};

