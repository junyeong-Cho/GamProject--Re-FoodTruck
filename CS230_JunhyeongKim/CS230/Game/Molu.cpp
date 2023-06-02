/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Molu.cpp
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    March 3, 2023
*/

#include "Molu.h"

Molu::Molu(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/Molu.spt");
}