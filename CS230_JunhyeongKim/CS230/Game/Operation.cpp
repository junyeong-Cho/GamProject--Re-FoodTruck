#include "InventoryManager.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include <iostream>

int Operation::wheel = 0;
bool Operation::leftClick = false;
bool Operation::rightClick = false;


void on_mouse_wheel(int scroll_amount)
{
	if (scroll_amount > 0)
	{
		Operation::wheel = 1;
	}
	else if (scroll_amount < 0)
	{
		Operation::wheel = -1;
	}
	else
	{
		Operation::wheel = 0;
	}
}

void on_mouse_pressed(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		Operation::rightClick = true;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		Operation::leftClick = true;
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
			doodle::draw_rectangle(doodle::get_mouse_x() + i * 10, doodle::get_mouse_y() + j * 10, 10, 10);
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

void Inventory::Update()
{

}

void ToolBox::Update()
{

}

void Refrigerator::Update()
{

}

void PetProperty::Update()
{

}