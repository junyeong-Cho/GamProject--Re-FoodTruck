#include "Kitchen.h"

Kitchen::Kitchen() : cook(Cook{})
{
	
}

void Kitchen::Load()
{

}

void Kitchen::Update(double dt)
{
	cook.Update(dt);
}
void Kitchen::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	cook.Draw();
}
void Kitchen::Unload()
{

}