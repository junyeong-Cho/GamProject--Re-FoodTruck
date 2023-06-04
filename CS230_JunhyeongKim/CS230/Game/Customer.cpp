/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Customer.cpp
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    March 2, 2023
*/

#include"Customer.h"
#include "..\Engine\Engine.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include "Counter.h"

#include <iostream>

Customor::Customor(Customor* front) :
    GameObject({ -300.0,138.0 }), front_customor(front),
    Yes(400.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0),
    No(750.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0),
    evalue(1400.0 / 2.5, 800.0 / 3.0, 1400.0 / 10.0, 800 / 10.0)
{
    current_state = &state_waiting;
    //SetScale({ 0.98,0.98 });
    random_timer = static_cast<double>(rand()) / (RAND_MAX / 5) + 10/Engine::GetUnloadManager().GetDay();
    std::cout << random_timer << "\n";
    current_state->Enter(this);
    timer = random_timer;
    last_timer = static_cast<int>(random_timer);    
}

void Customor::update_x_velocity(double dt)
{
    if (GetPosition().x < 133.0 * Engine::GetWindow().GetSize().x / 1400.0)
    {
        UpdateVelocity({ 200 * dt,0 });
    }
    else if (GetPosition().x >= 133 * Engine::GetWindow().GetSize().x / 1400.0)
    {
        SetPosition({ 133.0 * Engine::GetWindow().GetSize().x / 1400.0,GetPosition().y });
        SetVelocity({ 0,0 });
        can_order = true;
        if (button_timer <= 0.5)
        {
            button_timer += dt;
        }
    }
}

//Waiting
void Customor::State_Waiting::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    customor->SetVelocity({ 0,0 });
}

void Customor::State_Waiting::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);
}

void Customor::State_Waiting::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);

    if (customor->front_customor == nullptr || customor->front_customor->current_state->GetName() == "Fwaiting" || customor->front_customor->current_state->GetName() == "Leaving")
    {
        customor->change_state(&customor->state_in_counter);
    }

}



//In_counter
void Customor::State_In_Counter::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
}

void Customor::State_In_Counter::Update(GameObject* object, double dt)
{
    
    Customor* customor = static_cast<Customor*>(object);
    
    if (customor->random_timer <= 0)
    {
        if ((customor->GetPosition().x < 60.0 * Engine::GetWindow().GetSize().x / 1400.0))
        {
            customor->UpdatePosition({ 200 * dt,0 });
        }
        else
        {
            customor->SetPosition({ 60.0 * Engine::GetWindow().GetSize().x / 1400.0 ,customor->GetPosition().y });
        }

        customor->timer -= dt;

        if ((static_cast<int>(customor->timer) < customor->last_timer))
        {
            customor->last_timer = static_cast<int>(customor->timer);
        }
    }
    else 
    {
        customor->random_timer -= dt;
    }

}

void Customor::State_In_Counter::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->last_timer == 0)
    {
        CS230::SoundEffect* soundEffect = new CS230::SoundEffect();
        soundEffect->LoadFile("Assets/Sound/SFX/EnteringBell.wav");
        soundEffect->Play(0);

        customor->change_state(&customor->state_leaving);
    }

    if (customor->front_customor == nullptr || customor->front_customor->current_state->GetName() == "Leaving")
    {
        CS230::SoundEffect* soundEffect = new CS230::SoundEffect();
        soundEffect->LoadFile("Assets/Sound/SFX/EnteringBell.wav");
        soundEffect->Play(0);

        customor->change_state(&customor->state_order);
    }
}



//Order
void Customor::State_Order::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    customor->SetVelocity({ 0,0 });
    Engine::GetUnloadManager().current_customor = customor;
}

void Customor::State_Order::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->front_customor == nullptr)
    {
        customor->update_x_velocity(dt);
    }

    if (customor->button_timer >= 0.5 && customor->evaluating == false)
    {
        customor->Yes.update(doodle::get_mouse_x(), doodle::get_mouse_y());
        customor->No.update(doodle::get_mouse_x(), doodle::get_mouse_y());
    }
}

void Customor::State_Order::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->Get_can_order() == true && customor->Yes.checkClick == true)
    {
        customor->can_order = false;
        customor->change_state(&customor->state_fwaiting);
    }

    if (customor->Get_can_order() == true && customor->No.checkClick == true)
    {
        customor->can_order = false;
        customor->grade = static_cast<int>(Grade::NO_FOOD);
        customor->change_state(&customor->state_evaluate);
    }
}

//Fwaiting
void Customor::State_Fwaiting::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
}

void Customor::State_Fwaiting::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);

}

void Customor::State_Fwaiting::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);


    if (Engine::GetUnloadManager().food_complete == true)
    {
        customor->change_state(&customor->state_evaluate);
    }


}


//Evaluate
void Customor::State_Evaluate::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);

    if (Engine::GetUnloadManager().Getfood_grad() < 40)
    {
        customor->grade = static_cast<int>(Grade::BAD);
    }
    else if (Engine::GetUnloadManager().Getfood_grad() < 95)
    {
        customor->grade = static_cast<int>(Grade::SOSO);
    }
    else
    {
        customor->grade = static_cast<int>(Grade::GOOD);
    }
}

void Customor::State_Evaluate::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);

    customor->evalue.update(doodle::get_mouse_x(), doodle::get_mouse_y());
}

void Customor::State_Evaluate::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->evalue.checkClick == true)
    {

        switch (customor->grade)
        {
        case static_cast<int>(Grade::NO_FOOD):
            Engine::GetUnloadManager().Update_rate(-10);
            break;
        case static_cast<int>(Grade::BAD):
            Engine::GetUnloadManager().Update_money(5);
            Engine::GetUnloadManager().Update_rate(-5);
            break;
        case static_cast<int>(Grade::SOSO):
            Engine::GetUnloadManager().Update_money(5);
            Engine::GetUnloadManager().Update_rate(-5);
            break;
        case static_cast<int>(Grade::GOOD):
            Engine::GetUnloadManager().Update_money(5);
            Engine::GetUnloadManager().Update_rate(-5);
            break;
        default:
            break;
        }

        Engine::GetUnloadManager().food_complete = false;
        customor->change_state(&customor->state_leaving);
    }
}



//Leaving
void Customor::State_Leaving::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    customor->sprite.texture->Set_tint_color(0, 255, 0);
    customor->SetVelocity({ 500,0 });
}

void Customor::State_Leaving::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->GetPosition().x > Engine::GetWindow().GetSize().x)
    {
        customor->SetVelocity({ 0,0 });
    }
}

void Customor::State_Leaving::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    std::cout <<  static_cast<int>(customor->oreder_recipe);


}


void Customor::Update(double dt)
{
    GameObject::Update(dt);
    if (front_customor != nullptr && front_customor->current_state->GetName() == "Leaving")
    {
        front_customor = front_customor->front_customor;
    }
}


void Customor::Draw(Math::TransformationMatrix camera_matrix)
{

    sprite.Draw(camera_matrix * GetMatrix());


    if (can_order == true && evaluating == false)
    {
        doodle::push_settings();
        doodle::set_fill_color(255, 255, 255);
        doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 2.0, Engine::GetWindow().GetSize().x / 2.3, Engine::GetWindow().GetSize().y / 4.0);
        doodle::pop_settings();

        doodle::push_settings();
        doodle::set_font_fade_out_interval(0.5, 0.0);
        doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
        doodle::set_fill_color(0, 0, 0);
        //Order
        doodle::draw_text(Order_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        doodle::pop_settings();
    }

    if (current_state->GetName() == "Evaluate")
    {
        doodle::push_settings();
        doodle::set_fill_color(255, 255, 255);
        doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 2.0, Engine::GetWindow().GetSize().x / 2.3, Engine::GetWindow().GetSize().y / 4.0);
        doodle::pop_settings();

        doodle::push_settings();
        doodle::set_font_fade_out_interval(0.5, 0.0);
        doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
        doodle::set_fill_color(0, 0, 0);

        //Order
        if (grade == static_cast<int>(Grade::NO_FOOD))
        {
            doodle::draw_text(Grade_bad_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        }
        else if (grade == static_cast<int>(Grade::BAD))
        {
            doodle::draw_text(Grade_bad_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        }
        else if (grade == static_cast<int>(Grade::SOSO))
        {
            doodle::draw_text(Grade_soso_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        }
        else
        {
            doodle::draw_text(Grade_good_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        }
        doodle::pop_settings();
        evalue.draw("OK");
    }
    else if (current_state->GetName() == "In_Counter")
    {
      doodle::draw_text(std::to_string(last_timer),  sprite.GetFrameSize().x, GetPosition().y + 400);
    }

    if (button_timer > 0.3 && current_state->GetName() == "Order" && evaluating == false)
    {
        //Button
        Yes.draw("Yes!");
        No.draw("No!");
    }
}