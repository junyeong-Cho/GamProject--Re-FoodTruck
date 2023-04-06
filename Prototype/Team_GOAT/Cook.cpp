#include "Cook.h"
#include <doodle/drawing.hpp>
#include <doodle/input.hpp>
#include <cmath>
#include <iostream>
#include "State.h"


//static함수는 전역범위에서만 초기화 가능. & 헤더 파일에선 초기화 불가능.
bool Cook::isMouseClick = false;
Tool Cook::whatTool = Tool::HAND;

extern State* state;

Cook::Cook()
{
	Lettuce* lettuce1 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y }, IngredientName::Lettuce);
	Lettuce* lettuce2 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y }, IngredientName::Lettuce);
	Lettuce* lettuce3 = new Lettuce(KitchenPosition::COUNTER1, Math::vec2{ first_X, first_Y }, IngredientName::Lettuce);
	
	Sauce* sauce1 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y }, IngredientName::Sauce);
	Sauce* sauce2 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y }, IngredientName::Sauce);
	Sauce* sauce3 = new Sauce(KitchenPosition::COUNTER2, Math::vec2{ first_X + width, first_Y }, IngredientName::Sauce);

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
	ChangeIngredientSize();
	PutBowl();
	Salad();
	if (whatTool == Tool::HAND)
	{
		CreateUsingIngredient();
		FollowMouseIngredient();
		WhatIndexMouseClick();
		PutBell();
	}
	else if (whatTool == Tool::KNIFE)
	{
		Cutting();
	}
	Draw_CompletePoint();
	
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
	else if(pos.x > bell_X && pos.x <= bell_X + bell_width
		&& pos.y > bell_Y && pos.y < bell_Y + bell_height)
	{
		return KitchenPosition::BELL;
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
			if (using_ingredients[i]->where == KitchenPosition::CUTTING_BOARD)
			{
				doodle::push_settings();
				doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
				doodle::set_font_size(width/10.0);
				if (using_ingredients[i]->cuttingNum > 0)
				{
					doodle::draw_text("Cut\n" + std::to_string(using_ingredients[i]->cuttingNum) + " / 5",
						using_ingredients[i]->position.x - using_ingredients[i]->spriteHalfWidth / 2.0,
						using_ingredients[i]->position.y);
				}
				else
				{
					doodle::draw_text("Done", 
						using_ingredients[i]->position.x - using_ingredients[i]->spriteHalfWidth / 2.0,
						using_ingredients[i]->position.y);
				}
				
				doodle::pop_settings();
			}
		}
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
				if (using_ingredients[i]->cuttingNum > 0)
				{
					--using_ingredients[i]->cuttingNum;
				}
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
	doodle::push_settings();
	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_font_size(width / 10.0);
	if (whatTool == Tool::HAND)
	{
		doodle::draw_text("Tool : Hand", first_X, cuttingBoard_Y - cuttingBoard_height /20.0);
	}
	else if(whatTool == Tool::KNIFE)
	{
		doodle::draw_text("Tool : Knife", first_X, cuttingBoard_Y - cuttingBoard_height / 20.0);
	}
	doodle::pop_settings();
}

void Cook::ChangeIngredientSize() 
{
	if (seven_ingredients.size() != 0)
	{
		for (int i = 0; i < seven_ingredients.size(); ++i)
		{
			if (seven_ingredients[i].size() != 0)
			{
				for (int j = 0; j < seven_ingredients[i].size(); ++j)
				{
					seven_ingredients[i][j] -> position = Math::vec2{ first_X + (width * i) + (width / 2.0) , first_Y + height / 2.0 };
					seven_ingredients[i][j]-> spriteHalfWidth = width / 4.0;
				}
			}
		}
	}

	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			//이거 position을 어떻게 바꿔야할지 모르겠음.;
			using_ingredients[i]->spriteHalfWidth = width / 4.0;
		}
	}
}

void Cook::PutBowl()
{
	if (using_ingredients.size() != 0)
	{
		if (isMouseClick == true)
		{
			for (int i = 0; i < using_ingredients.size(); ++i)
			{
				if (using_ingredients[i]->where == KitchenPosition::BOWL)
				{
					inBowl.push_back(using_ingredients[i]);
					using_ingredients.erase(using_ingredients.begin() + i);
					whatMouseclickIndex = -1;
					break;
				}
			}
		}
	}
}

void Cook::Salad() // 점수 계산을 손봐야함.
{
	int needdLettuceNum = 3; // 필요한 상추 갯수
	int nowLettuceNum = 0; // 만족하는 상추 갯수
	int lettuceCutNum = 0; // 샐러드 만들 때 상추가 칼질되고 남아 있어야 하는 횟수.

	int needSuaceNum = 2; //필요한 소스 갯수
	int nowSuaceNum = 0; //만족하는 소스 갯수
	int sauceCutNum = 0; // 샐러드 만들 때 소스가 칼질되고 남아 있어야 하는 횟수.

	int point = 0;

	if (inBowl.size() != 0)
	{
		for (int i = 0; i < inBowl.size(); ++i)
		{
			if (inBowl[i]->name == IngredientName::Lettuce)
			{
				if (inBowl[i]->cuttingNum == lettuceCutNum)
				{
					nowLettuceNum += 1;
					point += 20;
				}
				else
				{
					point += 15;
				}
			}
			else if (inBowl[i]->name == IngredientName::Sauce)
			{
				if (inBowl[i]->cuttingNum == sauceCutNum)
				{
					nowSuaceNum += 1;
					point += 20;
				}
				else
				{
					point += 15;
				}
			}
		}

		if (nowLettuceNum == needdLettuceNum && nowSuaceNum == needSuaceNum)
		{
			point = 100;
		}
		else if (nowLettuceNum != needdLettuceNum && nowSuaceNum != needSuaceNum)
		{
			point -= 10;
		}
		else
		{
			point -= 10;
		}
	}
	completePoint = point;
}

void Cook::Draw_CompletePoint()
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_font_size(width/10.0);
	doodle::draw_text("Complete : " + std::to_string(completePoint) + "%", first_X, first_Y/1.2);

	doodle::pop_settings();
}

int Cook::GetPercentOfComplete()
{
	return completePoint;
}

void Cook::PutBell()
{
	if (GetWhere(WhereISMouse()) == KitchenPosition::BELL && isMouseClick == true)
	{
		*state = State::Counter;
	}
}
