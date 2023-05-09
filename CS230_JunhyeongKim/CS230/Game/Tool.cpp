#include "Tool.h"
#include "doodle/input.hpp"

void Tool::Load()
{
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Hand.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Knife.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Ladle.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_Scoop.png"));
	texture.push_back(Engine::GetTextureManager().Load("Assets/Tool_TrashCan.png"));
}

void Tool::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(Math::vec2(doodle::get_mouse_x(), doodle::get_mouse_y())) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture[static_cast<int>(tool)]->Draw(matrix);
}

void Tool::ChangeTool(InventoryTexture toolName)
{
	switch (toolName)
	{
	case InventoryTexture::Hand:
		tool = ToolName::HAND;
		break;
	case InventoryTexture::Knife:
		tool = ToolName::KNIFE;
		break;
	case InventoryTexture::Ladle:
		tool = ToolName::LADLE;
		break;
	case InventoryTexture::Scoop:
		tool = ToolName::SCOOP;
		break;
	case InventoryTexture::TrashCan:
		tool = ToolName::TRASHCAN;
		break;
	}
}