#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include <iostream>
#include "..\Engine\Engine.h"

extern bool leftClick;

Kitchen::Kitchen()
	:go_counter(100,100,100,100)
{
	cuttingBoardTexture = Engine::GetTextureManager().Load("Assets/Cutting_board.png");
	kitchenBackgroundTexture = Engine::GetTextureManager().Load("Assets/kitchenBackground.png");
	bellTexture = Engine::GetTextureManager().Load("Assets/Bell.png");

}

void Kitchen::Load()
{
	if (canLoad == true)
	{
		cook.Load();
		recipeBook.Load();
		canLoad = false;

		//Frame for Clock
		gameobjectmanager.Add(new Frame({ Engine::GetWindow().GetSize().x / 12.5, Engine::GetWindow().GetSize().y / 8.0 * 7.18 }, 1));

		//Face test
		refutation = new Refutation({ Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 8.0 * 7.25 });
		gameobjectmanager.Add(refutation);

		//Frame for Refutation
		gameobjectmanager.Add(new Frame({ Engine::GetWindow().GetSize().x / 4.0, Engine::GetWindow().GetSize().y / 8.0 * 7.18 }, 1));

		//Frame for Money
		gameobjectmanager.Add(new Frame({ Engine::GetWindow().GetSize().x / 1.3, Engine::GetWindow().GetSize().y / 8.0 * 7.18 }, 2));


		for (int i = 0; i < cook.ingredient_number; ++i)
		{
			sideBowl.push_back(SideBowl(Math::vec2{ cook.first_X + cook.width * i, cook.first_Y }, "100"));
		}
	}
}

void Kitchen::Update(double dt)
{
	Engine::GetUnloadManager().GetCounterObjectManager().UpdateAll(dt);
	cook.Update(dt);
	recipeBook.Update();
	go_counter.update(doodle::get_mouse_x(), doodle::get_mouse_y(), States::Counter);

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
	cook.GetOrder(RecipeName::AntSalad, recipeBook.GetRecipeBook());

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
	Draw_RecipeBook();
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
	double scale_x = Engine::GetWindow().GetSize().x / static_cast<double>(kitchenBackgroundTexture->GetSize().x);
	double scale_y = Engine::GetWindow().GetSize().y / static_cast<double>(kitchenBackgroundTexture->GetSize().y);
	kitchenBackgroundTexture->Draw(Math::TransformationMatrix() * Math::ScaleMatrix({ scale_x, scale_y }));;
}


void Kitchen::Draw_RecipeBook()
{
	
}

void Kitchen::Draw_Order()
{
	//주문 -> 벡터에 넣어서 순서대로.
}

void Kitchen::Draw_CounterButton()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(cook.backCounter_X, cook.backCounter_Y, cook.backCounter_width, cook.backCounter_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(cook.backCounter_width / 6.0);
	doodle::draw_text("Counter", cook.backCounter_X + cook.backCounter_width / 15.0, cook.backCounter_Y);
	doodle::pop_settings();
}

void Kitchen::Draw_Bell()
{
	//카운터 버튼이랑 이 버튼이랑 눌렀을 때 초기화 해주는게 다름.
	/*doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_ellipse(cook.bell_X, cook.bell_Y, cook.bell_width);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(cook.bell_width / 3.0);
	doodle::draw_text(" bell", cook.bell_X - cook.bell_width / 2.0, cook.bell_Y - cook.bell_width / 3.0);

	doodle::pop_settings();*/

	Math::TransformationMatrix matrix = Math::TranslationMatrix(Math::vec2(cook.bell_X - cook.bell_width/1.2, cook.bell_Y - cook.bell_width/1.2)) * Math::RotationMatrix(0) * Math::ScaleMatrix( (cook.bell_width * 1.3)/bellTexture->GetSize().x);

	bellTexture->Draw(matrix);
}



void Kitchen::Draw_CuttingBoard()
{
	doodle::push_settings();
	Math::TransformationMatrix matrix = Math::TranslationMatrix(Math::vec2(cook.cuttingBoard_X, cook.cuttingBoard_Y+20)) * Math::RotationMatrix(0) * Math::ScaleMatrix({ cook.cuttingBoard_width / cuttingBoardTexture->GetSize().x, cook.cuttingBoard_height / cuttingBoardTexture->GetSize().y });
	
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
	doodle::draw_text("Time\n " + std::to_string(static_cast<int>(Engine::GetUnloadManager().GetTimer())), Engine::GetWindow().GetSize().x / 12.0 + 10 + Engine::GetWindow().GetSize().x * 0.025, Engine::GetWindow().GetSize().y / 8.0 * 7.55);
	doodle::pop_settings();

	//Refutation - frame addapted
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_outline_color(255, 255, 255);
	doodle::set_fill_color(255, 161, 74);
	doodle::draw_text(" Rate\n  " + std::to_string(Engine::GetUnloadManager().GetRate()), Engine::GetWindow().GetSize().x / 5.0 + Engine::GetWindow().GetSize().x * 0.095, Engine::GetWindow().GetSize().y / 8.0 * 7.5);
	doodle::pop_settings();

	//Money - frame addapted
	doodle::push_settings();
	doodle::set_font_fade_out_interval(0.5, 0.0);
	doodle::set_font_size(Engine::GetWindow().GetSize().x / 50.0);
	doodle::set_outline_width(12);
	doodle::set_fill_color(0, 0, 0);
	doodle::draw_text(std::to_string(Engine::GetUnloadManager().GetMoney()), Engine::GetWindow().GetSize().x / 1.3 + Engine::GetWindow().GetSize().x * 0.1, Engine::GetWindow().GetSize().y / 8.0 * 7.35);
	doodle::pop_settings();
}

