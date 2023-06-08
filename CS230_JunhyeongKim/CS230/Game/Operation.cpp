#include "doodle/drawing.hpp"
#include "Operation.h"
#include <iostream>

int wheel = 0;
bool leftClick = false;
bool rightClick = false;

Operation::Operation()
{
}

void Operation::Load()
{
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Hand.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Knife.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Ladle.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/Scoop.png"));
	operationTexture.push_back(Engine::GetTextureManager().Load("Assets/TrashCan.png"));
}

void Operation::Unload()
{
	operationTexture.clear();
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
		operationTexture[static_cast<int>(textureIndex)]->Draw(Math::TranslationMatrix(Math::vec2{ (double)Engine::GetWindow().GetSize().x / 3.5, (double)Engine::GetWindow().GetSize().y / 7 }));
	}
}

void Operation::Update()
{
	if (rightClick == true)
	{
		if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Right))
		{
			wheel = 1;
		}
		else if(Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Left))
		{
			wheel = -1;
		}
		textureIndex += wheel;
		wheel = 0;
	}
}

ToolName Operation::Return()
{
	return textureIndex;
}