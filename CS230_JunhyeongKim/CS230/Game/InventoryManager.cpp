#include "InventoryManager.h"
#include "doodle/input.hpp"

int InventoryManager::wheel = 0;
bool InventoryManager::leftClick = false;
bool InventoryManager::rightClick = false;

InventoryManager::InventoryManager()
{
	operation.push_back(new Inventory());
	operation.push_back(new ToolBox());
	operation.push_back(new PetProperty());
	operation.push_back(new Refrigerator());
}

void InventoryManager::Draw()
{
	
}

void InventoryManager::Update()
{
	
}

void on_mouse_wheel(int scroll_amount)
{
	if (scroll_amount > 0)
	{
		InventoryManager::wheel = 1;
	}
	else if (scroll_amount < 0)
	{
		InventoryManager::wheel = -1;
	}
	else
	{
		InventoryManager::wheel = 0;
	}
}

void on_mouse_pressed(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		InventoryManager::rightClick = true;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		InventoryManager::leftClick = true;
	}

}

void on_mouse_released(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		Operation::rightClick = false;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		Operation::leftClick = false;
	}
}