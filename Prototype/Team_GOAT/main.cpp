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

void jy_Updated()
{
	doodle::create_window(1400, 800);
	doodle::set_frame_of_reference(doodle::FrameOfReference::LeftHanded_OriginTopLeft);
	doodle::set_image_mode(doodle::RectMode::Corner);
	//doodle::no_fill();

	const auto oscillate = [](double t) { return (std::sin(t) * 0.5 + 0.5); };


	while (!doodle::is_window_closed())
	{
		doodle::update_window();
		doodle::clear_background(doodle::HexColor{ 0xFFFFFFFF });


		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(3.0);

		doodle::draw_quad(0, 0, 1400, 0, 1375, 200, 25, 200);
		doodle::draw_quad(25, 200, 1375, 200, 1400, 800, 0, 800);

		doodle::pop_settings();


		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xE7C0ABFF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(50, 425, 570, 330);


		doodle::pop_settings();



		doodle::push_settings();


		doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
		const double inside_distance = 0.4 + 0.3 * oscillate(doodle::ElapsedTime);
		const double completely_outside_distance = inside_distance +
			(1 - inside_distance) * oscillate(doodle::ElapsedTime * 2);
		doodle::set_font_backdrop_fade_out_interval(inside_distance, completely_outside_distance);
		doodle::draw_text("Comming\nsoooonake", 850, 600);

		doodle::pop_settings();


		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xFFF688FF });
		doodle::set_outline_width(5.0);
		doodle::draw_rectangle(60, 225, 1200, 140);

		doodle::pop_settings();




		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xAD4A3BFF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(35, 20, 150, 60);
		doodle::draw_rectangle(250, 20, 150, 100);

		doodle::pop_settings();


		doodle::push_settings();

		doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
		doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
		doodle::set_outline_width(5.0);
		doodle::smooth_drawing();
		doodle::draw_rectangle(800, 130, 220, 60);
		doodle::draw_rectangle(1050, 100, 140, 90);
		doodle::draw_rectangle(1225, 100, 100, 90);

		doodle::pop_settings();

		
	}

}

int main(void)
{
    doodle::create_window("Team_GOAT");
    //jh_Updatd();
	jy_Updated();

}