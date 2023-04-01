//file name : Button.cpp
#include "Button.h"

//Draw
void Button::draw(const int mouse_x, const int mouse_y)
{
    doodle::push_settings();
    //mouse on button
    if ((mouse_x > x && mouse_x < x + width) && (mouse_y > y && mouse_y < y + height))
    {
        doodle::set_fill_color(doodle::HexColor{ 0x7E5873FF });
    }
    else
    {
        doodle::set_fill_color(doodle::HexColor{ 0xFFFFFF });
    }
    doodle::draw_rectangle(x, y, width, height);
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