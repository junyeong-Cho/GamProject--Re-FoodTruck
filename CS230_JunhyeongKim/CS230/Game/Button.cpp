#include "Button.h"
#include "../Engine/Engine.h"
#include "States.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"

Button::Button(double tempX, double tempY, double tempWidth, double tempHeight)
    : x(tempX), y(tempY), width(tempWidth), height(tempHeight), Width_raito(Engine::GetWindow().GetSize().x / 1400.0), Height_raito(Engine::GetWindow().GetSize().y / 800.0)
{
};

//Draw
void Button::draw()
{

    doodle::push_settings();

    //mouse on button
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height))
    {
        alpha = 100;
    }
    else
    {
        alpha = 255;
    }

    doodle::set_rectangle_mode(doodle::RectMode::Corner);
    doodle::set_fill_color(255, 100, 100, alpha);
    doodle::draw_rectangle(Width_raito * x, Height_raito * y, Width_raito * width, Height_raito * height);
    doodle::pop_settings();

    DrawLoading();
}



void Button::draw(std::string text)
{
    doodle::push_settings();

    //mouse on button
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height))
    {
        alpha = 100;
    }
    else
    {
        alpha = 255;
    }

    doodle::set_rectangle_mode(doodle::RectMode::Corner);
    doodle::set_fill_color(255, 100, 100, alpha);
    doodle::draw_rectangle(Width_raito * x, Height_raito * y, Width_raito * width, Height_raito * height);
    doodle::set_fill_color(0, alpha);
    doodle::set_font_size(Width_raito * (width / 7.0));
    doodle::draw_text(text, Width_raito * (x + width / text.size()), Height_raito * (y + height / 4));
    doodle::pop_settings();

    DrawLoading();
}

void Button::text_draw(std::string text)
{
    doodle::push_settings();

    //mouse on button
    if ((mouseX > x && mouseX < x + width) && (mouseY > y && mouseY < y + height))
    {
        alpha = 100;
    }
    else
    {
        alpha = 255;
    }

    doodle::set_fill_color(0, alpha);
    doodle::set_font_size(Width_raito * (width / 7.0));
    doodle::draw_text(text, Width_raito * (x + width / 3), Height_raito * (y + height / 4));
    doodle::pop_settings();
}


void Button::check_click(States next_state)
{

    if ((mouseX > x * Width_raito && mouseX < (x + width) * Width_raito) && (mouseY > y * Height_raito && mouseY < (y + height) * Height_raito))
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
        if (next_state == States::Kitchen)
        {
            canLoadingText = true;
        }
        else
        {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(next_state));
        }
    }

}

void Button::DrawLoading()
{
    if (canLoadingText == true)
    {
        doodle::push_settings();
        doodle::set_font_size(120.0);
        doodle::draw_text("Loading...", 300.0, 300.0);
        doodle::pop_settings();
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Kitchen));
        canLoadingText = false;
    }
}

void Button::check_click()
{

    if ((mouseX > x * Width_raito && mouseX < (x + width) * Width_raito) && (mouseY > y * Height_raito && mouseY < (y + height) * Height_raito))
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
        checkClick = true;
    }

}


void Button::update(const int mouse_x, const int mouse_y, States next_state)
{
    mouseX = mouse_x;
    mouseY = mouse_y;
    check_click(next_state);
    Width_raito = Engine::GetWindow().GetSize().x / 1400.0; // 1
    Height_raito = Engine::GetWindow().GetSize().y / 800.0; //  1
}

void Button::update(const int mouse_x, const int mouse_y)
{
    mouseX = mouse_x;
    mouseY = mouse_y;
    check_click();
    Width_raito = Engine::GetWindow().GetSize().x / 1400.0; // 1
    Height_raito = Engine::GetWindow().GetSize().y / 800.0; //  1
}