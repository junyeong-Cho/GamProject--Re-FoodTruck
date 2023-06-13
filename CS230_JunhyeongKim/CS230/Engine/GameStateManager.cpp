/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameStateManager.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    March 8, 2023
Updated:    June 9, 2023
*/

#include "GameStateManager.h"
#include "Engine.h"

CS230::GameStateManager::GameStateManager() { }


void CS230::GameStateManager::Update(double dt) 
{

    switch (status) {
    case Status::STARTING:
        if (gamestates.size() > 1)
        {
            SetNextGameState(0);
            status = Status::LOADING;
        }
        else
        {
            status = Status::STOPPING;
        }
        break;
    case Status::LOADING:
        current_gamestate = next_gamestate;

        Engine::GetLogger().LogEvent("Load " + current_gamestate->GetName());
        current_gamestate->Load();
        Engine::GetLogger().LogEvent("Load Complete");
        status = Status::UPDATING;
        break;

    case Status::UPDATING:
        if (current_gamestate != next_gamestate)
        {
            status = Status::UNLOADING;
        }
        else
        {
            Engine::GetLogger().LogVerbose("Update " + current_gamestate->GetName());
            current_gamestate->Update(dt);
            current_gamestate->Draw();
        }

        break;

    case Status::UNLOADING:
        Engine::GetLogger().LogEvent("Unload " + current_gamestate->GetName());
        
        current_gamestate->Unload();
        
        if (current_gamestate->GetName() != "Counter")
        {
            if (current_gamestate->GetName() != "Kitchen")
            {
                Engine::GetUnloadManager().GetCounterObjectManager().Unload();
                Engine::GetUnloadManager().Set_timer(500);
                Engine::GetUnloadManager().first_load = true;
                Engine::GetUnloadManager().Unload();
                /*Engine::GetTextureManager().Unload();*/
                Counter->ClearGSComponents();

            }
        }
        
        Engine::GetLogger().LogEvent("Unload Complete");
        if (next_gamestate == nullptr)
        {
            
            status = Status::STOPPING;
        }
        else
        {
            status = Status::LOADING;
        }
        break;
    case Status::STOPPING:
        status = Status::EXIT;
        break;
    case Status::EXIT:
        Engine::GetTextureManager().Unload();
        break;
    }
}



void CS230::GameStateManager::AddGameState(GameState& gamestate)
{
    gamestates.push_back(&gamestate);
    if (gamestate.GetName() == "Kitchen")
    {
        Kitchen = &gamestate;
    }

    if (gamestate.GetName() == "Counter")
    {
        Counter = &gamestate;
    }
}

void CS230::GameStateManager::SetNextGameState(int index)
{
    next_gamestate = gamestates[index];
}

void CS230::GameStateManager::ReloadGameState() 
{
    status = Status::UNLOADING;
}

void CS230::GameStateManager::ClearNextGameState() 
{
    next_gamestate = nullptr;
}
