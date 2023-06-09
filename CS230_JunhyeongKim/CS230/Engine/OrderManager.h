/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  OrderManager.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    June 2, 2023
*/
#pragma once
#include "..\Game\RecipeName.h"

namespace CS230
{
	class OrderManager
	{
	public:
		void SetOrder(RecipeName orderRecipe) { order = orderRecipe; }
		RecipeName GetOrder() { return order; }

	private:
		RecipeName order = RecipeName::LemonSalad;
	};
}
