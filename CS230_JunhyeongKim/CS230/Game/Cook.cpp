#include "Cook.h"
#include <doodle/drawing.hpp>
#include <iostream>
#include "..\Engine\Engine.h"
#include "States.h"

extern bool leftClick;

Cook::Cook() 
	: plate(platePos, plateSize, plateButtonPos, plateButtonSize), 
	pot(potPos, potSize, potButtonPos, potButtonSize)
{}

void Cook::SetIngredient()
{
	for (int i = 0; i < ingredient_number; ++i)
	{
		seven_ingredients.push_back(std::vector<Ingredient*>());
	}
	if (seven_ingredients.size() == ingredient_number)
	{
		for (int i = 0; i < firstIngredientNum; ++i)
		{
			seven_ingredients[0].push_back(new Lemon(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 0 + ingredientPadding.x, sideBowlBoardFirstPos .y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[1].push_back(new Lettuce(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 1 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[2].push_back(new Ant(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 2 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[3].push_back(new Leaf(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 3 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[4].push_back(new Salt(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 4 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[5].push_back(new DragonFruit(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 5 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
			seven_ingredients[6].push_back(new MermaidScales(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 6 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize));
		}
	}
}

void Cook::Load()
{
	SetIngredient();
	operation.Load();
	tool.Load();
	plate.Load();
	pot.Load();
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
		seven_ingredients[i].clear();
	}
	seven_ingredients.clear();

	for (int i = 0; i < using_ingredients.size(); ++i)
	{
		delete using_ingredients[i];
	}
	using_ingredients.clear();
	

	score = 0;
	time = 0;
	stoveOn = false;
	text = "Off";
	potDrawIndex = 0;
	plateDrawIndex = 0;
	checkDrawSoup = false;
	canCook = true;
	whatMouseclickIndex = -1;
}


void Cook::Update(double dt)
{
	SetStoveOn();
	if (stoveOn == true)
	{
		time += dt;
		if (time > 10)
		{
			time = 10;
		}
	}
	operation.Update();
	tool.Update(operation.Return());
	SetIngredientsWhere();
	PutSlot();
	CreateUsingIngredient();
	plate.Update(dt, orderSize);
	pot.Update(dt, orderSize);

	GetWhere(WhereISMouse());
	ToolTask();
	
	ClickBell();
}

void Cook::Draw()
{
	SlotDraw();
	if (canCook == true)
	{
		plate.DrawSlotRect();
		pot.DrawSlotRect();
	}
	DrawIngredients();

	tool.Draw();
	plate.ButtonDraw();
	pot.ButtonDraw();
	DrawGage();
	DrawScore();
	//얘가 항상 제일 위에 그려져야함.
	operation.Draw();
}

void Cook::DrawIngredients()
{
	if (seven_ingredients.size() != 0)
	{
		for (int i = 0; i < seven_ingredients.size(); ++i)
		{
			for (int j = 0; j < seven_ingredients[i].size(); ++j)
			{
				seven_ingredients[i][j]->Draw(ingredientTextureManager.GetTexture());
			}
		}
	}
	if (using_ingredients.size() != 0)
	{
		for (int i = 0; i < using_ingredients.size(); ++i)
		{
			using_ingredients[i]->Draw(ingredientTextureManager.GetTexture());
		}

	}
}

void Cook::ToolTask()
{
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
		PotToPlate();
	}
	else if (tool.GetTool() == ToolName::TRASHCAN)
	{
		TrashCan();
	}
}

Math::vec2 Cook::WhereISMouse()
{
	return Math::vec2(doodle::get_mouse_x(), doodle::get_mouse_y());
}

KitchenPosition Cook::GetWhere(Math::vec2 pos)
{
	for (int i = 0; i < ingredient_number; ++i)
	{
		Math::vec2 pos = { sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * i, sideBowlBoardFirstPos.y };
		if (Engine::GetDrawManager().RectCollision(pos, sideBowlSize, WhereISMouse()) == true)
		{
			std::cout << i << '\n';
			return static_cast<KitchenPosition>(i);
		}
	}
	if (Engine::GetDrawManager().RectCollision(cuttingBoardPos, cuttingBoardSize, WhereISMouse()) == true)
	{
		std::cout << "CUTTING_BOARD" << '\n';
		return KitchenPosition::CUTTING_BOARD;
	}
	else if (Engine::GetDrawManager().RectCollision(platePos, plateSize, WhereISMouse()) == true)
	{
		std::cout << "BOWL" << '\n';
		return KitchenPosition::BOWL;
	}
	else if (Engine::GetDrawManager().RectCollision(potPos, potSize, WhereISMouse()) == true)
	{
		std::cout << "STOVE" << '\n';
		return KitchenPosition::STOVE;
	}
	else if (Engine::GetDrawManager().RectCollision(bellPos, bellSize, WhereISMouse()) == true)
	{
		std::cout << "BELL" << '\n';
		return KitchenPosition::BELL;
	}
	std::cout << "ELSE" << '\n';
	return KitchenPosition::ELSE;
}

void Cook::ClickBell()
{
	if (leftClick == true && GetWhere(WhereISMouse()) == KitchenPosition::BELL)
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Counter));
		if (plateDrawIndex != 0)
		{
			canCook = true;
			plate.GetIngredientVec().clear();
			plateDrawIndex = 0;
			Engine::GetUnloadManager().Set_food_grad(score);
		}
	}
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
		for (int i = using_ingredients.size() - 1; i >= 0; --i)
		{
			if (using_ingredients[i]->IsMouseOn(WhereISMouse(), ingredientTextureManager.GetTexture()) == true && leftClick == true && GetWhere(WhereISMouse()) == KitchenPosition::CUTTING_BOARD)
			{
				if (using_ingredients[i]->GetCutNum() > 0)
				{
					using_ingredients[i]->Cut();
					leftClick = false;
				}
				/*leftClick = false;*/
			}
		}
		leftClick = false;
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
				for (int i = using_ingredients.size() - 1; i >= 0; --i)
				{
					if (using_ingredients[i]->IsMouseOn(WhereISMouse(), ingredientTextureManager.GetTexture()) == true)
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
		using_ingredients[WhatIndexMouseClick()]->ChangePos(Math::vec2{ WhereISMouse().x - ingredientSize.x / 2.0, WhereISMouse().y - ingredientSize.y / 2.0 });
	}
}

void Cook::PutSlot()
{
	if (using_ingredients.size() > whatMouseclickIndex && using_ingredients.size() != 0)
	{
		if (leftClick == true && whatMouseclickIndex != -1)
		{
			if (using_ingredients[whatMouseclickIndex]->GetPlace() == KitchenPosition::BOWL)
			{
				if (canCook == true)
				{
					if (plate.PutIngredient(using_ingredients[whatMouseclickIndex]))
					{
						using_ingredients.erase(using_ingredients.begin() + whatMouseclickIndex);
						whatMouseclickIndex = -1;
					}
				}
			}
			else if (using_ingredients[whatMouseclickIndex]->GetPlace() == KitchenPosition::STOVE)
			{
				if (pot.PutIngredient(using_ingredients[whatMouseclickIndex]))
				{
					using_ingredients.erase(using_ingredients.begin() + whatMouseclickIndex);
					whatMouseclickIndex = -1;
				}
			}
		}
	}
}

void Cook::SlotDraw()
{
	plate.Draw(plateDrawIndex);
	pot.Draw(potDrawIndex);

	if (checkDrawSoup == false)
	{
		pot.DrawIngredient(ingredientTextureManager.GetTexture());
	}
	plate.DrawIngredient(ingredientTextureManager.GetTexture());
}

void Cook::GetOrder(RecipeName orderRecipe, std::vector<Recipe*>& recipeBook)
{
	order = orderRecipe;
	orderSize = recipeBook[static_cast<int>(order)]->GetTotalNum();
}

void Cook::SetScore(std::vector<Recipe*>& recipeBook)
{
	if (canCook == true)
	{
		score = recipeBook[static_cast<int>(order)]->CheckComplete(plate.GetIngredientVec());
	}
}

void Cook::DrawScore()
{
	if (plate.ButtonClick(WhereISMouse()) == true)
	{
		if (score >= 0 && score < 40)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 3;
		}
		else if (score >= 40 && score < 90)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 2;
		}
		else if (score >= 90 && score <= 100)
		{
			plateDrawIndex = static_cast<int>(order) * 3 + 1;
		}
		canCook = false; // 카운터로 가져다주는 벨 누르면 true가 되어야함.
		plate.GetIngredientVec().clear();
	}
	doodle::push_settings();
	doodle::set_font_size(Engine::GetDrawManager().Vec(percentTextSize).x);
	doodle::draw_text( std::to_string(score) + "%", Engine::GetDrawManager().Vec(percentTextPos).x, Engine::GetDrawManager().Vec(percentTextPos).y);
	doodle::pop_settings();
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
				for (Ingredient* i : pot.GetIngredientVec())
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
	if (time > 0 && time < 4)
	{
		text = "Yet";
	}
	else if (time >= 4 && time < 6)
	{
		text = "Ready";
		
	}
	else if (time >= 6 && time < 8)
	{
		text = "Now";
		
	}
	else if (time >= 8)
	{
		text = "Fail";
		
	}

	doodle::pop_settings();
	doodle::set_font_size(Engine::GetDrawManager().Vec(gageBarTextSize).x);
	doodle::draw_text(text, Engine::GetDrawManager().Vec(gageBarTextPos).x, Engine::GetDrawManager().Vec(gageBarTextPos).y);

	//Color
	doodle::Color baseColor(0, 0, 0, 200);
	doodle::Color myGageColor(255, 0, 0);
	doodle::Color targetGageColor(0, 255, 0, 200);

	doodle::push_settings();
	doodle::set_fill_color(baseColor);
	doodle::draw_rectangle(Engine::GetDrawManager().Vec(gageBarPos).x, Engine::GetDrawManager().Vec(gageBarPos).y, Engine::GetDrawManager().Vec(wholeGageBarSize).x, Engine::GetDrawManager().Vec(wholeGageBarSize).y);

	doodle::set_fill_color(myGageColor);
	doodle::draw_rectangle(Engine::GetDrawManager().Vec(gageBarPos).x, Engine::GetDrawManager().Vec(gageBarPos).y, Engine::GetDrawManager().Vec({ time / 10.0 * wholeGageBarSize.x, wholeGageBarSize.y }).x, Engine::GetDrawManager().Vec(wholeGageBarSize).y);

	doodle::set_fill_color(targetGageColor);
	doodle::draw_rectangle(Engine::GetDrawManager().Vec({ gageBarPos.x + (0.6 * wholeGageBarSize.x), gageBarPos.y}).x, Engine::GetDrawManager().Vec(gageBarPos).y, Engine::GetDrawManager().Vec({0.2 * wholeGageBarSize.x, wholeGageBarSize.y}).x, Engine::GetDrawManager().Vec(wholeGageBarSize).y);
	doodle::pop_settings();
}

void Cook::PotToPlate()
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
		if (pot.GetIngredientVec().size() != 0)
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
			for (int i = 0; i < pot.GetIngredientVec().size() && plate.GetIngredientVec().size() <= 16; ++i)
			{
				if (plate.PutIngredient(pot.GetIngredientVec()[i]) == true)
				{
					pot.GetIngredientVec().erase(pot.GetIngredientVec().begin() + i);
				}
			}
			checkDrawSoup = false;
		}
	}
}

void Cook::Refill(int index)
{
	for (int i = 0; i < refillNum; ++i)
	{
		seven_ingredients[index].push_back(CreateIngredient(index));
	}
}

Ingredient* Cook::CreateIngredient(int index)
{
	Ingredient* newOne = nullptr;
	switch (index)
	{
	case 0:
		newOne = new Lemon(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 0 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 1:
		newOne = new Lettuce(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 1 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 2:
		newOne = new Ant(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 2 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 3:
		newOne = new Leaf(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 3 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 4:
		newOne = new Salt(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 4 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 5:
		newOne = new DragonFruit(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 5 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	case 6:
		newOne = new MermaidScales(Math::vec2{ sideBowlBoardFirstPos.x + (sideBowlSize.x + sideBowlPadding.x) * 6 + ingredientPadding.x, sideBowlBoardFirstPos.y + ingredientPadding.y }, ingredientSize);
		break;
	}
	return newOne;
}

void Cook::TrashCan()
{
	for (int i = using_ingredients.size() - 1; i >= 0; --i)
	{
		if (using_ingredients[i]->IsMouseOn(WhereISMouse(), ingredientTextureManager.GetTexture()) == true && leftClick == true)
		{
			leftClick = false;
			delete using_ingredients[i];
			using_ingredients.erase(using_ingredients.begin() + i);
			break;
		}
	}

	if (GetWhere(WhereISMouse()) == KitchenPosition::BOWL && leftClick == true)
	{
		leftClick = false;
		plate.Unload();
	}

	if (GetWhere(WhereISMouse()) == KitchenPosition::STOVE && leftClick == true)
	{
		leftClick = false;
		pot.Unload();
	}
}