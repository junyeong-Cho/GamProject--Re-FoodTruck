/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Sprite.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 24, 2023
*/

#include "Engine.h"
#include "Sprite.h"
#include <fstream>

CS230::Sprite::Sprite() 
{
    current_animation = 0;
}

CS230::Sprite::~Sprite()
{
    for (Animation* animation : animations) {
        delete animation;
    }
    animations.clear();
}

void CS230::Sprite::PlayAnimation(int animation)
{
    if (animation < 0 && animation >= animations.size())
    {
        Engine::GetLogger().LogError("The animation doesn¡¯t exist.");
    }
    else
    {
        current_animation = animation;
        animations[current_animation]->Reset();
    }
}

bool CS230::Sprite::AnimationEnded()
{
    if (animations[current_animation]->Ended() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CS230::Sprite::Update(double dt)
{
    animations[current_animation]->Update(dt);
}

void CS230::Sprite::Load(const std::filesystem::path& sprite_file)
{
    if (sprite_file.extension() != ".spt") {
        throw std::runtime_error(sprite_file.generic_string() + " is not a .spt file");
    }

    std::ifstream in_file(sprite_file);

    if (in_file.is_open() == false) {
        throw std::runtime_error("Failed to load " + sprite_file.generic_string());
    }

    hotspots.clear();
    frame_texels.clear();
    animations.clear();

    std::string text;
    in_file >> text;
    texture = Engine::GetTextureManager().Load(text);
    //texture.Load(text);
    frame_size = texture->GetSize();

    in_file >> text;
    while (in_file.eof() == false) {
        if (text == "FrameSize") {
            in_file >> frame_size.x;
            in_file >> frame_size.y;
        }
        else if (text == "NumFrames") {
            int frame_count;
            in_file >> frame_count;
            for (int i = 0; i < frame_count; i++) {
                frame_texels.push_back({ frame_size.x * i, 0 });
            }
        }
        else if (text == "Frame") {
            int frame_location_x, frame_location_y;
            in_file >> frame_location_x;
            in_file >> frame_location_y;
            frame_texels.push_back({ frame_location_x, frame_location_y });
        }
        else if (text == "HotSpot") {
            int hotspot_x, hotspot_y;
            in_file >> hotspot_x;
            in_file >> hotspot_y;
            hotspots.push_back({ hotspot_x, hotspot_y });
        }
        else if (text == "Anim") {
            in_file >> text;
            animations.push_back(new Animation(text));
        }
        else {
            Engine::GetLogger().LogError("Unknown command: " + text);
        }
        in_file >> text;
    }
    if (frame_texels.empty() == true) {
        frame_texels.push_back({ 0,0 });
    }
    if (animations.empty() == true){
        animations.push_back(new Animation());
    }
}

void CS230::Sprite::Draw(Math::TransformationMatrix display_matrix)
{
    texture->Draw(display_matrix * Math::TranslationMatrix(-GetHotSpot(0)), GetFrameTexel(animations[current_animation]->CurrentFrame()), GetFrameSize());
}

Math::ivec2 CS230::Sprite::GetHotSpot(int index)
{
	return hotspots[index];
}

Math::ivec2 CS230::Sprite::GetFrameSize()
{
    return frame_size;
}

Math::ivec2 CS230::Sprite::GetFrameTexel(int index) const
{
    return frame_texels[index];
}

