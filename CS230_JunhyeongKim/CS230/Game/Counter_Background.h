/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter_Background.h
Project:    Gam150 Project
Author:     Junhyeong Kim
Created:    May 17, 2023
*/

#pragma once

#pragma once
#include <vector>
#include "../Engine/Texture.h"
#include "../Engine/Vec2.h"

class Counter_Background 
{
public:
    void Add(const std::filesystem::path& texturePath);
    void Unload();
    void Draw();
    Math::ivec2 GetSize();
private:
    struct ParallaxLayer {
        CS230::Texture* texture;
    };

    std::vector<ParallaxLayer> backgrounds;

};
