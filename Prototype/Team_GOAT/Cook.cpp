#include "Cook.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>
#include <cmath>
#include <iostream>


//static함수는 전역범위에서만 초기화 가능. & 헤더 파일에선 초기화 불가능.
bool Cook::isMouseClick = false;
Tool Cook::whatTool = Tool::HAND;

Cook::Cook()
{
	Lettuce* lettuce1 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y });
	Lettuce* lettuce2 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y });
	Lettuce* lettuce3 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y });
	
	Sauce* sauce1 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y });
	Sauce* sauce2 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y });
	Sauce* sauce3 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y });

	for (int i = 0; i < ingredient_number; ++i)
	{
		seven_ingredients.push_back(std::vector<Ingredient*>());
	}
	
	if (seven_ingredients.size() != 0)
	{
		seven_ingredients[0].push_back(lettuce1);
		seven_ingredients[0].push_back(lettuce2);
		seven_ingredients[0].push_back(lettuce3);

		seven_ingredients[1].push_back(sauce1);
		seven_ingredients[1].push_back(sauce2);
		seven_ingredients[1].push_back(sauce3);
	}
}

void Cook::Update()
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);

	DrawIngredients();
	WriteCuttingNum();
	SetIngredientsWhere();
	DrawToolName();
	if (whatTool == Tool::HAND)
	{
		CreateUsingIngredient();
		FollowMouseIngredient();
		WhatIndexMouseClick();
	}
	else if (whatTool == Tool::KNIFE)
	{
		Cutting();
	}
	
	doodle::pop_settings();
}


void Cook::DrawIngredients()
{
	if (seven_ingredients.size() != 0)
	{
		for (int i = 0; i < seven_ingredients.size(); ++i)
		{
			if (seven_ingredients[i].size() != 0)
			{
				for (int j = 0; j < seven_ingredients[i].size(); ++j)
				{
					seven_ingredients[i][j]->DrawImage();
				}
			}
		}
	}
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			using_ingredients[i]->DrawImage();
		}

	}
}




Math::vec2 Cook::WhereISMouse()
{
	return Math::vec2(doodle::get_mouse_x(), doodle::get_mouse_y());
}

KitchenPosition Cook::GetWhere(Math::vec2 pos)
{
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
	}
	else if (pos.x > cuttingBoard_X && pos.x <= cuttingBoard_X + cuttingBoard_width
		&& pos.y > cuttingBoard_Y && pos.y < cuttingBoard_Y + cuttingBoard_height)
	{
		return KitchenPosition::CUTTING_BOARD;
	}
	else if (std::sqrt((std::pow((pos.x - bowl_X), 2) + (std::pow((pos.y - bowl_Y), 2)))) <= bowl_width)
	{
		return KitchenPosition::BOWL;
	}
	else if (std::sqrt((std::pow((pos.x - stove_X), 2) + (std::pow((pos.y - stove_Y), 2)))) <= stove_width)
	{
		return KitchenPosition::STOVE;
	}
	else if (pos.x > trashCan_X && pos.x <= trashCan_X + trashCan_width
		&& pos.y > trashCan_Y && pos.y < trashCan_Y + trashCan_height)
	{
		return KitchenPosition::TRASH_CAN;
	}
	
	return KitchenPosition::ELSE;
}

void Cook::SetIngredientsWhere()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			using_ingredients[i]->where = GetWhere(using_ingredients[i]->position);
		}
	}
}

void Cook::WriteCuttingNum()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->where != KitchenPosition::CUTTING_BOARD)
			{
				cuttingBoardIndex = -1;
			}
			else if (using_ingredients[i]->where == KitchenPosition::CUTTING_BOARD)
			{
				cuttingBoardIndex = i;
				break;
			}
		}
	}
	if (cuttingBoardIndex != -1)
	{
		if (using_ingredients[cuttingBoardIndex]->cuttingNum > 0)
		{
			doodle::draw_text("Cut : " + std::to_string(using_ingredients[cuttingBoardIndex]->cuttingNum), cuttingBoard_X + 20, cuttingBoard_Y + 20);
		}
		else
		{
			doodle::draw_text("Done. Move ingredient", cuttingBoard_X + 20, cuttingBoard_Y + 20);
		}

	}
	else
	{
		doodle::draw_text("Put Ingredient", cuttingBoard_X + 20, cuttingBoard_Y + 20);
	}
}

void Cook::Cutting()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true && isMouseClick == true && GetWhere(WhereISMouse()) == KitchenPosition::CUTTING_BOARD)
			{
				--using_ingredients[i]->cuttingNum;
				isMouseClick = false;
			}
		}
	}
}

void on_key_pressed(doodle::KeyboardButtons button)
{
	if (button == doodle::KeyboardButtons::Z)
	{
		Cook::whatTool = Tool::KNIFE;
	}
	if (button == doodle::KeyboardButtons::X)
	{
		Cook::whatTool = Tool::HAND;
	}
}

void Cook::CreateUsingIngredient()
{
	if (seven_ingredients.size() != 0)
	{
		if (isMouseClick == true)
		{
			for (int i = 0; i < seven_ingredients.size(); ++i)
			{
				if (seven_ingredients[i].size() != 0)
				{
					for (int j = 0; j < seven_ingredients[i].size(); ++j)
					{
						if (seven_ingredients[i][j]->where == GetWhere(WhereISMouse()) && whatMouseclickIndex == -1)
						{
							using_ingredients.push_back(seven_ingredients[i][j]);
							seven_ingredients[i].erase(seven_ingredients[i].begin() + j);
							whatMouseclickIndex = using_ingredients.size() - 1;
							isMouseClick = false;
						}
					}
				}
			}
		}
	}


}

int Cook::WhatIndexMouseClick()
{
	if (isMouseClick == true)
	{
		if (using_ingredients.size() != 0)
		{
			if (whatMouseclickIndex != -1)
			{
				whatMouseclickIndex = -1;
				isMouseClick = false;
			}
			else
			{
				for (int i = 0; i < using_ingredients.size(); ++i)
				{
					if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true)
					{
						whatMouseclickIndex = i;
						isMouseClick = false;
						break;
					}
				}
			}
		}
	}
	return whatMouseclickIndex;
}

void on_mouse_pressed(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Left && Cook::isMouseClick == false)
	{
		Cook::isMouseClick = true;
		
	}
}

void on_mouse_released(doodle::MouseButtons button)
{
	if (button == doodle::MouseButtons::Left)
	{
		Cook::isMouseClick = false;
	}
}


void Cook::FollowMouseIngredient()
{
	if (using_ingredients.size() != 0 && WhatIndexMouseClick() != -1)
	{
		using_ingredients[WhatIndexMouseClick()]->ChangePos(WhereISMouse());
	}
}

void Cook::DrawToolName()
{
	if (whatTool == Tool::HAND)
	{
		doodle::draw_text("Tool : Hand", cuttingBoard_X + 20, cuttingBoard_Y + cuttingBoard_height + 100);
	}
	else if(whatTool == Tool::KNIFE)
	{
		doodle::draw_text("Tool : Knife", cuttingBoard_X + 20, cuttingBoard_Y + cuttingBoard_height + 100);
	}
}

double Cook::GetPercentOfComplete()
{
	return 100.0;
}
