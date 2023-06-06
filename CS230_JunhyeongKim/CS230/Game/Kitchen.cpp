#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include <iostream>
#include "..\Engine\Engine.h"

extern bool leftClick;

Kitchen::Kitchen()
	:go_counter(930.0, 720.0, 120.0, 80.0)
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
}

void Kitchen::Load()
{
	if (canLoad == true)
	{
		cook.Load();
		recipeBook.Load();
		canLoad = false;

		for (int i = 0; i < cook.ingredient_number; ++i)
		{
			sideBowl.push_back(SideBowl(Math::vec2{ cook.sideBowlBoardFirstPos.x + (cook.sideBowlSize.x + cook.sideBowlPadding.x) * i, cook.sideBowlBoardFirstPos.y }, "1"));
		}
		cook.GetOrder(orderRecipe, recipeBook.GetRecipeBook());
	}
}

void Kitchen::Update(double dt)
{
	Engine::GetUnloadManager().GetCounterObjectManager().UpdateAll(dt);

	if (recipeBook.BookOpen() != true)
	{
		cook.Update(dt);
		go_counter.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Counter);
	}
	cook.ToolUpdate();
	recipeBook.Update();

	SetSideBowl();
	SetSideBowlRefill();

	Engine::GetUnloadManager().Update_timer(dt);

	if (Engine::GetUnloadManager().GetTimer() <= 0)
	{
		Engine::GetUnloadManager().Update_Day();
		if (Engine::GetUnloadManager().GetDay() >= 4)
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Ending));
		}
		else
		{
			Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::Day_end));
			canLoad = true;
			canUnload = true;
		}
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
	go_counter.draw();

	//항상 제일 위에 그려져야함.
	cook.ToolDraw();
}

void Kitchen::Unload()
{
	if (canUnload == true)
	{
		cook.Unload();
		recipeBook.Unload();
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

void Kitchen::SetOrder()
{
	orderRecipe = Engine::GetOrderManager().GetOrder();
}