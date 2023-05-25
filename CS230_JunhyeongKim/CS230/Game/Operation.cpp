#include "doodle/drawing.hpp"
#include "Operation.h"
#include <iostream>

int wheel = 0;
bool leftClick = false;
bool rightClick = false;

Operation::Operation()
{
	std::cout << "Operation Constructor";
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

void Operation::Load()
{

}

void on_mouse_wheel(int scroll_amount)
{
	if (scroll_amount > 0)
	{
		wheel = -1;
	}
	else if (scroll_amount < 0)
	{
		wheel = 1;
	}
	else
	{
		wheel = 0;
	}
}

void on_mouse_pressed(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		rightClick = true;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		leftClick = true;

	}
}

void on_mouse_released(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Right)
	{
		rightClick = false;
	}
	else if (button == doodle::MouseButtons::Left)
	{
		leftClick = false;
	}
}

void Operation::Draw()
{
	if (rightClick == true)
	{
		if (textureIndex != InventoryTexture::Ingredient)
		{
			operationTexture[static_cast<int>(textureIndex)]->Draw(Math::TranslationMatrix(Math::vec2{(double)Engine::GetWindow().GetSize().x / 3.5, (double)Engine::GetWindow().GetSize().y / 7 }));
		}
		else
		{

		}
	}
}

void Operation::Update()
{
	if (rightClick == true)
	{
		textureIndex += wheel;
		wheel = 0;
		if (leftClick == true)
		{
			leftClick = false;
			switch (textureIndex)
			{
			case InventoryTexture::ToolBox:
				textureIndex = InventoryTexture::Hand;
				break;
			case InventoryTexture::PetProperty:
				textureIndex = InventoryTexture::Fire;
				break;
			case InventoryTexture::Refrigerator:
				textureIndex = InventoryTexture::Ingredient;
				break;
			}
		}
	}
	else
	{
		textureIndex = InventoryTexture::ToolBox;
	}
}

InventoryTexture Operation::Return()
{
	return textureIndex;
}