/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter.cpp
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "States.h"
#include "Counter.h"

Counter::Counter()
	:yes_button(1400.0 / 3.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0),guest_position({-300.0,200.0})
{
}

void Counter::Load()
{
	guest_image = Engine::GetTextureManager().Load("Assets/giraffe.png");
}

void Counter::Update(double dt)
{
	yes_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Kitchen);
    if (guest_position.x < 133.0 * Engine::GetWindow().GetSize().x / 1400.0)
    {
        guest_position.x += 500 * dt;
    }
    else if (guest_position.x >= 133 * Engine::GetWindow().GetSize().x / 1400.0)
    {
        guest_position.x = 133 * Engine::GetWindow().GetSize().x / 1400.0;
    }
}

void Counter::Draw_UI()
{
    //시간
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Time", Engine::GetWindow().GetSize().x / 12.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //명성
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 5.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.15, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Rate : " + std::to_string(100), Engine::GetWindow().GetSize().x / 5.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //돈
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 2.75, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Money", Engine::GetWindow().GetSize().x / 2.75 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //밖에 손님 확인용
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x * 4.0 / 5.0, Engine::GetWindow().GetSize().y / 8.0 * 5.0, Engine::GetWindow().GetSize().x * 0.15, Engine::GetWindow().GetSize().y * 0.35);
}

void Counter::Draw_text(std::string text)
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 255);
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 2.0, Engine::GetWindow().GetSize().x / 2.3, Engine::GetWindow().GetSize().y / 4.0);
    doodle::pop_settings();

    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text(text, Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
    doodle::pop_settings();
}

void Counter::Draw()
{
	Engine::GetWindow().Clear(0xEBE3C0FF);
    //Draw_background
    doodle::push_settings();
    doodle::set_fill_color(128, 128, 0);
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y / 4.0, Engine::GetWindow().GetSize().x / 3.0 * 2.0, Engine::GetWindow().GetSize().y / 7.0 * 4.4);
    doodle::pop_settings();

    //Draw guest
	guest_image->Draw(Math::TranslationMatrix(guest_position));
    
    //draw
    doodle::push_settings();
    doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
    doodle::no_outline();
    doodle::draw_rectangle(0, 0, Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y);
    doodle::pop_settings();

    //Draw UI,text,
    Draw_UI();
    Draw_text("I'd like a pretty salad, please.");
    //Draw_stand
    doodle::push_settings();
    doodle::set_fill_color(255, 255, 0);
    doodle::draw_rectangle(0.0, 0.0, Engine::GetWindow().GetSize().x / 6.0 * 5.0, Engine::GetWindow().GetSize().y / 4.0);
    doodle::draw_triangle(Engine::GetWindow().GetSize().x / 6.0 * 5.0, Engine::GetWindow().GetSize().y / 4.0, Engine::GetWindow().GetSize().x / 6.0 * 5.0 + 100.0, 0.0, Engine::GetWindow().GetSize().x / 6.0 * 5.0, 0.0);
    doodle::pop_settings();


    yes_button.draw("Yes!");
}

void Counter::Clear()
{
	Engine::GetWindow().Clear(0xEBE3C0FF);
}

void Counter::Unload()
{
	guest_position.x = -300.0;
}

