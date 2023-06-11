/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/

#include "..\Engine\Engine.h"

#include "doodle/drawing.hpp" //Draw
#include "doodle/input.hpp" //Mouse

#include "States.h"
#include "Sound.h"

#include "Counter.h"
#include "Customer.h"
#include "Giraffe.h"
#include "Elf.h"
#include "Fireman.h"
#include "Zilien.h"
#include "Anteater.h"
#include "Greendragon.h"
#include "SunMan.h"
#include "Theif.h"
#include "Amy.h"



Counter::Counter()
    :yes_button(600.0, 250.0, 1400.0 / 10.0, 800.0 / 10.0)
{
}

void Counter::Load()
{
    //Frame for Clock
    gameobjectmanager.Add(new Frame({ 210 , 730 }, 1));

    //Face test

    refutation = new Reputation({ 400, Engine::GetWindow().GetSize().y / 8.0 * 7.25 });
    gameobjectmanager.Add(refutation);


    //Frame for Refutation
    gameobjectmanager.Add(new Frame({ 395, 730 }, 1));


    //Frame for Money
    gameobjectmanager.Add(new Frame({ Engine::GetWindow().GetSize().x / 1.3, Engine::GetWindow().GetSize().y - 78.0 }, 2));

    //Frame for Day
    gameobjectmanager.Add(new Frame({ 30, 730 }, 1));

    if (Engine::GetUnloadManager().first_load == true)
    {
        ClearGSComponents();
        front_customor = new Giraffe(nullptr);
        Engine::GetUnloadManager().GetCounterObjectManager().Add(front_customor);
        Engine::GetUnloadManager().current_customor = front_customor;

        for (int i = 0; i < customors; i++)
        {
            ranCustomerNum = rand() % kind_customer;
            switch (ranCustomerNum )
            {
            case 0:
                front_customor = new Giraffe(front_customor);
                break;
            case 1:
                front_customor = new Anteater(front_customor);
                break;
            case 2:
                front_customor = new Elf(front_customor);
                break;
            case 3:
                front_customor = new Fireman(front_customor);
                break;
            case 4:
                front_customor = new Greendragon(front_customor);
                break;
            case 5:
                front_customor = new Zilien(front_customor);
                break;
            case 6:
                front_customor = new SunMan(front_customor);
				break;
            case 7:
                front_customor = new Theif(front_customor);
                break;
            case 8:
                front_customor = new Amy(front_customor);
				break;
            default:
                break;
            }
            Engine::GetUnloadManager().GetCounterObjectManager().Add(front_customor);
        }
        counter_Screen.Add("Assets/Counter_Screen.png");

        background.Add("Assets/Counter_Background.png");

        //Test version
        AddGSComponent(new CS230::MusicEffect());

        GetGSComponent<CS230::MusicEffect>()->LoadFile("Assets/Sound/Theme/main_theme_pirot.ogg");
        GetGSComponent<CS230::MusicEffect>()->LoadFile("Assets/Sound/Theme/kitchen_theme.ogg");

        //FoodTexture
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Bad.png")); //0
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Soso.png")); //1
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Good.png")); //2

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Bad.png")); //3
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Soso.png")); //4
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Good.png")); //5

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Bad.png")); //6
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Soso.png")); //7
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Good.png")); //8

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Bad.png")); //9
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Soso.png")); //10
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Good.png")); //11

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Bad.png")); //12
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Soso.png")); //13
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Good.png")); //14

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Bad.png")); //15
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Soso.png")); //16
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Good.png")); //17

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Bad.png")); //18
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Soso.png")); //19
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Good.png")); //20

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Bad.png")); //21
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Soso.png")); //22
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Good.png")); //23

        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Bad.png")); //24
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Soso.png")); //25
        foodTexture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Good.png")); //26

        Engine::GetUnloadManager().first_load = false;
    }




}

void Counter::Update(double dt)
{
    gameobjectmanager.UpdateAll(dt);

    GetGSComponent<CS230::MusicEffect>()->Play(1);

    if (Engine::GetUnloadManager().current_customor != nullptr)
    {
        if (Engine::GetUnloadManager().current_customor->Get_State_Name() == "Fwaiting")
        {
            yes_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Kitchen);
            Engine::GetOrderManager().SetOrder(Engine::GetUnloadManager().current_customor->Get_Oreder_recipe());
        }
    }
    Engine::GetUnloadManager().GetCounterObjectManager().UpdateAll(dt);
    Engine::GetUnloadManager().Update_timer(dt);

    if (Engine::GetUnloadManager().GetTimer() <= 0)
    {
        GetGSComponent<CS230::MusicEffect>()->Stop();
        Engine::GetUnloadManager().Update_Day();
        if (Engine::GetUnloadManager().GetDay() > 4)
        {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
        }
        else
        {
            Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Day_end));
        }
    }


    if (Engine::GetUnloadManager().GetRate() <= 0 || Engine::GetUnloadManager().GetMoney() <= 0)
    {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
    }
}

void Counter::Draw_UI()
{
    //Timer - frame addapted
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
    doodle::set_outline_width(12);
    doodle::set_outline_color(255, 255, 255);
    doodle::set_fill_color(255, 161, 74);
    doodle::draw_text("Time\n ", 240, Engine::GetWindow().GetSize().y / 8.0 * 7.55);
    doodle::draw_text(std::to_string(static_cast<int>(Engine::GetUnloadManager().GetTimer())), 255, Engine::GetWindow().GetSize().y - 80);
    doodle::pop_settings();

    //Refutation - frame addapted
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
    doodle::set_outline_width(12);
    doodle::set_outline_color(255, 255, 255);
    doodle::set_fill_color(255, 161, 74);
    doodle::draw_text(" Rate\n  " + std::to_string(Engine::GetUnloadManager().GetRate()), 455, 755);
    doodle::pop_settings();

    //Money - frame addapted
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
    doodle::set_outline_width(12);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("$" + std::to_string(Engine::GetUnloadManager().GetMoney()), Engine::GetWindow().GetSize().x / 1.3 + Engine::GetWindow().GetSize().x * 0.1 + 10.0, Engine::GetWindow().GetSize().y / 8.0 * 7.35 + 5.0);
    doodle::pop_settings();

    //Day
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
    doodle::set_outline_width(12);
    doodle::set_outline_color(255, 255, 255);
    doodle::set_fill_color(255, 161, 74);
    doodle::draw_text("DAY " + std::to_string(Engine::GetUnloadManager().GetDay()), 60, 735);
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



    if (Engine::GetUnloadManager().current_customor != nullptr)
    {
        if (Engine::GetUnloadManager().current_customor->Get_State_Name() == "Fwaiting")
        {
            yes_button.draw("Kitchen");
        }
    }

    gameobjectmanager.DrawAll(Math::TransformationMatrix());

    Draw_UI();
    DrawFood();
}

void Counter::Clear()
{
    Engine::GetWindow().Clear(0xEBE3C0FF);
}

void Counter::Unload()
{
    //Engine::GetUnloadManager().Save_Counter_object(gameobjectmanager);
    gameobjectmanager.Unload();
    //counter_Screen.Unload();
    //background.Unload();
    //GetGSComponent<CS230::MusicEffect>()->Stop();
}

void Counter::DrawFood()
{
    if (Engine::GetUnloadManager().current_customor != nullptr)
    {
        if (Engine::GetUnloadManager().current_customor->CanDrawFood() == true)
        {
            Math::TransformationMatrix matrix = Engine::GetDrawManager().GetMatrix(foodTexture[Engine::GetUnloadManager().current_customor->DrawFoodIndex()],
                Math::vec2{ 340.0, 50.0 }, Math::vec2{ 300.0, 200.0 });
                foodTexture[Engine::GetUnloadManager().current_customor->DrawFoodIndex()]->Draw(matrix);
        }
    }
}