/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Junhyeong Kim
Created:    March 8, 2023
Updated:    April 27, 2023
*/
#pragma once
#include <chrono>
#include "Window.h"
#include "Logger.h"
#include "GameStateManager.h"
#include "TextureManager.h"
#include "Input.h"
#include "Unload_manager.h"

class Engine {
public:
    static Engine& Instance() {
        static Engine instance;
        return instance;
    }
    static CS230::Logger& GetLogger() {
        return Instance().logger;
    }
    static CS230::Window& GetWindow() {
        return Instance().window;
    }
    static CS230::GameStateManager& GetGameStateManager()
    {
        return Instance().gamestatemanager;
    }
    static CS230::TextureManager& GetTextureManager() {
        return Instance().texturemanager;
    }
    static CS230::Input& GetInput() {
        return Instance().input;
    }
    static CS230::Unload_manager& GetUnloadManager() {
        return Instance().unload_manager;
    }

    void Start(std::string window_title);
    void Stop();
    void Update();
    bool HasGameEnded();
private:
    Engine();
    ~Engine();

    std::chrono::system_clock::time_point last_tick = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point last_test;

    int frame_count = 0;

    static constexpr double TargetFPS = 60.0;
    static constexpr int FPSDuration = 5;
    static constexpr int FPSTargetFrames = static_cast<int>(FPSDuration * TargetFPS);

    CS230::TextureManager texturemanager;
    CS230::GameStateManager gamestatemanager;
    CS230::Logger logger;
    CS230::Window window;
    CS230::Input input;
    CS230::Unload_manager unload_manager;
};
