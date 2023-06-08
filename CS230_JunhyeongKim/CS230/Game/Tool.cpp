#include "Tool.h"
#include "doodle/input.hpp"
#include <iostream>

Tool::Tool()
{
	/*texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Hand.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Knife.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Ladle.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Scoop.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_TrashCan.png"));*/
}

void Tool::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Hand.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Knife.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Ladle.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Scoop.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_TrashCan.png"));
}

void Tool::Unload()
{
	texture.clear();
}

void Tool::Draw()
{
	pos.x = doodle::get_mouse_x() - size.x / 2.0;
	pos.y = doodle::get_mouse_y() - size.y / 2.0;
	texture[static_cast<int>(toolname)]->Draw(Engine::GetDrawManager().GetMatrix(texture[static_cast<int>(toolname)], pos, size));
	
}

void Tool::Update(ToolName toolName)
{
	toolname = toolName;
}