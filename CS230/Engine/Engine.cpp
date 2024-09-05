/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Engine.cpp
Project:    GAM150
Author:     Jonathan Holmes, Junhyeong Kim
Created:    March 8, 2023
Updated:    April 27, 2023
*/
#pragma once
#include <stdlib.h>
#include "Engine.h"


Engine::Engine() :
#ifdef _DEBUG				
    logger(CS230::Logger::Severity::Debug, true, last_tick)
#else 						
    logger(CS230::Logger::Severity::Event, false, last_tick)
#endif
{}

Engine::~Engine() {}

void Engine::Start(std::string window_title) 
{
    logger.LogEvent("Engine Started");
    window.Start(window_title);
    //Start other services
    last_test = last_tick;
    srand(time(nullptr));
    unsigned int seed = rand();
    logger.LogEvent(std::to_string(seed));
}

void Engine::Stop() {
    //Stop all services
    logger.LogEvent("Engine Stopped");
}

void Engine::Update() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();
   
    
    if (dt > 1 / TargetFPS)
    {
        logger.LogVerbose("Engine Update");
        last_tick = now;

        frame_count++;
        if (frame_count >= FPSTargetFrames)
        {
            double actual_time = std::chrono::duration_cast<std::chrono::duration<double>>(now - last_test).count();
            logger.LogDebug("FPS: " + std::to_string(frame_count / actual_time));
            frame_count = 0;
            last_test = now;
        }
        gamestatemanager.Update(dt);
        input.Update();
        window.Update();
        draw_manager.Update(window.GetSize());
    }
    //Update other services
}

bool Engine::HasGameEnded()
{
    return gamestatemanager.HasGameEnded();
}