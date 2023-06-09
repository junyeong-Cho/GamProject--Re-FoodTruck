/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Credit.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    May 26, 2023
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
