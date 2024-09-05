/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameState.h
Project:    GAM150
Author:     Junyeong Cho
Created:    March 8, 2023
Updated:    May   3, 2023
*/

#pragma once

#include "../Engine/ComponentManager.h"

#include <string>



namespace CS230 {
    class GameState {
    public:
        virtual void Load() = 0;
        virtual void Update(double dt) = 0;
        virtual void Unload() = 0;
        virtual void Draw() = 0;

        virtual std::string GetName() = 0;

        template<typename T>
        T* GetGSComponent()
        {
            return componentmanager.GetComponent<T>();
        }
        void ClearGSComponents()
        {
            componentmanager.Clear();
        }
    protected:
        void AddGSComponent(Component* component)
        {
            componentmanager.AddComponent(component);
        }

        void UpdateGSComponents(double dt)
        {
            componentmanager.UpdateAll(dt);
        }

        template<typename T>
        void RemoveGSComponent()
        {
            componentmanager.RemoveComponent<T>();
        }



    private:
        ComponentManager componentmanager;

    };
}
