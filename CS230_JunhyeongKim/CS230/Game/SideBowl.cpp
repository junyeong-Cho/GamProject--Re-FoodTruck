/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SideBowl.cpp
Project:    GAM150
Author:     Yeaseul Lim
Created:    May 23, 2023
Upeated:    June 2, 2023
*/
#include "SideBowl.h"
#include "../Engine/Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/environment.hpp"

extern bool leftClick;

SideBowl::SideBowl(Math::vec2 pos, std::string cost) : position(pos), cost(cost)
{
	
}

void SideBowl::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/SideBowl.png");
}

void SideBowl::Draw()
{
	texture->Draw(Math::TranslationMatrix(position));
	DrawCost();
	DrawButton();
	DrawRemainingNum();
}

bool SideBowl::MouseOn(Math::vec2 mouse)
{
	if (position.x <= mouse.x && position.x + texture->GetSize().x >= mouse.x &&
		position.y <= mouse.y && position.y + texture->GetSize().y >= mouse.y)
	{
		return true;
	}
	return false;
}

bool SideBowl::Refill()
{
	if (number == 0)
	{
		return true;
	}
	return false;
}

void SideBowl::DrawCost()
{
	if (Refill())
	{
		doodle::push_settings();
		doodle::set_font_size(20);
		doodle::draw_text("$" + cost, position.x + texture->GetSize().x / 2.7, position.y + texture->GetSize().y / 4.0);
		doodle::pop_settings();
	}
	
}

void SideBowl::DrawRemainingNum()
{
	doodle::push_settings();
	doodle::set_font_size(20);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::draw_text(std::to_string(number), position.x + texture->GetSize().x / 1.9, position.y + texture->GetSize().y/1.05);
	doodle::pop_settings();
}

void SideBowl::Update(double dt)
{
	timer += dt;
	if (timer < 0.5)
	{
		changeColor = false;
	}
	else if(timer >= 0.5 && timer < 1)
	{
		changeColor = true;
	}
	else if(timer >= 1)
	{
		timer = 0;
	}

}

void SideBowl::DrawButton()
{
	if (Refill())
	{
		doodle::Color red = doodle::Color(255, 0, 0);
		doodle::Color white = doodle::Color(255, 255, 255);
		doodle::Color now = red;
		doodle::push_settings();
		if (changeColor == true)
		{
			now = red;
		}
		else
		{
			now = white;
		}
		doodle::set_fill_color(now);
		doodle::draw_ellipse(position.x + texture->GetSize().x / 2, position.y + texture->GetSize().y / 1.6, texture->GetSize().x * 0.7, texture->GetSize().y * 0.2);
		doodle::pop_settings();

		doodle::push_settings();
		doodle::set_font_size(13);
		doodle::set_fill_color(doodle::Color(0, 0, 0));
		doodle::draw_text("Click!", position.x + texture->GetSize().x / 3, position.y + texture->GetSize().y / 1.8);
		doodle::pop_settings();
	}
}