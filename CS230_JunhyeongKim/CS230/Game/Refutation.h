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

#include "../Engine/GameObjectManager.h"



class Refutation : public CS230::GameObject
{
public:
	Refutation(Math::vec2 position, int size);


	void Load() override;
	void Update(double dt) override;


};