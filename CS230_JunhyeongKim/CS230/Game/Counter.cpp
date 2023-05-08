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
#include "doodle/drawing.hpp" //Draw
#include "doodle/input.hpp" //Mouse
#include "States.h"
#include "Counter.h"
#include "Customer.h"
#include "Giraffe.h"
#include "Elf.h"

Counter::Counter()
    :yes_button(1400.0 / 13.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0)
{
}

void Counter::Load()
{
    front_customor = new Giraffe(nullptr);
    gameobjectmanager.Add(front_customor);




    for (int i = 0; i < customors; i++)
    {
        int customer_num = (static_cast<double>(rand()) / (RAND_MAX / 2));

        switch (customer_num)
        {
        case 0:
            front_customor = new Giraffe(front_customor);
            break;
        case 1:
            front_customor = new Elf(front_customor);
            break;
        case 2:
            front_customor = new Giraffe(front_customor);
            break;
        default:
            break;
        }
        gameobjectmanager.Add(front_customor);
    }

}

void Counter::Update(double dt)
{
    yes_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Kitchen);
    gameobjectmanager.UpdateAll(dt);
}

void Counter::Draw_UI()
{
    //½Ã°£
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Time", Engine::GetWindow().GetSize().x / 12.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //¸í¼º
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 5.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.15, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Rate : " + std::to_string(100), Engine::GetWindow().GetSize().x / 5.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //µ·
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 2.75, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    //doodle::draw_text(std::to_string(money.Get_money()), Engine::GetWindow().GetSize().x / 2.75 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
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
    gameobjectmanager.DrawAll(Math::TransformationMatrix());

    //draw
    doodle::push_settings();
    doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
    doodle::no_outline();
    doodle::draw_rectangle(0, 0, Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y);
    doodle::pop_settings();

    //Draw UI,text,
    Draw_UI();
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
    gameobjectmanager.Unload();
}
