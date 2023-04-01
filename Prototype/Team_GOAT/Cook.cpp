#include "Cook.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>
#include <math.h>
#include <iostream>

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
	CreateUsingIngredient();
	FollowMouseIngredient();
	SetIsClick();
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

// 칼을 든 상태에서는 재료를 클릭할 때 칼질이 되고, 칼을 두고 재료를 클릭할 땐 그냥 위치 이동되게 해야함.
void Cook::Cutting()
{
	if (doodle::MouseButton == doodle::MouseButtons::Left)
	{
		if (WhereISMouse().x > cuttingBoard_X && WhereISMouse().x < cuttingBoard_X + cuttingBoard_width
			&& WhereISMouse().y > cuttingBoard_Y && WhereISMouse().y < cuttingBoard_Y + cuttingBoard_height)
		{
			if (using_ingredients.size() != 0)
			{
				for (int i = 0; i < using_ingredients.size(); ++i)
				{
					if (using_ingredients[i]->where == CUTTING_BOARD)
					{
						if (using_ingredients[i]->cuttingNum > 0)
						{
							--using_ingredients[i]->cuttingNum;
						}
					}
				}
				
			}
		}
	}
}

void Cook::WriteCuttingNum()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->where == CUTTING_BOARD)
			{
				doodle::draw_text(std::to_string(using_ingredients[i]->cuttingNum), cuttingBoard_X + 20, cuttingBoard_Y + 20);
			}
		}
	}
}


void Cook::CreateUsingIngredient()
{
	if (seven_ingredients.size() != 0)
	{
		if (doodle::MouseButton == doodle::MouseButtons::Left)
		{
			for (int i = 0; i < seven_ingredients.size(); ++i)
			{
				if (seven_ingredients[i]->where == GetWhere(WhereISMouse()))
				{
					using_ingredients.push_back(seven_ingredients[i]);
					using_ingredients[using_ingredients.size() - 1]->isClick = true;
				}
			}
		}
	}
}

void Cook::FollowMouseIngredient()
{
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->isClick == true)
			{
				using_ingredients[i]->ChangePos(WhereISMouse());
			}
		}
	}
}

void Cook::SetIsClick()
{
	//이부분 고장남 고쳐야함.
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			if (using_ingredients[i]->IsMouseOn(WhereISMouse()) == true && doodle::MouseButton == doodle::MouseButtons::Left)
			{
				if (using_ingredients[i]->isClick == false)
				{
					using_ingredients[i]->isClick = true;
					break;
				}
				if (using_ingredients[i]->isClick == true)
				{
					using_ingredients[i]->isClick = false;
					break;
				}
			}
		}
	}
}

double Cook::GetPercentOfComplete()
{
	return 100.0;
}
