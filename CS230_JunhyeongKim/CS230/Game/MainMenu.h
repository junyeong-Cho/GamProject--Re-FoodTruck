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
//#include "../Game/Background.h"

#include "../Engine/GameObjectManager.h"
#include "../Engine/TextureManager.h"

#include "../Engine/Texture.h"
//#include "../Engine/Font.h"

#include "../Engine/GameState.h"
#include "../Engine/Sprite.h"

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

	int counter = 0;

};

