#include "SaleItem.h"
#include "doodle/drawing.hpp"
#include <iostream>

bool SaleItem::IsMouseOn(Math::vec2 mousePos)
{
	if(position.x <= 200)
	{
		return true;
	}
	return false;
}

void Apple::DrawImage()
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	
	doodle::set_fill_color(0, 128, 0);
	
	doodle::draw_quad(position.x - spriteHalfWidth, position.y + spriteHalfWidth,
		              position.x + spriteHalfWidth, position.y + spriteHalfWidth,
		              position.x + spriteHalfWidth, position.y - spriteHalfWidth,
		              position.x - spriteHalfWidth, position.y - spriteHalfWidth);
	

	doodle::set_outline_color(0, 102, 153);
	doodle::set_fill_color(255);
	doodle::draw_text("Apple: " + std::to_string(itemNum), 200, 200);
	
	doodle::pop_settings();
}

void Apple::GetName()
{
	std::cout << "Apple: " << std::endl;
}

void Pizza::DrawImage()
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	doodle::set_outline_color(0, 102, 153);
	doodle::set_fill_color(255);
	
	
	doodle::set_fill_color(255, 128, 0);
	doodle::draw_quad(position.x - spriteHalfWidth, position.y + spriteHalfWidth,
					  position.x + spriteHalfWidth, position.y + spriteHalfWidth,
		              position.x + spriteHalfWidth, position.y - spriteHalfWidth,
		              position.x - spriteHalfWidth, position.y - spriteHalfWidth);
	
	doodle::draw_text("Pizza: " + std::to_string(itemNum), 250, 300);
	

	doodle::pop_settings();
}

void Pizza::GetName()
{
	std::cout << "Pizza: " << std::endl;
}

void Chicken::DrawImage()
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	
	doodle::set_fill_color(255, 255, 0);
	doodle::draw_quad(position.x - spriteHalfWidth, position.y + spriteHalfWidth,
		              position.x + spriteHalfWidth, position.y + spriteHalfWidth,
		              position.x + spriteHalfWidth, position.y - spriteHalfWidth,
		              position.x - spriteHalfWidth, position.y - spriteHalfWidth);
	

	doodle::set_outline_color(0, 102, 153);
	doodle::set_fill_color(255);
	//doodle::draw_text("Wow! Wow WOw!", 300, 400);
	doodle::draw_text("Chicken: " + std::to_string(itemNum), 300, 400);
	doodle::pop_settings();
}

void Chicken::GetName()
{
	std::cout << "Chicken: " << std::endl;
}

void SaleItem::ChangePos(Math::vec2 pos)
{
	position = pos;
}





