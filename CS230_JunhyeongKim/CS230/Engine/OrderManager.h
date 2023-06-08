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
