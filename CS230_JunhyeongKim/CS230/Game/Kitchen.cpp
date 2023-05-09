#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include <iostream>

Kitchen::Kitchen()
{
	
}

void Kitchen::Load()
{
	cook.Load();
	recipeBook.Load();
}

void Kitchen::Update(double dt)
{
	cook.Update(dt);
	cook.Set_Variables();
	recipeBook.Update();
}
void Kitchen::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	Draw_UI();
	
	cook.Draw();
	cook.DrawScore(RecipeName::LemonSalad);
	recipeBook.Draw();
}
void Kitchen::Unload()
{
	recipeBook.Unload();
	cook.Unload();
}

void Kitchen::Draw_UI()
{
	Draw_Background();
	Draw_Clock();
	Draw_Money();
	Draw_RecipeBook();
	Draw_Order();
	Draw_CounterButton();
	Draw_Bell();
	Draw_IngredientBowl();
	Draw_CuttingBoard();
	Draw_PaltingSpot();
}

void Kitchen::Draw_Background()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(3.0);

	doodle::draw_quad(
		cook.topBackground_X1, cook.topBackground_Y1,
		cook.topBackground_X2, cook.topBackground_Y2,
		cook.topBackground_X3, cook.topBackground_Y3,
		cook.topBackground_X4, cook.topBackground_Y4);

	doodle::draw_quad(
		cook.bottomBackground_X1, cook.bottomBackground_Y1,
		cook.bottomBackground_X2, cook.bottomBackground_Y2,
		cook.bottomBackground_X3, cook.bottomBackground_Y3,
		cook.bottomBackground_X4, cook.bottomBackground_Y4);

	doodle::pop_settings();
}


void Kitchen::Draw_Clock()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(cook.clock_X, cook.clock_Y, cook.clock_width, cook.clock_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(cook.clock_width / 10.0);
	doodle::draw_text("Clock\ncoming Soon", cook.clock_X + cook.clock_width / 15.0, cook.clock_Y + cook.clock_height / 2.2);
	doodle::pop_settings();
}

void Kitchen::Draw_Money()
{
	//돈
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
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_ellipse(cook.bell_X, cook.bell_Y, cook.bell_width);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(cook.bell_width / 3.0);
	doodle::draw_text(" bell", cook.bell_X - cook.bell_width / 2.0, cook.bell_Y - cook.bell_width / 3.0);

	doodle::pop_settings();
}

void Kitchen::Draw_IngredientBowl()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFFF688FF });
	doodle::set_outline_width(5.0);
	for (int i = 0; i < cook.ingredient_number; ++i)
	{
		doodle::draw_rectangle(cook.first_X + (cook.width * i), cook.first_Y, cook.width, cook.height);
	}

	doodle::pop_settings();
}

void Kitchen::Draw_CuttingBoard()
{
	doodle::push_settings();
	Math::TransformationMatrix matrix = Math::TranslationMatrix(Math::vec2(cook.cuttingBoard_X, cook.cuttingBoard_Y)) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.35);
	CS230::Texture* texture = Engine::GetTextureManager().Load("Assets/Cutting_board.png");
	texture->Draw(matrix);

	doodle::pop_settings();
}

void Kitchen::Draw_PaltingSpot()
{
	doodle::push_settings();

	doodle::pop_settings();
}

