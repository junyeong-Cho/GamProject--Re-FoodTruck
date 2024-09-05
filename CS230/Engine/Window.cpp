/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Window.cpp
Project:    GAM150
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include <doodle/drawing.hpp>
#include <doodle/window.hpp>
#include "Window.h"
#include "Engine.h"

void CS230::Window::Start(std::string title) {
    doodle::create_window(title, default_width, default_height);
    Clear(default_background);
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
}

Math::ivec2 CS230::Window::GetSize() {
    return window_size;
}

void CS230::Window::Clear(unsigned int color) {
    doodle::clear_background(doodle::HexColor{ color });
}

void CS230::Window::Update() {
    doodle::update_window();
}

void on_window_resized(int new_width, int new_height) {
    Engine::GetLogger().LogEvent("Window Resized");
    Engine::GetWindow().window_size.x = new_width;
    Engine::GetWindow().window_size.y = new_height;
}

