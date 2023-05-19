#include "Clock.h"

Clock::Clock(Math::vec2 start_position) : GameObject(start_position)
{
	sprite.Load("Assets/Clock.png");
    SetPosition(start_position);
	current_state = &state_moving;
	current_state->Enter(this);
}



void Clock::Update(double dt)
{
	GameObject::Update(dt);

}


void Clock::State_Moving::Enter(GameObject* object)
{
	Clock* clock = static_cast<Clock*>(object);

	clock->sprite.PlayAnimation(static_cast<int>(Animations::Moving));

}

void Clock::State_Moving::Update(GameObject* object, double dt)
{
}

void Clock::State_Moving::CheckExit(GameObject* object)
{
}
