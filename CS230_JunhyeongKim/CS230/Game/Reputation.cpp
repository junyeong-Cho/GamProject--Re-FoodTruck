/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Reputation.cpp
Project:    GAM150
Author:     Junyeong cho
Created:    March 8, 2023
Updated:    May  28, 2023
*/
#include "Reputation.h"


Reputation::Reputation(Math::vec2 position) : GameObject(position)
{
	sprite.Load("Assets/RefutationFaces/RefutationFaces.spt");
	current_state = &state_idle;
	current_state->Enter(this);
}

void Reputation::Update(double dt)
{
	GameObject::Update(dt);
}

void Reputation::DrawRefutation()
{
	doodle::draw_rectangle(Engine::GetWindow().GetSize().x / 5.0, Engine::GetWindow().GetSize().y / 8.0 * 7.3, Engine::GetWindow().GetSize().x * 0.15, Engine::GetWindow().GetSize().y * 0.07);
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 60.0);
	doodle::set_fill_color(0, 0, 0);
	doodle::draw_text("Rate : " + std::to_string(Engine::GetUnloadManager().GetRate()), Engine::GetWindow().GetSize().x / 5.0 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
	doodle::pop_settings();
}


void Reputation::State_Idle::Enter(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	refutation->sprite.PlayAnimation(static_cast<int>(Animations::Idle));
}

void Reputation::State_Idle::Update(GameObject* object, double dt)
{

}

void Reputation::State_Idle::CheckExit(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);


	if ((Engine::GetUnloadManager().GetRate() <= 100) && (Engine::GetUnloadManager().GetRate() > 75))
	{
		refutation->change_state(&refutation->state_happy);
	}
}



void Reputation::State_Happy::Enter(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	refutation->sprite.PlayAnimation(static_cast<int>(Animations::Happy));
}

void Reputation::State_Happy::Update(GameObject* object, double dt)
{
}

void Reputation::State_Happy::CheckExit(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	if ((Engine::GetUnloadManager().GetRate() <= 75) && (Engine::GetUnloadManager().GetRate() > 50))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 50) && (Engine::GetUnloadManager().GetRate() > 25))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 25) && (Engine::GetUnloadManager().GetRate() > 0))
	{
		refutation->change_state(&refutation->state_angry);
	}
}

void Reputation::State_Normal::Enter(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	refutation->sprite.PlayAnimation(static_cast<int>(Animations::Normal));
}

void Reputation::State_Normal::Update(GameObject* object, double dt)
{
}

void Reputation::State_Normal::CheckExit(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	if ((Engine::GetUnloadManager().GetRate() <= 100) && (Engine::GetUnloadManager().GetRate() > 75))
	{
		refutation->change_state(&refutation->state_happy);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 75) && (Engine::GetUnloadManager().GetRate() > 50))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 50) && (Engine::GetUnloadManager().GetRate() > 25))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 25) && (Engine::GetUnloadManager().GetRate() > 0))
	{
		refutation->change_state(&refutation->state_angry);
	}
}

void Reputation::State_Angry::Enter(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	refutation->sprite.PlayAnimation(static_cast<int>(Animations::Angry));
}

void Reputation::State_Angry::Update(GameObject* object, double dt)
{
}

void Reputation::State_Angry::CheckExit(GameObject* object)
{
	Reputation* refutation = static_cast<Reputation*>(object);
	if ((Engine::GetUnloadManager().GetRate() <= 100) && (Engine::GetUnloadManager().GetRate() > 75))
	{
		refutation->change_state(&refutation->state_happy);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 75) && (Engine::GetUnloadManager().GetRate() > 50))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 50) && (Engine::GetUnloadManager().GetRate() > 25))
	{
		refutation->change_state(&refutation->state_normal);
	}
	else if ((Engine::GetUnloadManager().GetRate() <= 25) && (Engine::GetUnloadManager().GetRate() > 0))
	{
		refutation->change_state(&refutation->state_angry);
	}
}
