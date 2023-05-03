/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  TextureManagerManager.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    April 25, 2023
*/

#include "TextureManager.h"
#include "Engine.h"
#include "Texture.h"

CS230::Texture* CS230::TextureManager::Load(const std::filesystem::path& file_path)
{
	if (textures[file_path] == nullptr)
	{
		textures[file_path] = new Texture(file_path);
		return textures[file_path];
	}
	else
	{
		return textures[file_path];
	}
}

void CS230::TextureManager::Unload()
{
	std::map<std::filesystem::path, Texture*>::iterator iter;
	for (iter = textures.begin(); iter != textures.end(); iter++)
	{
		delete iter->second;
	}

	textures.clear();
}