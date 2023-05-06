#include "Cook.h"

Cook::Cook() : inventoryManager(InventoryManager{})
{

}

void Cook::Update(double dt)
{
	inventoryManager.Update();
}

void Cook::Draw()
{
	inventoryManager.Draw();
}
