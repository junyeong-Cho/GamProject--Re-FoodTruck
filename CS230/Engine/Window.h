/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Window.h
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/


#pragma once
#include <string>
#include "Vec2.h"

void on_window_resized(int, int);

namespace CS230 {
    class Window {
    public:
        void Start(std::string title);
        void Clear(unsigned int color);
        void Update();
        Math::ivec2 GetSize();
        friend void ::on_window_resized(int, int);
        
    private:
        Math::ivec2 window_size;
        static constexpr int default_width = 1400;
        static constexpr int default_height = 800;
        static constexpr unsigned int default_background = UINT_MAX;

    };
}


