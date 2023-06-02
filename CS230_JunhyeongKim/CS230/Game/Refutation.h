/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Refutation.h
Project:    CS230 Engine
Author:     Junyeong cho
Created:    March 8, 2023
Updated:    May  28, 2023
*/

#pragma once

#include "doodle/drawing.hpp" 

#include "../Engine/GameObjectManager.h"
#include "../Engine/Unload_manager.h"
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Engine/Engine.h"


class Refutation : public CS230::GameObject
{
public:
    Refutation(Math::vec2 position);

    void Update(double dt) override;

    void DrawRefutation();

private:

    enum class Animations
    {
        Idle,
        Happy,
        Normal,
        Angry
    };


    class State_Idle : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };

    class State_Happy : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Happy"; }
    };

    class State_Normal : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Normal"; }
    };

    class State_Angry : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Angry"; }
    };

    State_Idle state_idle;

    State_Happy state_happy;

    State_Normal state_normal;

    State_Angry state_angry;

};