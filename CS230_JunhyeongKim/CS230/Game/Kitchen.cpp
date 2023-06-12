/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Kitchen.cpp
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 10, 2023
Updated:    June 9, 2023
*/
#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include "..\Engine\Engine.h"

extern bool leftClick;

Kitchen::Kitchen()
	:go_counter(930.0, 720.0, 120.0, 80.0)
{
}

void Kitchen::Load()
{
	if (canLoad == true)
	{
		cuttingBoardTexture = Engine::GetTextureManager().Load("Assets/Cutting_board.png");
		kitchenBackgroundTexture = Engine::GetTextureManager().Load("Assets/kitchenBackground.png");
		bellTexture = Engine::GetTextureManager().Load("Assets/Bell.png");

		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/LemonSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/SaltSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/LeafSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/DragonFruitSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/MermaidScalesSalad_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/WaterSoup_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/AntSoup_Soso.png"));
		orderRecipeTexture.push_back(Engine::GetTextureManager().Load("Assets/StrongSoup_Soso.png"));

		orderUI = Engine::GetTextureManager().Load("Assets/MainFrame.png");
		cook.Load();

		recipeBook.Load();

		//Frame for Clock
		gameobjectmanager.Add(new Frame({ 210 , 730 }, 1));

		//Face test

		refutation = new Reputation({ 400, Engine::GetWindow().GetSize().y / 8.0 * 7.25 });
		gameobjectmanager.Add(refutation);


		//Frame for Refutation
		gameobjectmanager.Add(new Frame({ 395, 730 }, 1));


		//Frame for Money
		gameobjectmanager.Add(new Frame({ Engine::GetWindow().GetSize().x / 1.3, Engine::GetWindow().GetSize().y - 78.0 }, 2));

		//Frame for Day
		gameobjectmanager.Add(new Frame({ 30, 730 }, 1));


		for (int i = 0; i < cook.ingredient_number; ++i)
		{
			sideBowl.push_back(SideBowl(Math::vec2{ cook.sideBowlBoardFirstPos.x + (cook.sideBowlSize.x + cook.sideBowlPadding.x) * i, cook.sideBowlBoardFirstPos.y }, "3"));
			sideBowl[i].Load();
		}
		

		SetOrder();
		cook.GetOrder(orderRecipe, recipeBook.GetRecipeBook());
		canLoad = false;

	}
}

void Kitchen::Update(double dt)
{
	Engine::GetUnloadManager().GetCounterObjectManager().UpdateAll(dt);

	cook.ToolUpdate();
	if (recipeBook.BookOpen() == false)
	{
		cook.Update(dt);
		if (cook.GetTool() == ToolName::HAND)
		{
			go_counter.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Counter);
		}
	}
	SetSideBowl();
	if (cook.GetTool() == ToolName::HAND)
	{
		recipeBook.Update();
		SetSideBowlRefill();
	}


	Engine::GetUnloadManager().Update_timer(dt);

	if (Engine::GetUnloadManager().GetTimer() <= 0)
	{
		Engine::GetUnloadManager().Update_Day();
		if (Engine::GetUnloadManager().GetDay() > 4)
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
			canLoad = true;
			canUnload = true;
		}
		else
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Day_end));
			canLoad = true;
			canUnload = true;
		}
	}

	if (Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Space))
	{
		GetGSComponent<CS230::MusicEffect>()->Stop();
		Engine::GetUnloadManager().Update_Day();
		if (Engine::GetUnloadManager().GetDay() > 4)
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
		}
		else
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Day_end));
		}
		canLoad = true;
		canUnload = true;
	}


	if (Engine::GetUnloadManager().GetRate() <= 0 || Engine::GetUnloadManager().GetMoney() <= 0)
	{
		Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
		canLoad = true;
		canUnload = true;
	}

	if (Engine::GetOrderManager().GetOrder() != orderRecipe)
	{
		SetOrder();
		cook.GetOrder(orderRecipe, recipeBook.GetRecipeBook());
	}

	for (int i = 0; i < sideBowl.size(); ++i)
	{
		sideBowl[i].Update(dt);
	}

}

void Kitchen::Draw()
{
	Engine::GetWindow().Clear(0xEBE3C0FF);

	Draw_UI();

	for (int i = 0; i < cook.ingredient_number; ++i)
	{
		sideBowl[i].Draw();
	}
	cook.Draw();
	cook.SetScore(recipeBook.GetRecipeBook());
	recipeBook.Draw();
	go_counter.draw("Counter");

	//항상 제일 위에 그려져야함.
	cook.ToolDraw();
}

void Kitchen::Unload()
{
	if (canUnload == true)
	{
		cook.Unload();
		recipeBook.Unload();
		ClearGSComponents();
		canUnload = false;
	}
}

void Kitchen::SetSideBowl()
{
	for (int i = 0; i < cook.ingredient_number; ++i)
	{
		sideBowl[i].SetBowlNum(cook.GetSideBwolSize(i));
		sideBowl[i].Refill();
	}
}


void Kitchen::SetSideBowlRefill()
{
	for (int i = 0; i < cook.ingredient_number; ++i)
	{
		if (sideBowl[i].Refill() == true && sideBowl[i].MouseOn(cook.WhereISMouse()) && leftClick == true)
		{
			leftClick = false;
			cook.Refill(i);
		}
	}
}

void Kitchen::Draw_UI()
{
	Draw_Background();
	Draw_Order();
	Draw_CounterButton();
	Draw_Bell();
	Draw_CuttingBoard();
	Draw_PaltingSpot();

	gameobjectmanager.DrawAll(Math::TransformationMatrix());

	Draw_Frame_Text();
}

void Kitchen::Draw_Background()
{
	double scale_x = (double)Engine::GetWindow().GetSize().x / static_cast<double>(kitchenBackgroundTexture->GetSize().x);
	double scale_y = (double)Engine::GetWindow().GetSize().y / static_cast<double>(kitchenBackgroundTexture->GetSize().y);
	kitchenBackgroundTexture->Draw(Math::TransformationMatrix() * Math::ScaleMatrix({ scale_x, scale_y }));;
}


void Kitchen::Draw_Order()
{
	orderUI->Draw(Engine::GetDrawManager().GetMatrix(orderUI, cook.orderFramePos, cook.orderFrameSize));

	CS230::Texture* foodTexture = orderRecipeTexture[static_cast<int>(orderRecipe)];
	foodTexture->Draw(Engine::GetDrawManager().GetMatrix(foodTexture, cook.orderRecipePos, cook.orderRecipeSize));

}

void Kitchen::Draw_CounterButton()
{
	
}

void Kitchen::Draw_Bell()
{
	bellTexture->Draw(Engine::GetDrawManager().GetMatrix(bellTexture, cook.bellPos, cook.bellSize));
}



void Kitchen::Draw_CuttingBoard()
{
	doodle::push_settings();
	Math::TransformationMatrix matrix = Engine::GetDrawManager().GetMatrix(cuttingBoardTexture, cook.cuttingBoardPos, cook.cuttingBoardSize);
	cuttingBoardTexture->Draw(matrix);
	doodle::pop_settings();
}

void Kitchen::Draw_PaltingSpot()
{
	doodle::push_settings();

	doodle::pop_settings();
}

void Kitchen::Draw_Frame_Text()
{
	//Timer - frame addapted
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_outline_color(255, 255, 255);
	doodle::set_fill_color(255, 161, 74);
	doodle::draw_text("Time\n ", 240, Engine::GetWindow().GetSize().y / 8.0 * 7.55);
	doodle::draw_text(std::to_string(static_cast<int>(Engine::GetUnloadManager().GetTimer())), 255, Engine::GetWindow().GetSize().y - 80);
	doodle::pop_settings();

	//Refutation - frame addapted
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_outline_color(255, 255, 255);
	doodle::set_fill_color(255, 161, 74);
	doodle::draw_text(" Rate\n  " + std::to_string(Engine::GetUnloadManager().GetRate()), 455, 755);
	doodle::pop_settings();

	//Money - frame addapted
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_fill_color(0, 0, 0);
	doodle::draw_text("$" + std::to_string(Engine::GetUnloadManager().GetMoney()), Engine::GetWindow().GetSize().x / 1.3 + Engine::GetWindow().GetSize().x * 0.1 + 10.0, Engine::GetWindow().GetSize().y / 8.0 * 7.35+ 5.0);
	doodle::pop_settings();

	//Day
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_outline_color(255, 255, 255);
	doodle::set_fill_color(255, 161, 74);
	doodle::draw_text("DAY "+ std::to_string(Engine::GetUnloadManager().GetDay()), 60, 735);
	doodle::pop_settings();
}


void Kitchen::SetOrder()
{
	orderRecipe = Engine::GetOrderManager().GetOrder();
}

