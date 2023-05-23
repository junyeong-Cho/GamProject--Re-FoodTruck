/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Anteater.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    March 2, 2023
*/
#include "Anteater.h"

Anteater::Anteater(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Anteater.spt");
}