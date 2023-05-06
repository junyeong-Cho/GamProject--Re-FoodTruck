/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Main_menu.cpp
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "Main_menu.h"
#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "States.h"

Main_menu::Main_menu()
	:main_button(600, 200, 250, 100)
{}

void Main_menu::Load()
{

}

void Main_menu::Update(double dt)
{
	main_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Counter);
}

void Main_menu::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	doodle::draw_text("Re:Truck", Engine::GetWindow().GetSize().x / 2.0 - Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 12.0);
	main_button.draw("Play");
}

void Main_menu::Clear()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
}

void Main_menu::Unload()
{

}