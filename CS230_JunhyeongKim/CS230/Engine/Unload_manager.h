/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Unload_manager.h
Project:    Gam 150
Author:     Junhyeong Kim
Created:    March 8, 2023
*/

#pragma once
#include "GameObjectManager.h"

namespace CS230
{
	class Unload_manager
	{
	public:
		void Save_Counter_object(GameObjectManager object_manager);
		GameObjectManager& GetCounterObjectManager() { return counter_ObjectManager; }
		const int GetMoney() { return money; }
		const int GetRate() { return rate; }
		const double GetTimer() { return timer; }

		void Update_money(int i) { money += i; }
		void Update_rate(int i) { rate += i; }
		void Update_timer(double dt) { timer -= dt; }

		void Set_money(int i) { money = i; }
		void Set_rate(int i) { rate = i; }
		void Set_timer(double dt) { timer = dt; }
		bool first_load = true;
	private:
		GameObjectManager counter_ObjectManager;
		int money = 100;
		int rate = 100;
		double timer = 100;
	};
}