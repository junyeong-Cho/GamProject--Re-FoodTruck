/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameObjectManager.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    April 25, 2023
*/

#include "GameObjectManager.h"

//like load
void CS230::GameObjectManager::Add(GameObject* object)
{
	objects.push_back(object);
}


void CS230::GameObjectManager::UpdateAll(double dt)
{
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->Update(dt);
    }
}

void CS230::GameObjectManager::DrawAll(Math::TransformationMatrix camera_matrix)
{
    for (int i = objects.size() - 1; i >= 0; i--)
    {
        objects[i]->Draw(camera_matrix);
    }
}

void CS230::GameObjectManager::Unload()
{
    for (GameObject* object : objects) {
        delete object;
    }
    objects.clear();
}