#include "Ingredient.h"
#include "doodle/drawing.hpp"
#include <iostream>

void Lettuce::DrawImage()
{
	doodle::push_settings();
	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_fill_color(0, 128, 0);
	doodle::draw_quad(position.x - spriteHalfWidth, position.y + spriteHalfWidth,
		position.x + spriteHalfWidth, position.y + spriteHalfWidth,
		position.x + spriteHalfWidth, position.y - spriteHalfWidth,
		position.x - spriteHalfWidth, position.y - spriteHalfWidth);
	doodle::pop_settings();
}

void Sauce::DrawImage()
{
	doodle::push_settings();
	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_fill_color(255, 255, 0);
	doodle::draw_quad(position.x - spriteHalfWidth, position.y + spriteHalfWidth,
		position.x + spriteHalfWidth, position.y + spriteHalfWidth,
		position.x + spriteHalfWidth, position.y - spriteHalfWidth,
		position.x - spriteHalfWidth, position.y - spriteHalfWidth);
	doodle::pop_settings();
}

void Ingredient::ChangePos(Math::vec2 pos)
{
	position = pos;
}

bool Ingredient::IsMouseOn(Math::vec2 mousePos)
{
	if (position.x - spriteHalfWidth < mousePos.x && position.x + spriteHalfWidth > mousePos.x
		&& position.y - spriteHalfWidth < mousePos.y && position.y + spriteHalfWidth > mousePos.y)
	{
		return true;
	}
	return false;
}
