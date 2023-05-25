/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter_Background.cpp
Project:    Gam150 Project
Author:     Junhyeong Kim
Created:    May 17, 2023
*/
#include "Counter_Background.h"
#include "..\Engine\Engine.h"
#include <iostream>


void Counter_Background::Add(const std::filesystem::path& texturePath)
{
	ParallaxLayer parallax;
	parallax.texture = Engine::GetTextureManager().Load(texturePath);//Load(texturePath);
	backgrounds.push_back(parallax);
}

void Counter_Background::Unload()
{
	backgrounds.clear();
}

void Counter_Background::Draw()
{
	int i = 0;
	for (i = 0; i < backgrounds.size(); i++)
	{
		double scale_x = Engine::GetWindow().GetSize().x / static_cast<double>(backgrounds[i].texture->GetSize().x);
		double scale_y = Engine::GetWindow().GetSize().y / static_cast<double>(backgrounds[i].texture->GetSize().y);
		backgrounds[i].texture->Draw(Math::TransformationMatrix() * Math::ScaleMatrix({scale_x, scale_y}));
	}

}


Math::ivec2 Counter_Background::GetSize()
{
	return backgrounds[0].texture->GetSize();
}