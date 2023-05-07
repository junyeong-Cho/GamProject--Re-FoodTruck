#include "Cook.h"
#include <doodle/drawing.hpp>
#include <iostream>

extern bool leftClick;

Cook::Cook()
{
	for (int i = 0; i < ingredient_number; ++i)
	{
		seven_ingredients.push_back(std::vector<Ingredient*>());
	}
	Lemon* lemon1 = new Lemon(IngredientName::Lemon, Math::vec2{ first_X + width, first_Y }, 3, KitchenPosition::COUNTER1);
	Lemon* lemon2 = new Lemon(IngredientName::Lemon, Math::vec2{ first_X + width, first_Y }, 3, KitchenPosition::COUNTER1);
	Lemon* lemon3 = new Lemon(IngredientName::Lemon, Math::vec2{ first_X + width, first_Y }, 3, KitchenPosition::COUNTER1);

	Lettuce* lettuce1 = new Lettuce(IngredientName::Lettuce, Math::vec2{ first_X, first_Y }, 4, KitchenPosition::COUNTER2);
	Lettuce* lettuce2 = new Lettuce(IngredientName::Lettuce, Math::vec2{ first_X, first_Y }, 4, KitchenPosition::COUNTER2);
	Lettuce* lettuce3 = new Lettuce(IngredientName::Lettuce, Math::vec2{ first_X, first_Y }, 4, KitchenPosition::COUNTER2);

	Ant* ant1 = new Ant(IngredientName::Ant, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER3);
	Ant* ant2 = new Ant(IngredientName::Ant, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER3);
	Ant* ant3 = new Ant(IngredientName::Ant, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER3);

	Leaf* leaf1 = new Leaf(IngredientName::Leaf, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER4);
	Leaf* leaf2 = new Leaf(IngredientName::Leaf, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER4);
	Leaf* leaf3 = new Leaf(IngredientName::Leaf, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER4);

	Salt* salt1 = new Salt(IngredientName::Salt, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER5);
	Salt* salt2 = new Salt(IngredientName::Salt, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER5);
	Salt* salt3 = new Salt(IngredientName::Salt, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER5);

	DragonFruit* dragonFruit1 = new DragonFruit(IngredientName::DragonFruit, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER6);
	DragonFruit* dragonFruit2 = new DragonFruit(IngredientName::DragonFruit, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER6);
	DragonFruit* dragonFruit3 = new DragonFruit(IngredientName::DragonFruit, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER6);

	MermaidScales* mermaidScales1 = new MermaidScales(IngredientName::MermaidScales, Math::vec2{ first_X, first_Y }, 2, KitchenPosition::COUNTER6);
	MermaidScales* mermaidScales2 = new MermaidScales(IngredientName::MermaidScales, Math::vec2{ first_X, first_Y }, 2, KitchenPosition::COUNTER6);
	MermaidScales* mermaidScales3 = new MermaidScales(IngredientName::MermaidScales, Math::vec2{ first_X, first_Y }, 2, KitchenPosition::COUNTER6);

	if (seven_ingredients.size() == ingredient_number)
	{
		seven_ingredients[0].push_back(lemon1);
		seven_ingredients[0].push_back(lemon2);
		seven_ingredients[0].push_back(lemon3);

		seven_ingredients[1].push_back(lettuce1);
		seven_ingredients[1].push_back(lettuce2);
		seven_ingredients[1].push_back(lettuce3);

		seven_ingredients[2].push_back(ant1);
		seven_ingredients[2].push_back(ant2);
		seven_ingredients[2].push_back(ant3);

		seven_ingredients[3].push_back(leaf1);
		seven_ingredients[3].push_back(leaf2);
		seven_ingredients[3].push_back(leaf3);

		seven_ingredients[4].push_back(salt1);
		seven_ingredients[4].push_back(salt2);
		seven_ingredients[4].push_back(salt3);

		seven_ingredients[5].push_back(dragonFruit1);
		seven_ingredients[5].push_back(dragonFruit2);
		seven_ingredients[5].push_back(dragonFruit3);

		seven_ingredients[6].push_back(mermaidScales1);
		seven_ingredients[6].push_back(mermaidScales2);
		seven_ingredients[6].push_back(mermaidScales3);
	}
}

void Cook::Load()
{
	operation.Load();
	tool.Load();

	for (int i = 0; i < ingredient_number; ++i)
	{
		for (int j = 0; j < seven_ingredients[i].size(); ++j)
		{
			seven_ingredients[i][j]->Load();
		}
	}

}
void Cook::Set_Variables()
{
	Width_raito = Engine::GetWindow().GetSize().x / 1400.0;
	Height_raito = Engine::GetWindow().GetSize().y / 800.0;

	//origin
	endWidth = Width_raito * 1400.0;
	endHeight = Height_raito * 800.0;

	//side bowl
	first_X = Width_raito * 60.0;
	first_Y = Height_raito * 435.0; // 225.0;
	width = Width_raito * 170.0;
	height = Height_raito * 140.0;

	//cutting board
	cuttingBoard_X = Width_raito * 50.0;
	cuttingBoard_Y = Height_raito * 35.0; // 425.0;
	cuttingBoard_width = Width_raito * 570.0;
	cuttingBoard_height = Height_raito * 330.0;

	//bowl
	bowl_X = Width_raito * 800.0;
	bowl_Y = Height_raito * 220.0; // 580.0;
	bowl_width = Width_raito * 280.0;

	//stove
	stove_X = Width_raito * 980.0;
	stove_Y = Height_raito * 35.0; // 600.0;
	stove_width = Width_raito * 380.0;
	stove_height = Height_raito * 330.0;

	//trashCan

	//Bell
	bell_X = Width_raito * 1320.0;
	bell_Y = Height_raito * 505.0; // 295.0;
	bell_width = Width_raito * 100.0;

	//background
	topBackground_X1 = zero;
	topBackground_Y1 = endHeight;
	topBackground_X2 = endWidth;
	topBackground_Y2 = endHeight;
	topBackground_X3 = Width_raito * 1375.0;
	topBackground_Y3 = Height_raito * 600.0;
	topBackground_X4 = Width_raito * 25.0;
	topBackground_Y4 = topBackground_Y3;

	bottomBackground_X1 = topBackground_X4;
	bottomBackground_Y1 = topBackground_Y3;
	bottomBackground_X2 = topBackground_X3;
	bottomBackground_Y2 = topBackground_Y3;
	bottomBackground_X3 = endWidth;
	bottomBackground_Y3 = zero;
	bottomBackground_X4 = zero;
	bottomBackground_Y4 = zero;

	//clock
	clock_X = Width_raito * 35.0;
	clock_Y = Height_raito * 720.0;
	clock_width = Width_raito * 150.0;
	clock_height = Height_raito * 60.0;

	//receipt
	receipt_X = Width_raito * 250.0;
	receipt_Y = Height_raito * 680.0;
	receipt_width = Width_raito * 150.0;
	receipt_height = Height_raito * 100.0;

	//backCounterButton
	backCounter_X = Width_raito * 800.0;
	backCounter_Y = Height_raito * 610.0;
	backCounter_width = Width_raito * 220.0;
	backCounter_height = Height_raito * 60.0;

	//toollDrawer
	toolDrawer_X = Width_raito * 1050.0;
	toolDrawer_Y = Height_raito * 610.0;
	toolDrawer_width = Width_raito * 140.0;
	toolDrawer_height = Height_raito * 90.0;

	//refrigerator
	refrigerator_X = Width_raito * 1225.0;
	refrigerator_Y = Height_raito * 610.0;
	refrigerator_width = Width_raito * 100.0;
	refrigerator_height = Height_raito * 90.0;

	//tool Explain
	toolExplain_X = Width_raito * 450.0;
	toolExplain_Y = Height_raito * 680.0;
	toolExplain_width = Width_raito * 150.0;
	toolExplain_height = Height_raito * 100.0;
}

void Cook::Update(double dt)
{
	Set_Variables();
	operation.Update();
	tool.ChangeTool(operation.Return());
	SetIngredientsWhere();
	PutBowl();
}

void Cook::Draw()
{
	DrawIngredients();
	tool.Draw();

	//얘가 항상 제일 위에 그려져야함.
	operation.Draw();
}

void Cook::DrawIngredients()
{
	if (seven_ingredients.size() != 0)
	{
		for (int i = 0; i < seven_ingredients.size(); ++i)
		{
			if (seven_ingredients[i].size() != 0)
			{
				std::cout << seven_ingredients[i].size();
				for (int j = 0; j < seven_ingredients[i].size(); ++j)
				{
					seven_ingredients[i][j]->Draw();
				}
			}
		}
	}
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			using_ingredients[i]->Draw();
		}

	}
}

Math::vec2 Cook::WhereISMouse()
{
	return Math::vec2(doodle::get_mouse_x(), doodle::get_mouse_y());
}

KitchenPosition Cook::GetWhere(Math::vec2 pos)
{
	doodle::push_settings();
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
	if (pos.y > first_Y && pos.y < first_Y + height)
	{
		if (pos.x > first_X + width * 0 && pos.x <= first_X + width * 0 + width)
		{
			return KitchenPosition::COUNTER1;
		}
		else if (pos.x > first_X + width * 1 && pos.x <= first_X + width * 1 + width)
		{
			return KitchenPosition::COUNTER2;
		}
		else if (pos.x > first_X + width * 2 && pos.x <= first_X + width * 2 + width)
		{
			return KitchenPosition::COUNTER3;
		}
		else if (pos.x > first_X + width * 3 && pos.x <= first_X + width * 3 + width)
		{
			return KitchenPosition::COUNTER4;
		}
		else if (pos.x > first_X + width * 4 && pos.x <= first_X + width * 4 + width)
		{
			return KitchenPosition::COUNTER5;
		}
		else if (pos.x > first_X + width * 5 && pos.x <= first_X + width * 5 + width)
		{
			return KitchenPosition::COUNTER6;
		}
		else if (pos.x > first_X + width * 6 && pos.x <= first_X + width * 6 + width)
		{
			return KitchenPosition::COUNTER7;
		}
		else if (std::sqrt((std::pow((pos.x - bell_X), 2) + (std::pow((pos.y - bell_Y), 2)))) <= bell_width / 2.0)
		{
			return KitchenPosition::BELL;
		}
	}
	else if (pos.x > cuttingBoard_X && pos.x <= cuttingBoard_X + cuttingBoard_width
		&& pos.y > cuttingBoard_Y && pos.y < cuttingBoard_Y + cuttingBoard_height)
	{
		return KitchenPosition::CUTTING_BOARD;
	}
	else if (std::sqrt((std::pow((pos.x - bowl_X), 2) + (std::pow((pos.y - bowl_Y), 2)))) <= bowl_width / 2.0)
	{
		return KitchenPosition::BOWL;
	}
	else if (pos.x > stove_X && pos.x <= stove_X + stove_width
		&& pos.y > stove_Y && pos.y < stove_Y + stove_height)
	{
		return KitchenPosition::STOVE;
	}
	doodle::pop_settings();
	return KitchenPosition::ELSE;
}

void Cook::SetIngredientsWhere()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			using_ingredients[i]->ChangePalce(GetWhere(using_ingredients[i]->GetPos()));
		}
	}
}

void Cook::Cutting()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true && leftClick == true && GetWhere(WhereISMouse()) == KitchenPosition::CUTTING_BOARD)
			{
				if (using_ingredients[i]->GetCutNum() > 0)
				{
					using_ingredients[i]->Cut();
				}
				leftClick = false;
			}
		}
	}
}

void Cook::CreateUsingIngredient()
{
	if (seven_ingredients.size() != 0)
	{
		if (leftClick == true)
		{
			for (int i = 0; i < seven_ingredients.size(); ++i)
			{
				if (seven_ingredients[i].size() != 0)
				{
					for (int j = 0; j < seven_ingredients[i].size(); ++j)
					{
						if (seven_ingredients[i][j]->GetPlace() == GetWhere(WhereISMouse()) && whatMouseclickIndex == -1)
						{
							using_ingredients.push_back(seven_ingredients[i][j]);
							seven_ingredients[i].erase(seven_ingredients[i].begin() + j);
							whatMouseclickIndex = using_ingredients.size() - 1;
							leftClick = false;
						}
					}
				}
			}
		}
	}


}

int Cook::WhatIndexMouseClick()
{
	if (leftClick == true)
	{
		if (using_ingredients.size() != 0)
		{
			if (whatMouseclickIndex != -1)
			{
				whatMouseclickIndex = -1;
				leftClick = false;
			}
			else
			{
				for (int i = 0; i < using_ingredients.size(); ++i)
				{
					if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true)
					{
						whatMouseclickIndex = i;
						leftClick = false;
						break;
					}
				}
			}
		}
	}


	return whatMouseclickIndex;
}

void Cook::FollowMouseIngredient()
{
	if (using_ingredients.size() != 0 && WhatIndexMouseClick() != -1)
	{
		using_ingredients[WhatIndexMouseClick()]->ChangePos(WhereISMouse());
	}


}

void Cook::PutBowl()
{
	if (using_ingredients.size() != 0)
	{
		if (leftClick == true)
		{
			for (int i = 0; i < using_ingredients.size(); ++i)
			{
				if (using_ingredients[i]->GetPlace() == KitchenPosition::BOWL)
				{
					inPlate.push_back(using_ingredients[i]);
					using_ingredients.erase(using_ingredients.begin() + i);
					whatMouseclickIndex = -1;
					break;
				}
			}
		}
	}
}
