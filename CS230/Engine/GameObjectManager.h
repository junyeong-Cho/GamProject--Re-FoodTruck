/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameObjectManager.h
Project:    GAM150
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include <vector>
#include "GameObject.h"
#include "Matrix.h"

namespace Math { class TransformationMatrix; }

namespace CS230 {
    class GameObjectManager {
    public:
        void Add(GameObject* object);
        void Unload();

        void UpdateAll(double dt);
        void DrawAll(Math::TransformationMatrix camera_matrix);

        GameObject* get_object(int i) { return objects[i]; }
        int GetSize() { return static_cast<int>(objects.size()); }
    private:
        std::vector<GameObject*> objects;
    };
}
