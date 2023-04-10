#include "Kitchen.h"
#include "doodle/drawing.hpp"
#include <iostream>


void Kitchen::Update(double Width, double Height)
{
	Width_raito = Width;
	Height_raito = Height;

	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	SetVariables();
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
	Draw_Recipe();
	Draw_ToolExplainText();


	cook.Update();

	doodle::pop_settings();
}

void Kitchen::SetVariables()
{
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
	cook.stove_height = stove_height;

	//trashCan

	//bell
	cook.bell_X = bell_X;
	cook.bell_Y = bell_Y;
	cook.bell_width = bell_width;
	
}

void Kitchen::Draw_BackGround()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(3.0);

	doodle::draw_quad(
		topBackground_X1, topBackground_Y1, 
		topBackground_X2, topBackground_Y2,
		topBackground_X3, topBackground_Y3, 
		topBackground_X4, topBackground_Y4 );

	doodle::draw_quad(
		bottomBackground_X1, bottomBackground_Y1,
		bottomBackground_X2, bottomBackground_Y2,
		bottomBackground_X3, bottomBackground_Y3,
		bottomBackground_X4, bottomBackground_Y4);

	doodle::pop_settings();
}

void Kitchen::Draw_CuttingBoard()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xE7C0ABFF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(cuttingBoard_X, cuttingBoard_Y, cuttingBoard_width, cuttingBoard_height);
	doodle::set_font_size(cuttingBoard_width / 10.0);
	doodle::draw_text("Cutting Board", cuttingBoard_X+cuttingBoard_width / 15.0, cuttingBoard_Y+cuttingBoard_height / 3.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Bowl()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xE7C0ABFF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_ellipse(bowl_X, bowl_Y, bowl_width);
	doodle::set_font_size(bowl_width / 5.0);
	doodle::draw_text("Bowl", bowl_X - bowl_width/3.7, bowl_Y - bowl_width / 5.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Stove()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::draw_rectangle(stove_X, stove_Y, stove_width, stove_height);

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
	doodle::draw_rectangle(clock_X, clock_Y, clock_width, clock_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(clock_width / 10.0);
	doodle::draw_text("Clock\ncoming Soon", clock_X + clock_width / 15.0, clock_Y + clock_height / 2.2);
	doodle::pop_settings();
}

void Kitchen::Draw_Receipt()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(receipt_X, receipt_Y, receipt_width, receipt_height);

	doodle::pop_settings();
}

void Kitchen::Draw_BackCounter()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(backCounter_X, backCounter_Y, backCounter_width, backCounter_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(backCounter_width / 6.0);
	doodle::draw_text("Counter", backCounter_X + backCounter_width / 15.0, backCounter_Y );
	doodle::pop_settings();
}

void Kitchen::Draw_ToolDrawer()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(toolDrawer_X, toolDrawer_Y, toolDrawer_width, toolDrawer_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(toolDrawer_width / 10.0);
	doodle::draw_text("Tool Drawer\ncoming Soon", toolDrawer_X + toolDrawer_width / 10.0, toolDrawer_Y + toolDrawer_height / 2.2);
	doodle::pop_settings();
}

void Kitchen::Draw_Refrigerator()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(refrigerator_X, refrigerator_Y, refrigerator_width, refrigerator_height);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(toolDrawer_width / 12.0);
	doodle::draw_text("Refrigerator", refrigerator_X + refrigerator_width / 15.0, refrigerator_Y + refrigerator_height / 2.2);
	doodle::pop_settings();
}

void Kitchen::Draw_Bell()
{
	doodle::push_settings();

	doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_ellipse(bell_X, bell_Y, bell_width);
	doodle::set_fill_color(doodle::Color(0, 0, 0));
	doodle::set_font_size(bell_width / 3.0);
	doodle::draw_text(" bell", bell_X - bell_width / 2.0, bell_Y-bell_width / 3.0);

	doodle::pop_settings();
}

void Kitchen::Draw_Recipe()
{
	//상추
	doodle::push_settings();
	doodle::set_fill_color(0, 128, 0);
	doodle::draw_rectangle(receipt_X + receipt_width/5.0, receipt_Y + receipt_height/2.5, receipt_width / 10.0, receipt_width / 10.0);
	doodle::pop_settings();

	//소스
	doodle::push_settings();
	doodle::set_fill_color(255, 255, 0);
	doodle::draw_rectangle(receipt_X + receipt_width / 5.0, receipt_Y + receipt_height / 6.0, receipt_width/10.0, receipt_width / 10.0);
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_fill_color(0,0,0);
	doodle::set_font_size(receipt_width / 10.0);
	doodle::draw_text("<Salad Recipe>", receipt_X + receipt_width / 27.0, receipt_Y + receipt_height / 1.5);
	doodle::draw_text("x  3", receipt_X + receipt_width / 2.5, receipt_Y + receipt_height / 2.7);
	doodle::draw_text("x  2", receipt_X + receipt_width / 2.5, receipt_Y + receipt_height / 9.7);
	doodle::pop_settings();
}

void  Kitchen::Draw_ToolExplainText()
{
	doodle::push_settings();
	doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
	doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
	doodle::set_outline_width(5.0);
	doodle::smooth_drawing();
	doodle::draw_rectangle(toolExplain_X, toolExplain_Y, toolExplain_width, toolExplain_height);
	doodle::pop_settings();

	doodle::push_settings();
	doodle::set_fill_color(0, 0, 0);
	doodle::set_font_size(toolExplain_width / 10.0);
	doodle::draw_text("<Tool>", toolExplain_X + toolExplain_width / 3.7, toolExplain_Y + toolExplain_height / 1.5);
	doodle::draw_text("Key Z : Knife", toolExplain_X + toolExplain_width / 10.0, toolExplain_Y + toolExplain_height / 2.7);
	doodle::draw_text("Key X : Hand", toolExplain_X + toolExplain_width / 10.0, toolExplain_Y + toolExplain_height / 9.7);
	doodle::pop_settings();
}