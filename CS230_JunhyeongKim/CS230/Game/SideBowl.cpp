#include "SideBowl.h"
#include "../Engine/Engine.h"
#include "doodle/drawing.hpp"

extern bool leftClick;

SideBowl::SideBowl(Math::vec2 pos, std::string cost) : position(pos), cost(cost)
{
	texture = Engine::GetTextureManager().Load("Assets/SideBowl.png");
}

void SideBowl::Draw()
{
	texture->Draw(Math::TranslationMatrix(position));
	DrawCost();
	DrawCost();
}

bool SideBowl::MouseOn(Math::vec2 mouse)
{
	//doodle::draw_rectangle(position.x, position.y, texture->GetSize().x, texture->GetSize().y);
	if (position.x <= mouse.x && position.x + texture->GetSize().x >= mouse.x &&
		position.y <= mouse.y && position.y + texture->GetSize().y >= mouse.y)
	{
		return true;
	}
	return false;
}

void SideBowl::ReduceNum(int num)
{
	if (number > 0)
	{
		--number;
	}
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
		doodle::draw_text(cost, position.x+ 10, position.y);
		doodle::pop_settings();
	}
	else
	{
		//doodle::draw_text(std::to_string(number), position.x + 10, position.y);
	}
}

void SideBowl::DrawButton()
{
	if (Refill())
	{
		doodle::push_settings();
		doodle::draw_ellipse(position.x + texture->GetSize().x / 2, position.y + texture->GetSize().y / 1.2, texture->GetSize().x / 0.7, texture->GetSize().y / 0.2);
		doodle::pop_settings();
	}
	else
	{
		doodle::draw_text(std::to_string(number), position.x + 10, position.y);
	}
}