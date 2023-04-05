#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include "doodle/environment.hpp"


void Kitchen::Update(double Width, double Height)
{
	Width_raito = Width;
	Height_raito = Height;

	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_image_mode(doodle::RectMode::Corner);

	SetVariables(Width, Height);
	SetCookVariables();

	Draw_BackGround();
	Draw_CuttingBoard();
	Draw_Bowl();
	Draw_Stove();
	Draw_SideBowl();
	Draw_Clock();
	Draw_Receipt();
	Draw_BackCounter();
	Draw_ToolDrawer();
	Draw_Refrigerator();
	Draw_Bell();

	cook.Update();

	doodle::pop_settings();
}

void Kitchen::SetVariables(double Width, double Height)
{
	//side bowl
	first_X = Width_raito * 60.0;
	first_Y = Height_raito * 225.0;
	width = Width_raito * 170.0;
	height = Height_raito * 140.0;

	//cutting board
	cuttingBoard_X = Width_raito * 50.0;
	cuttingBoard_Y = Height_raito * 425.0;
	cuttingBoard_width = Width_raito * 570.0;
	cuttingBoard_height = Height_raito * 330.0;

	//bowl
	bowl_X = Width_raito * 800.0;
	bowl_Y = Height_raito * 580.0;
	bowl_width = Width_raito * 280.0;

	//stove
	stove_X = Width_raito * 1000.0;
	stove_Y = Height_raito * 600.0;
	stove_width = Width_raito * 280.0;

	//trashCan

	//Bell
	bell_X = Width_raito * 800.0;
	bell_Y = Height_raito * 60.0;
	bell_width = Width_raito * 60.0;
	bell_height = Height_raito * 60.0;
}

void Kitchen::SetCookVariables()
{
	//side bowl
	cook.first_X = first_X;
	cook.first_Y = first_Y;
	cook.width = width;
	cook.height = height;

	//cutting board
	cook.cuttingBoard_X = cuttingBoard_X;
	cook.cuttingBoard_Y = cuttingBoard_Y;
	cook.cuttingBoard_width = cuttingBoard_width;
	cook.cuttingBoard_height = cuttingBoard_height;

	//bowl
	cook.bowl_X = bowl_X;
	cook.bowl_Y = bowl_Y;
	cook.bowl_width = bowl_width;

	//stove
	cook.stove_X = stove_X;
	cook.stove_Y = stove_Y;
	cook.stove_width = stove_width;

	//trashCan

	//bell
	cook.bell_X = bell_X;
	cook.bell_Y = bell_Y;
	cook.bell_width = bell_width;
	cook.bell_height = bell_height;
}

void Kitchen::Draw_BackGround()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(3.0);

	doodle::draw_quad(0.0, 0.0, Width_raito * 1400.0, 0.0, Width_raito * 1375.0, Height_raito * 200.0, Width_raito * 25.0, Height_raito * 200.0);
	doodle::draw_quad(Width_raito * 25.0, Height_raito * 200.0, Width_raito * 1375.0, Height_raito * 200.0, Width_raito * 1400.0, Height_raito * 800.0, 0.0, Height_raito * 800.0);

	doodle::pop_settings();
}

void Kitchen::Draw_CuttingBoard()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xE7C0ABFF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 50.0, Height_raito * 425.0, Width_raito * 570.0, Height_raito * 330.0);


	doodle::pop_settings();
}

void Kitchen::Draw_Bowl()
{
	doodle::push_settings();

	doodle::draw_ellipse(Width_raito * 800.0, Height_raito * 580.0, Width_raito * 280.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Stove()
{
	doodle::push_settings();

	const auto oscillate = [](double t) { return (std::sin(t) * 0.5 + 0.5); };
	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	const double inside_distance = 0.4 + 0.3 * oscillate(doodle::ElapsedTime);
	const double completely_outside_distance = inside_distance + (1 - inside_distance) * oscillate(doodle::ElapsedTime * 2);
	doodle::set_font_backdrop_fade_out_interval(inside_distance, completely_outside_distance);
	doodle::set_font_size((Width_raito * 0.5 + Height_raito * 0.5) * 55.0);
	doodle::draw_text("Comming\nsoooonake", Width_raito * 1000.0, Height_raito * 600.0);

	doodle::pop_settings();
}

void Kitchen::Draw_SideBowl()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFFF688FF });
	doodle::set_outline_width(5.0);
	for (int i = 0; i < ingredient_number; ++i)
	{
		doodle::draw_rectangle(first_X + (width * i), first_Y, width, height);
	}

	doodle::pop_settings();
}

void Kitchen::Draw_Clock()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 35.0, Height_raito * 20.0, Width_raito * 150.0, Height_raito * 60.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Receipt()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 250.0, Height_raito * 20.0, Width_raito * 150.0, Height_raito * 100.0);

	doodle::pop_settings();
}

void Kitchen::Draw_BackCounter()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 800.0, Height_raito * 130.0, Width_raito * 220.0, Height_raito * 60.0);
	
	doodle::pop_settings();
}

void Kitchen::Draw_ToolDrawer()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 1050.0, Height_raito * 100.0, Width_raito * 140.0, Height_raito * 90.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Refrigerator()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(Width_raito * 1225.0, Height_raito * 100.0, Width_raito * 100.0, Height_raito * 90.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Bell()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(bell_X, bell_Y, bell_width, bell_height);
	doodle::set_font_size(bell_width / 3.0);
	doodle::draw_text(" bell", bell_X, bell_Y+bell_width);
	doodle::pop_settings();
}