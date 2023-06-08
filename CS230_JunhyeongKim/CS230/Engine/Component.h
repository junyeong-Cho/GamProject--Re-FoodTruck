/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Collision.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    March  8, 2023
Updated:    April  3, 2023
*/

#pragma once


namespace CS230
{
	class Component
	{
	public:
		virtual ~Component() {};
		virtual void Update(double) {};
	};
}