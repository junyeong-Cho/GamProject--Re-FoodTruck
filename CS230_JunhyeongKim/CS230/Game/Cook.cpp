#include "Cook.h"
#include <doodle/drawing.hpp>
#include <iostream>

extern bool leftClick;

Cook::Cook() : plate(Plate(Math::vec2{650.0, 80.0})), pot(Pot(Math::vec2{1000.0,-10.0}))
{
	Set_Variables();
	for (int i = 0; i < ingredient_number; ++i)
	{
		seven_ingredients.push_back(std::vector<Ingredient*>());
	}

	if (seven_ingredients.size() == ingredient_number)
	{
		for (int i = 0; i < 20; ++i)
		{
			seven_ingredients[0].push_back(new Lemon(IngredientName::Lemon, Math::vec2{ first_X + width, first_Y }, 3, KitchenPosition::COUNTER1));
			seven_ingredients[1].push_back(new Lettuce(IngredientName::Lettuce, Math::vec2{ first_X, first_Y }, 4, KitchenPosition::COUNTER2));
			seven_ingredients[2].push_back(new Ant(IngredientName::Ant, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER3));
			seven_ingredients[3].push_back(new Leaf(IngredientName::Leaf, Math::vec2{ first_X, first_Y }, 1, KitchenPosition::COUNTER4));
			seven_ingredients[4].push_back(new Salt(IngredientName::Salt, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER5));
			seven_ingredients[5].push_back(new DragonFruit(IngredientName::DragonFruit, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER6));
			seven_ingredients[6].push_back(new MermaidScales(IngredientName::MermaidScales, Math::vec2{ first_X, first_Y }, 3, KitchenPosition::COUNTER7));
		}
	}
}

void Cook::Load()
{
	operation.Load();
	tool.Load();
	plate.Load();
	pot.Load();

	for (int i = 0; i < ingredient_number; ++i)
	{
		for (int j = 0; j < seven_ingredients[i].size(); ++j)
		{
			seven_ingredients[i][j]->Load();
		}
	}
	ChangeIngredientPos();
}

void Cook::Unload()
{
	plate.Unload();
	pot.Unload();
	for (int i = 0; i < seven_ingredients.size(); ++i)
	{
		for (int j = 0; j < seven_ingredients[i].size(); ++j)
		{
			delete seven_ingredients[i][j];
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
	SetStoveOn();
	if (stoveOn == true)
	{
		time += dt;
	}
	Set_Variables();
	operation.Update();
	tool.ChangeTool(operation.Return());
	SetIngredientsWhere();
	PutSlot();
	CreateUsingIngredient();
	plate.Update(dt);
	pot.Update(dt);

	GetWhere(WhereISMouse());

	if (tool.GetTool() == ToolName::HAND)
	{
		FollowMouseIngredient();
	}
	else if (tool.GetTool() == ToolName::KNIFE)
	{
		Cutting();
	}
	else if (tool.GetTool() == ToolName::LADLE)
	{
		SpotToPlate();
	}
}

void Cook::Draw()
{
	SlotDraw();
	DrawIngredients();
	tool.Draw();
	plate.ButtonDraw();
	pot.ButtonDraw();
	DrawGage();
	DrawTempSoup();
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
	else if (std::sqrt((std::pow((pos.x - 800), 2) + (std::pow((pos.y - 230), 2)))) <= 150.0)
	{
		return KitchenPosition::BOWL;
	}
	else if (std::sqrt((std::pow((pos.x - 1150), 2) + (std::pow((pos.y - 230), 2)))) <= 150.0)
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

void Cook::PutSlot()
{
	if (using_ingredients.size() != 0)
	{
		if (leftClick == true)
		{
			for (int i = 0; i < using_ingredients.size(); ++i)
			{
				if (using_ingredients[i]->GetPlace() == KitchenPosition::BOWL)
				{
					if (canCook == true)
					{
						if (plate.PutIngredient(using_ingredients[i]))
						{
							using_ingredients.erase(using_ingredients.begin() + i);
							whatMouseclickIndex = -1;
						}
						break;
					}
				}
				else if (using_ingredients[i]->GetPlace() == KitchenPosition::STOVE)
				{
					if (pot.PutIngredient(using_ingredients[i]))
					{
						using_ingredients.erase(using_ingredients.begin() + i);
						whatMouseclickIndex = -1;
					}
					break;
				}
			}
		}
	}
}

void Cook::ChangeIngredientPos()
{
	for (int i = 0; i < seven_ingredients.size(); ++i)
	{
		for (int j = 0; j < seven_ingredients[i].size(); ++j)
		{
			seven_ingredients[i][j]->ChangePos(Math::vec2(first_X + width * i, first_Y));
		}
	}
}

void Cook::SlotDraw()
{
	plate.Draw(plateDrawIndex);
	pot.Draw(potDrawIndex);

	if (checkDrawSoup == false)
	{
		pot.DrawIngredient();
	}
	plate.DrawIngredient();
}

void Cook::DrawScore(RecipeName order)
{
	score = recipeBook.GetRecipeBook()[static_cast<int>(order)]->CheckComplete(plate.vector);
	if (plate.ButtonClick(WhereISMouse()) == true)
	{
		if (score >= 0 && score < 50)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 3;
		}
		else if (score >= 50 && score < 95)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 2;
		}
		else if (score >= 95 && score < 100)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 1;
		}
		canCook = false; // 카운터로 가져다주는 벨 누르면 true가 되어야함.
		plate.vector.clear();
	}
	doodle::draw_text( std::to_string(score) + "%", 700, -10);
}

void Cook::SetStoveOn()
{
	if (stoveOn == false)
	{
		if (pot.ButtonClick(WhereISMouse()) == true)
		{
			stoveOn = true;
			
		}
		potDrawIndex = 0;
	}
	else
	{
		if (pot.ButtonClick(WhereISMouse()) == true)
		{
			stoveOn = false;
			if (text == "Now")
			{
				text = "Good";
				for (Ingredient* i : pot.vector)
				{
					i->Boil();
				}
			}
			else
			{
				text = "Bad";
			}
			time = 0;
			
		}
		potDrawIndex = 1;
	}
	
}

void Cook::DrawGage()
{
	if (time > 0 && time < 2)
	{
		text = "Yet";
	}
	else if (time >= 2 && time < 4)
	{
		text = "Ready";
		
	}
	else if (time >= 4 && time < 6)
	{
		text = "Now";
		
	}
	else if (time >= 6)
	{
		text = "Fail";
		
	}

	doodle::draw_text(text, 1100, -10);
}

void Cook::SpotToPlate()
{
	if (checkDrawSoup == true)
	{
		if (GetWhere(WhereISMouse()) == KitchenPosition::STOVE && leftClick == true)
		{
			leftClick = false;
			checkDrawSoup = false;
		}
	}
	else
	{
		if (pot.vector.size() != 0)
		{
			if (GetWhere(WhereISMouse()) == KitchenPosition::STOVE && leftClick == true)
			{
				leftClick = false;
				checkDrawSoup = true;
			}
		}
	}
	if (GetWhere(WhereISMouse()) == KitchenPosition::BOWL && leftClick == true)
	{
		if (canCook == true)
		{
			for (int i = 0; i < pot.vector.size() && plate.vector.size() <= 16; ++i)
			{
				plate.PutIngredient(pot.vector[i]);
			}
			pot.vector.clear();
			checkDrawSoup = false;
		}
	}
}

void Cook::DrawTempSoup()
{
	if (checkDrawSoup == true)
	{
		doodle::draw_ellipse(WhereISMouse().x, WhereISMouse().y, 30);
	}
}

