#include <iostream>
#include "doodle/doodle.hpp"
#include "Button.h"
#include "State.h"



void jh_Updatd()
{


    State state = State::Main;

    //Button main_button(0,0,100,100, state);
    Button main_button(-100, -100, 200, 300, state);

    while (!doodle::is_window_closed())
    {
        doodle::update_window();

        switch (state)
        {
        case State::Main:
            doodle::clear_background(255, 255, 255);
            main_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);

            break;
        case State::Counter:
            std::cout << "ddd";

            doodle::clear_background(255, 0, 0);

            break;
        case State::Kitchen:
            doodle::clear_background(0, 255, 0);

            break;

        }
    }
}


void print_text(doodle::HexColor color, std::string text, int x, int y)
{
	doodle::push_settings();

	doodle::set_font_size(48);
	doodle::set_fill_color(133, 226, 0, 151);
	doodle::set_outline_color(doodle::HexColor{ color });
	doodle::draw_text(text, x, y);

	doodle::pop_settings();
}


void jy_Updated()
{
	
	doodle::create_window(1400, 800);
	

	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_image_mode(doodle::RectMode::Corner);
	//doodle::no_fill();

	State current_state = State::Main;
	State prev_state;


	const auto oscillate = [](double t) { return (std::sin(t) * 0.5 + 0.5); };


	while (!doodle::is_window_closed())
	{
		double Width_raito = doodle::Width / 1400.0;
		double Height_raito = doodle::Height / 800.0;


		doodle::update_window();
		doodle::clear_background(doodle::HexColor{ 0xFFFFFFFF });
		

		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(3.0);

		//메인 배경
		doodle::draw_quad(0.0, 0.0, Width_raito * 1400.0, 0.0, Width_raito * 1375.0, Height_raito * 200.0, Width_raito * 25.0, Height_raito * 200.0);
		doodle::draw_quad(Width_raito * 25.0, Height_raito * 200.0, Width_raito * 1375.0, Height_raito * 200.0, Width_raito * 1400.0, Height_raito * 800.0, 0.0, Height_raito * 800.0);

		doodle::pop_settings();



		//도마 그림
		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xE7C0ABFF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(Width_raito * 50.0, Height_raito * 425.0, Width_raito * 570.0, Height_raito * 330.0);
		Button cutting_board(Width_raito * 50.0, Height_raito * 425.0, Width_raito * 570.0, Height_raito * 330.0, current_state);


		doodle::pop_settings();


		//샐러드 보울
		doodle::push_settings();


		doodle::draw_ellipse(Width_raito * 800.0, Height_raito * 580.0, Width_raito * 280.0);
		Button salad_bowl(Width_raito * 660.0, Height_raito * 440.0, Width_raito * 280.0, Height_raito * 280.0, current_state);


		doodle::pop_settings();


		//버너 커밍순
		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
		const double inside_distance = 0.4 + 0.3 * oscillate(doodle::ElapsedTime);
		const double completely_outside_distance = inside_distance +
			(1 - inside_distance) * oscillate(doodle::ElapsedTime * 2);
		doodle::set_font_backdrop_fade_out_interval(inside_distance, completely_outside_distance);
		doodle::draw_text("Comming\nsoooonake", Width_raito * 1000.0, Height_raito * 600.0);

		doodle::pop_settings();



		//반찬통
		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xFFF688FF });
		doodle::set_outline_width(5.0);
		doodle::draw_rectangle(Width_raito * 60.0, Height_raito * 225.0, Width_raito * 1200.0, Height_raito * 140.0);
		Button cavage(Width_raito * 60.0, Height_raito * 225.0, Width_raito * 170.0, Height_raito * 140.0, current_state);
		Button source(Width_raito * 230.0, Height_raito * 225.0, Width_raito * 170.0, Height_raito * 140.0, current_state);

		doodle::pop_settings();



		//시간표시, 주문내역
		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(Width_raito * 35.0, Height_raito * 20.0, Width_raito * 150.0, Height_raito * 60.0);
		doodle::draw_rectangle(Width_raito * 250.0, Height_raito * 20.0, Width_raito * 150.0, Height_raito * 100.0);

		doodle::pop_settings();

		
		//카운터로 돌아가는 버튼, 서랍장, 냉장고 버튼
		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(Width_raito * 800.0, Height_raito * 130.0, Width_raito * 220.0, Height_raito * 60.0);
		doodle::draw_rectangle(Width_raito * 1050.0, Height_raito * 100.0, Width_raito * 140.0, Height_raito * 90.0);
		doodle::draw_rectangle(Width_raito * 1225.0, Height_raito * 100.0, Width_raito * 100.0, Height_raito * 90.0);

		doodle::pop_settings();



		switch (current_state)
		{
		case State::Main:
			prev_state = current_state;

			cutting_board.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
			cavage.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Cavage);
			source.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Source);
			salad_bowl.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
			break;

		case State::Counter:
			prev_state = current_state;
			cutting_board.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);


			break;
		case State::Kitchen:
			prev_state = current_state;
			doodle::clear_background(0, 255, 0);

			break;

		case State::Cavage:
			prev_state = current_state;
			cavage.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Cavage);
			source.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Source);
			salad_bowl.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);

			doodle::push_settings();

			print_text(0x3F6C00FF, "This is Cavage", Width_raito * 140.0, Height_raito * 630.0);

			doodle::pop_settings();

			break;

		case State::Source:
			prev_state = current_state;
			cavage.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Cavage);
			source.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Source);
			salad_bowl.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);

			doodle::push_settings();

			print_text(0xF5BA83FF, "This is Source", Width_raito * 140.0, Height_raito * 630.0);

			doodle::pop_settings();

			break;
		}

	}

}

int main(void)
{
    doodle::create_window("Team_GOAT");
    //jh_Updatd();
	jy_Updated();

}