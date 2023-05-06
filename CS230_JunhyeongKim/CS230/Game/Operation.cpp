#include "InventoryManager.h"
#include "doodle/drawing.hpp"
#include "doodle/input.hpp"
#include <iostream>

int Operation::wheel = 0;
bool Operation::leftClick = false;
bool Operation::rightClick = false;

void Operation::Load()
{
	matrix *= Math::TranslationMatrix(Engine::GetWindow().GetSize());
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Toolbox.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/PetProperty.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Refrigerator.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Hand.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Knife.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Ladle.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Scoop.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/TrashCan.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Fire.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Water.png"));
}

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

	switch (inventory)
	{
	case InventoryName::ToolBox:
		operationTexture[static_cast<int>(InventoryTexture::ToolBox)]->Draw(matrix);
		break;
	case InventoryName::Refrigerator:
		operationTexture[static_cast<int>(InventoryTexture::Refrigerator)]->Draw(matrix);
		break;
	case InventoryName::PetProperty:
		operationTexture[static_cast<int>(InventoryTexture::PetProperty)]->Draw(matrix);
		break;
	}

void ToolBox::Draw()
{
	tool += wheel;
	wheel = 0;

	switch (tool)
	{
	case ToolName::HAND:
		operationTexture[static_cast<int>(InventoryTexture::Hand)]->Draw(matrix);
		break;
	case ToolName::KNIFE:
		operationTexture[static_cast<int>(InventoryTexture::Knife)]->Draw(matrix);
		break;
	case ToolName::LADLE:
		operationTexture[static_cast<int>(InventoryTexture::Ladle)]->Draw(matrix);
		break;
	case ToolName::SCOOP:
		operationTexture[static_cast<int>(InventoryTexture::Scoop)]->Draw(matrix);
		break;
	case ToolName::TRASHCAN:
		operationTexture[static_cast<int>(InventoryTexture::TrashCan)]->Draw(matrix);
		break;
	}
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

	switch (property)
	{
	case PetPropertyName::FIRE:
		operationTexture[static_cast<int>(InventoryTexture::Fire)]->Draw(matrix);
		break;
	case PetPropertyName::WATER:
		operationTexture[static_cast<int>(InventoryTexture::Water)]->Draw(matrix);
		break;
	}
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