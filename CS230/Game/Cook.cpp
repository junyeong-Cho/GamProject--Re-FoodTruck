#include "Cook.h"

Cook::Cook() : inventory(Inventory{})
{

}

void Cook::Update(double dt)
{
	inventory.Update();
}

void Cook::Draw()
{
	inventory.Draw();
}
