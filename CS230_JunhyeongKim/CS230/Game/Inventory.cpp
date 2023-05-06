#include "Inventory.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include <iostream>

int Inventory::wheel = 0;
bool Inventory::leftClick = false;
bool Inventory::rightClick = false;


Inventory::Inventory(){}

void Inventory::Update()
{
	
}

void Inventory::Draw()
{
	if (ChooseInvenroty() != InventoryName::Nothing)
	{
		switch (ClickInventory())
		{
		case InventoryName::Nothing:
			Draw_Inventory();
			break;
		case InventoryName::ToolBox: 
			Draw_ToolBoxInventory();
			break;
		case InventoryName::Refrigerator:
			Draw_Refrigerator();
			break;
		case InventoryName::PetProperty:
			Draw_PetProperty();
			break;
		}

	}
}

InventoryName Inventory::ChooseInvenroty()
{
	if (rightClick == true)
	{
		inventory += wheel;
		wheel = 0;
		return inventory;
	}
	return InventoryName::Nothing;
}

InventoryName Inventory::ClickInventory()
{
	if (ChooseInvenroty() != InventoryName::Nothing)
	{
		if (leftClick == true)
		{
			clickInventory = inventory;
			return clickInventory;
		}
	}
	return InventoryName::Nothing;
}

void Inventory::Draw_Inventory()
{
	doodle::push_settings();

	std::string text;
	switch (ChooseInvenroty())
	{
	case InventoryName::ToolBox:
		text = "ToolBox";
		break;
	case InventoryName::Refrigerator:
		text = "Refrigerator";
		break;
	case InventoryName::PetProperty:
		text = "PetProperty";
		break;
	}
	doodle::set_font_size(20);
	doodle::draw_text(text, doodle::get_mouse_x(), doodle::get_mouse_y());

	doodle::pop_settings();
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
		InventoryManager::rightClick = false;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		InventoryManager::leftClick = false;
	}
}

void Inventory::Draw()
{
	inventory += wheel;
	wheel = 0;

	doodle::push_settings();
	std::string text;
	switch (inventory)
	{
	case InventoryName::ToolBox:
		text = "ToolBox";
		break;
	case InventoryName::Refrigerator:
		text = "Refrigerator";
		break;
	case InventoryName::PetProperty:
		text = "PetProperty";
		break;
	}
	doodle::set_font_size(20);
	doodle::draw_text(text, doodle::get_mouse_x(), doodle::get_mouse_y());
	doodle::pop_settings();
}

void ToolBox::Draw()
{
	tool += wheel;
	wheel = 0;

	doodle::push_settings();
	std::string text;
	switch (tool)
	{
	case ToolName::HAND:
		text = "HAND";
		break;
	case ToolName::KNIFE:
		text = "KNIFE";
		break;
	case ToolName::LADLE:
		text = "LADLE";
		break;
	case ToolName::SCOOP:
		text = "SCOOP";
		break;
	case ToolName::TRASHCAN:
		text = "TRASHCAN";
		break;
	}
	doodle::set_font_size(20);
	doodle::draw_text(text, doodle::get_mouse_x(), doodle::get_mouse_y());
	doodle::pop_settings();
}

void Refrigerator::Draw()
{
	doodle::push_settings();

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			doodle::draw_rectangle(doodle::get_mouse_x() + i*10, doodle::get_mouse_y() + j*10, 10, 10);
		}
	}

	doodle::pop_settings();
}

void PetProperty::Draw()
{
	property += wheel;
	wheel = 0;

	doodle::push_settings();
	std::string text;
	switch (property)
	{
	case PetPropertyName::FIRE:
		text = "FIRE";
		break;
	case PetPropertyName::WATER:
		text = "WATER";
		break;
	}
	doodle::set_font_size(20);
	doodle::draw_text(text, doodle::get_mouse_x(), doodle::get_mouse_y());
	doodle::pop_settings();
}