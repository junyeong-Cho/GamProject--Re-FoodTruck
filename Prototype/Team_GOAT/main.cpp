#include <iostream>
#include "doodle/doodle.hpp"
#include "Button.h"
#include "State.h"

void jh_Updatd()
{
    State state = State::Main;

    Button main_button(-100, -100, 200, 300, state);
    Button counter_button((doodle::Width /14) * 5.5, (doodle::Height / 8.0) * 3.0, doodle::Width / 28.0, doodle::Height / 16.0, state);
    Button game_over_button(100, 100, 100, 100, state);


    //Button main_button(0,0,100,100, state);
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
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();
            
            //speech bubble
            doodle::set_fill_color(0,88);
            doodle::draw_rectangle(-((doodle::Width / 7.0) * 3.0), -((doodle::Height / 8) * 3), ((doodle::Width / 7.0) * 6.0), ((doodle::Height / 8.0) * 5.0));
            
            //customer's satisfaction - 추후 추가 예정
            doodle::draw_rectangle(-((doodle::Width / 7.0) * 3.0), ((doodle::Height / 8.0) * 2.0), (doodle::Width / 7.0) * 2.0, (doodle::Height / 8.0) );
            doodle::draw_text(" 0 % / o x o", -((doodle::Width / 7.0) * 3.0), ((doodle::Height / 8.0) * 2.0));
            doodle::pop_settings();

            counter_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Game_over);
            break;
        case State::Game_over:
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();
            doodle::set_font_size(100.0);
            doodle::draw_text(" RE \n Try?", -((doodle::Width / 7.0) * 3.0), -((doodle::Height / 8.0) * 0.5));
            doodle::pop_settings();
            game_over_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
            break;

        }
    }
}

int main(void)
{
    doodle::create_window("Team_GOAT", 1400, 800);
    jh_Updatd();

}