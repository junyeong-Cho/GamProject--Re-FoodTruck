/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/
#pragma once
#include <doodle/image.hpp>
#include "Vec2.h"
#include "Matrix.h"
namespace CS230 {
    class Texture {
    public:

        void Draw(Math::TransformationMatrix display_matrix);
        void Draw(Math::TransformationMatrix display_matrix, Math::ivec2 texel_position, Math::ivec2 frame_size);
        void Set_tint_color(double red, double green, double blue);

        Math::ivec2 GetSize();
    private:
        Texture(const std::filesystem::path& file_path);
        bool set_tint = false;
        double r = 0;
        double g = 0;
        double b = 0;

        doodle::Image image;
        friend class TextureManager;
    };
}
