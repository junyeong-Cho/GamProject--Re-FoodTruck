/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Tutorial.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    May 26, 2023
Updated:    June 9, 2023
*/

#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "States.h"
#include "Tutorial.h"

Tutorial::Tutorial() : tutorialNum(0)
{

}

void Tutorial::Load()
{
	tutorialNum = 0;
	
	//Push back the images at here!
	tutorials.push_back(Engine::GetTextureManager().Load("Assets/Tutorial1.jpg"));
	tutorials.push_back(Engine::GetTextureManager().Load("Assets/Tutorial2.jpg"));
	tutorials.push_back(Engine::GetTextureManager().Load("Assets/Tutorial3.jpg"));
	tutorials.push_back(Engine::GetTextureManager().Load("Assets/Tutorial4.jpg"));

}

void Tutorial::Update(double dt)
{
	Engine::GetWindow().Clear(0x000000FF);



	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Enter))
	{
		tutorialNum += 1;
	}

	if (tutorialNum == maxNum)
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Main_menu));
	}
}

void Tutorial::Draw()
{
	if (tutorialNum < maxNum)
	{
		tutorials[tutorialNum]->Draw(Math::TranslationMatrix({ (Engine::GetWindow().GetSize() - tutorials[tutorialNum]->GetSize()) / 2.0 }));
	}
}

void Tutorial::Unload()
{
	tutorials.clear();
}
