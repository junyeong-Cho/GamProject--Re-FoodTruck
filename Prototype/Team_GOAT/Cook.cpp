#include "Cook.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>
#include <math.h>
#include <iostream>


//static함수는 전역범위에서만 초기화 가능. & 헤더 파일에선 초기화 불가능.
bool Cook::isMouseClick = false;
Tool Cook::whatTool = HAND;

Cook::Cook()
{
	Lettuce* lettuce = new Lettuce(COUNTER1, Math::vec2{100, 80});
	Sauce* sauce= new Sauce(COUNTER2, Math::vec2{ 250, 80});
	
	seven_ingredients.push_back(lettuce);
	seven_ingredients.push_back(sauce);
}


void Cook::Update()
{
	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	DrawGrid();
	DrawCuttingBoard();
	DrawBowl(); 
	DrawStove();
	DrawIngredients();
	WriteCuttingNum();
	SetIngredientsWhere();
	if (whatTool == HAND)
	{
		CreateUsingIngredient();
		FollowMouseIngredient();
		WhatIndexMouseClick();
	}
	else if (whatTool == KNIFE)
	{
		Cutting();
	}
}

void Cook::DrawIngredients()
{
	if (seven_ingredients.size() != 0)
	{
		for (int i = 0; i < seven_ingredients.size(); ++i)
		{
			seven_ingredients[i]->DrawImage();
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

void Cook::DrawGrid()
{
	for (int i = 0; i < ingredient_number; ++i)
	{
		doodle::draw_rectangle(first_X + (width * i), first_Y, width, height);
	}
}

void Cook::DrawCuttingBoard()
{
	doodle::draw_rectangle(cuttingBoard_X, cuttingBoard_Y, cuttingBoard_width, cuttingBoard_height);
}

void Cook::DrawBowl()
{
	doodle::draw_ellipse(bowl_X, bowl_Y, bowl_width);
}

void Cook::DrawStove()
{
	doodle::draw_ellipse(stove_X, stove_Y, stove_width);
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
			return COUNTER1;
		}
		else if (pos.x > first_X + width * 1 && pos.x <= first_X + width * 1 + width)
		{
			return COUNTER2;
		}
		else if (pos.x > first_X + width * 2 && pos.x <= first_X + width * 2 + width)
		{
			return COUNTER3;
		}
		else if (pos.x > first_X + width * 3 && pos.x <= first_X + width * 3 + width)
		{
			return COUNTER4;
		}
		else if (pos.x > first_X + width * 4 && pos.x <= first_X + width * 4 + width)
		{
			return COUNTER5;
		}
		else if (pos.x > first_X + width * 5 && pos.x <= first_X + width * 5 + width)
		{
			return COUNTER6;
		}
		else if (pos.x > first_X + width * 6 && pos.x <= first_X + width * 6 + width)
		{
			return COUNTER7;
		}
	}
	else if (pos.x > cuttingBoard_X && pos.x <= cuttingBoard_X + cuttingBoard_width
		&& pos.y > cuttingBoard_Y && pos.y < cuttingBoard_Y + cuttingBoard_height)
	{
		return CUTTING_BOARD;
	}
	else if (std::sqrt((std::pow((pos.x - bowl_X), 2) + (std::pow((pos.y - bowl_Y), 2)))) <= bowl_width)
	{
		return BOWL;
	}
	else if (std::sqrt((std::pow((pos.x - stove_X), 2) + (std::pow((pos.y - stove_Y), 2)))) <= stove_width)
	{
		return STOVE;
	}
	else if (pos.x > trashCan_X && pos.x <= trashCan_X + trashCan_width
		&& pos.y > trashCan_Y && pos.y < trashCan_Y + trashCan_height)
	{
		return TRASH_CAN;
	}
	
	return ELSE;
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
			if (using_ingredients[i]->where != CUTTING_BOARD)
			{
				cuttingBoardIndex = -1;
			}
			else if (using_ingredients[i]->where == CUTTING_BOARD)
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
			if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true && isMouseClick == true && GetWhere(WhereISMouse()) == CUTTING_BOARD)
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
		Cook::whatTool = KNIFE;
	}
	if (button == doodle::KeyboardButtons::X)
	{
		Cook::whatTool = HAND;
	}
	std::cout << Cook::whatTool << '\n';
}

void Cook::CreateUsingIngredient()
{
	if (seven_ingredients.size() != 0)
	{
		if (isMouseClick == true)
		{
			for (int i = 0; i < seven_ingredients.size(); ++i)
			{
				if (seven_ingredients[i]->where == GetWhere(WhereISMouse()) && whatMouseclickIndex == -1)
				{
					using_ingredients.push_back(seven_ingredients[i]);
					seven_ingredients.erase(seven_ingredients.begin() + i);
					whatMouseclickIndex = using_ingredients.size() - 1;
					isMouseClick = false;
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



double Cook::GetPercentOfComplete()
{
	return 100.0;
}
