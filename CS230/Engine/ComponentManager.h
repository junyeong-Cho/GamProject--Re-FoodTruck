/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  ComponenetManager.h
Project:    GAM150
Author:     Jonathan Holmes, Junyeong Cho
Created:    March  8, 2023
Updated:    May   15, 2023
*/

#pragma once

#include <vector>
#include <algorithm>

#include "Component.h"



namespace CS230
{
    class ComponentManager
    {
    public:
        ~ComponentManager() { }

        void UpdateAll(double dt)
        {
            for (Component* component : components)
            {
                component->Update(dt);
            }
        }

        void AddComponent(Component* component)
        {
            components.push_back(component);
        }

        template<typename T>
        T* GetComponent()
        {
            for (Component* component : components)
            {
                T* ptr = dynamic_cast<T*>(component);
                if (ptr != nullptr)
                {
                    return ptr;
                }
            }
            return nullptr;
        }

        template<typename T>
        void RemoveComponent()
        {
            auto it = std::find_if
            (
                components.begin(), components.end(), [](Component* element)
                {
                    return (dynamic_cast<T*>(element) != nullptr);
                }
            );

            delete* it;
            components.erase(it);
        }
        void Clear()
        {
            for (Component* component : components)
            {
                delete component;
            }

            components.clear();
        }

    private:
        std::vector<Component*> components;
    };
}

