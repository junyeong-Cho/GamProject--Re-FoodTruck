#include "Button.h"

//Draw
void Button::draw(const int mouse_x, const int mouse_y)
{

	doodle::push_settings();
	
	//mouse on button
	if ((mouse_x > x && mouse_x < x + width) && (mouse_y > y && mouse_y < y + height))
	{
		alpha = 100;
	}
	else
	{
		alpha = 255;
	}
	
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	doodle::set_rectangle_mode(doodle::RectMode::Corner);
	doodle::set_fill_color(255, 100, 100, alpha);
	doodle::draw_rectangle(x, y, width, height);
	doodle::pop_settings();
}

void Button::draw(const int mouse_x, const int mouse_y , std::string text)
{
	doodle::push_settings();

	//mouse on button
	if ((mouse_x > x && mouse_x < x + width) && (mouse_y > y && mouse_y < y + height))
	{
		alpha = 100;
	}
	else
	{
		alpha = 255;
	}

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	doodle::set_rectangle_mode(doodle::RectMode::Corner);
	doodle::set_fill_color(255, 100, 100 , alpha);
	doodle::draw_rectangle(x, y, width, height);
	doodle::set_fill_color(0,alpha);
	doodle::draw_text(text,x + width/3, y + height/4);
	doodle::pop_settings();
}


void Button::check_click(const int mouse_x, const int mouse_y, State next_state)
{

	if ((mouse_x > x && mouse_x < x + width) && (mouse_y > y && mouse_y < y + height))
	{
		if (doodle::MouseIsPressed == true)
		{
			checkMouse = true;
		}
	}
	else
	{
		checkMouse = false;
	}

	if (doodle::MouseIsPressed == false && checkMouse == true)
	{
		checkMouse = false;
		*current_state = next_state;
	}

}


void Button::update(const int mouse_x, const int mouse_y, State next_state)
{

	draw(mouse_x, mouse_y);
	check_click(mouse_x, mouse_y, next_state);
}

void Button::update(const int mouse_x, const int mouse_y, State next_state, std::string text)
{
	draw(mouse_x, mouse_y, text);
	check_click(mouse_x, mouse_y, next_state);
}