/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameStateManager.h
Project:    GAM150
Author:     Jonathan Holmes, Junyeong Cho
Created:    March 8, 2023
*/
#pragma once
#include "GameState.h"
#include <vector>

namespace CS230 {
    class GameStateManager {
    public:
        GameStateManager();

        void Update(double dt);

        void AddGameState(GameState& gamestate);
        void SetNextGameState(int index);
        void ClearNextGameState();
        void ReloadGameState();
        bool HasGameEnded() { return status == Status::EXIT; }

        GameState* GetCurrentGameState() { return current_gamestate; }

        template<typename T>
        T* GetGSComponent()
        {
            return current_gamestate->GetGSComponent<T>();
        }


    private:
        enum class Status 
        {
            STARTING,
            LOADING,
            UPDATING,
            UNLOADING,
            STOPPING,
            EXIT
        };

        Status status = Status::STARTING;
        std::vector<GameState*> gamestates;
        GameState* current_gamestate = nullptr;
        GameState* next_gamestate = nullptr;

        GameState* Kitchen = nullptr;
        GameState* Counter = nullptr;

    };
}
