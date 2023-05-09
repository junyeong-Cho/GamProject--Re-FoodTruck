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

Customor::Customor(Customor* front) :
    GameObject({ -300.0,200.0 }), front_customor(front),
    Yes(400.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0),
    No(750.0, 800.0 / 3.0, 1400.0 / 10.0, 800.0 / 10.0),
    evalue(1400.0 / 2.5, 800.0 / 3.0, 1400.0 / 10.0, 800 / 10.0)
{
    current_state = &state_waiting;
    SetScale({ 0.98,0.98 });
    current_state->Enter(this);
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
        customor->change_state(&customor->state_order);
    }

}

//Order
void Customor::State_Order::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    customor->SetVelocity({ 0,0 });
}

void Customor::State_Order::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->front_customor == nullptr || customor->front_customor->number_ticket < 3)
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
        customor->change_state(&customor->state_evaluate);
    }
}

//Fwaiting
void Customor::State_Fwaiting::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    customor->SetVelocity({ 500,0 });
}

void Customor::State_Fwaiting::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);

    if (customor->front_customor != nullptr)
    {
        customor->number_ticket = customor->front_customor->number_ticket + 1;
    }

    if (customor->number_ticket == 1)
    {
        if (customor->GetVelocity().x > 0 && (customor->GetPosition().x > Engine::GetWindow().GetSize().x / 1.4))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ Engine::GetWindow().GetSize().x / 1.4 , customor->GetPosition().y });
        }

        if (customor->GetVelocity().x < 0 && (customor->GetPosition().x < Engine::GetWindow().GetSize().x / 1.4))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ Engine::GetWindow().GetSize().x / 1.4 , customor->GetPosition().y });
        }


        if (customor->GetPosition().x == Engine::GetWindow().GetSize().x / 1.25)
        {
            customor->SetVelocity({ -500,0 });
        }

    }
    else if (customor->number_ticket == 2)
    {
        if (customor->GetVelocity().x > 0 && (customor->GetPosition().x > Engine::GetWindow().GetSize().x / 1.25))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ Engine::GetWindow().GetSize().x / 1.25 , customor->GetPosition().y });
        }

        if (customor->GetVelocity().x < 0 && (customor->GetPosition().x < Engine::GetWindow().GetSize().x / 1.25))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ Engine::GetWindow().GetSize().x / 1.25 , customor->GetPosition().y });
        }

        if (customor->GetPosition().x == (Engine::GetWindow().GetSize().x / 1400.0) * 1240.0)
        {
            customor->SetVelocity({ -500,0 });
        }
    }
    else if (customor->number_ticket == 3)
    {
        if (customor->GetVelocity().x > 0 && (customor->GetPosition().x > (Engine::GetWindow().GetSize().x / 1400.0) * 1240.0))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ (Engine::GetWindow().GetSize().x / 1400.0) * 1240.0 , customor->GetPosition().y });
        }

        if (customor->GetVelocity().x < 0 && (customor->GetPosition().x < (Engine::GetWindow().GetSize().x / 1400.0) * 1240.0))
        {
            customor->SetVelocity({ 0,0 });
            customor->SetPosition({ (Engine::GetWindow().GetSize().x / 1400.0) * 1240.0 , customor->GetPosition().y });
        }

    }
}

void Customor::State_Fwaiting::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->get_food == true)
    {
        customor->change_state(&customor->state_evaluate);
    }

    if (customor->number_ticket == 1 && customor->GetPosition().x == Engine::GetWindow().GetSize().x / 1.4 && Engine::GetInput().KeyDown(CS230::Input::Keys::A))
    {
        customor->change_state(&customor->state_evaluate);
    }
}


//Evaluate
void Customor::State_Evaluate::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
}

void Customor::State_Evaluate::Update(GameObject* object, double dt)
{
    Customor* customor = static_cast<Customor*>(object);

    //
    if (customor->get_food == false)
    {
        customor->grade = 0;
    }
    customor->evalue.update(doodle::get_mouse_x(), doodle::get_mouse_y());
}

void Customor::State_Evaluate::CheckExit(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
    if (customor->evalue.checkClick == true)
    {
        if (customor->grade == 0)
        {
            Engine::GetUnloadManager().Update_money(5);
            Engine::GetUnloadManager().Update_rate(-5);
        }
        customor->number_ticket -= 1;
        customor->change_state(&customor->state_leaving);
    }
}



//Leaving
void Customor::State_Leaving::Enter(GameObject* object)
{
    Customor* customor = static_cast<Customor*>(object);
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
}


void Customor::Update(double dt)
{
    GameObject::Update(dt);
    if (front_customor != nullptr && front_customor->current_state->GetName() == "Leaving")
    {
        front_customor = front_customor->front_customor;
    }

    if (first_ticket == nullptr && front_customor != nullptr && front_customor->current_state->GetName() == "Fwaiting")
    {
        if (front_customor->number_ticket == 1)
        {
            first_ticket = front_customor;
        }
        else if (front_customor->number_ticket == 2)
        {
            first_ticket = front_customor->front_customor;
        }
        else if (front_customor->number_ticket == 3)
        {
            first_ticket = front_customor->front_customor->front_customor;
        }
    }

    if (first_ticket != nullptr && first_ticket->current_state->GetName() == "Evaluate")
    {
        evaluating = true;
    }
    else if (first_ticket != nullptr && first_ticket->current_state->GetName() != "Evaluate")
    {
        evaluating = false;
    }

    if (first_ticket != nullptr && first_ticket->number_ticket != 1)
    {
        first_ticket = nullptr;
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
        if (grade == 0)
        {
            doodle::draw_text(Grade_bad_text(), Engine::GetWindow().GetSize().x / 4.0 + Engine::GetWindow().GetSize().x / 30.0, Engine::GetWindow().GetSize().y / 2.0 + Engine::GetWindow().GetSize().y / 10.0);
        }
        doodle::pop_settings();
        evalue.draw("OK");
    }

    if (button_timer > 0.3 && current_state->GetName() == "Order" && evaluating == false)
    {
        //Button
        Yes.draw("Yes!");
        No.draw("No!");
    }
}