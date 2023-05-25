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
    if (Engine::GetUnloadManager().first_load == true)
    {

        front_customor = new Giraffe(nullptr);
        Engine::GetUnloadManager().GetCounterObjectManager().Add(front_customor);
        for (int i = 1; i < customors; i++)
        {
            int customer_num = rand() / (RAND_MAX / 2);

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
            Engine::GetUnloadManager().GetCounterObjectManager().Add(front_customor);
        }
        counter_Screen.Add("Assets/Counter_Screen.png");

        int background_num = rand() / (RAND_MAX / 2);

        switch (background_num)
        {
        case 0:
            background.Add("Assets/Counter_Background_1.png");
            break;
        case 1:
            background.Add("Assets/Counter_Background_2.png");
            break;
        case 2:
            background.Add("Assets/Counter_Background_3.png");
            break;
        default:
            break;
        }

        
        Engine::GetUnloadManager().first_load = false;


    }

}

void Counter::Update(double dt)
{
    if (Engine::GetUnloadManager().current_customor != nullptr)
    {
        if (Engine::GetUnloadManager().current_customor->Get_State_Name() == "Fwaiting")
        {
            yes_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Kitchen);
        }
    }
    Engine::GetUnloadManager().GetCounterObjectManager().UpdateAll(dt);
    Engine::GetUnloadManager().Update_timer(dt);
    if (Engine::GetUnloadManager().GetTimer() <= 0)
    {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
    }
}

void Counter::Draw_UI()
{
    //½Ã°£
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 12.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Tm : " + std::to_string(static_cast<int>(Engine::GetUnloadManager().GetTimer())), Engine::GetWindow().GetSize().x / 12.0 - 20 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //¸í¼º
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 5.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.15, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Rate : " + std::to_string(Engine::GetUnloadManager().GetRate()), Engine::GetWindow().GetSize().x / 5.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
    //µ·
    doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 2.75, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.10, Engine::GetWindow().GetSize().y * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text(std::to_string(Engine::GetUnloadManager().GetMoney()), Engine::GetWindow().GetSize().x / 2.75 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
    doodle::pop_settings();
}


void Counter::Draw()
{
    Engine::GetWindow().Clear(0xEBE3C0FF);

    //Draw Background
    background.Draw();
    //Draw guest
    Engine::GetUnloadManager().GetCounterObjectManager().DrawAll(Math::TransformationMatrix());


    counter_Screen.Draw();

    Draw_UI();

    if (Engine::GetUnloadManager().current_customor != nullptr)
    {
        if (Engine::GetUnloadManager().current_customor->Get_State_Name() == "Fwaiting")
        {
            yes_button.draw("Kitchen");
        }
    }

}

void Counter::Clear()
{
    Engine::GetWindow().Clear(0xEBE3C0FF);
}

void Counter::Unload()
{
    //Engine::GetUnloadManager().Save_Counter_object(gameobjectmanager);
    //gameobjectmanager.Unload();
    counter_Screen.Unload();
    background.Unload();
}
