#include <iostream>
#include "doodle/doodle.hpp"
#include "Button.h"
#include "State.h"
#include <chrono>

//가판대
void draw_stand();
//돈, 명예, 시간 관련된 UI위치
void draw_UI();
//손님 뒤에 나올 배경 크기, 위치
void draw_background();
//손님 이미지 위치나 손님 관련 효과
void draw_customer(doodle::Image guest_image);
//손님 주문 텍스트
void draw_text(std::string text);


/*void jh_Updatd()
{
    State state = State::Main;

    Button main_button(-100, -100, 200, 300, state);
    Button counter_button((doodle::Width / 14) * 5.5, (doodle::Height / 8.0) * 3.0, doodle::Width / 28.0, doodle::Height / 16.0, state);
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
            doodle::set_fill_color(0, 88);
            doodle::draw_rectangle(-((doodle::Width / 7.0) * 3.0), -((doodle::Height / 8) * 3), ((doodle::Width / 7.0) * 6.0), ((doodle::Height / 8.0) * 5.0));

            //customer's satisfaction - 추후 추가 예정
            doodle::draw_rectangle(-((doodle::Width / 7.0) * 3.0), ((doodle::Height / 8.0) * 2.0), (doodle::Width / 7.0) * 2.0, (doodle::Height / 8.0));
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
*/

void sm_Updatd()
{
    State state = State::Main;
    const doodle::Image guest_image("giraffe.png");
    Button main_button(-100, -100, 200, 300, state);
    Button to_kitchen_button(doodle::Width / 3, 0, 200, 100, state);
    Button yes(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, state);
    Button no(doodle::Width / 2, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, state);
    const std::string giraffe_text= "People without faith will go to hell.";
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
            draw_background();
            doodle::draw_image(guest_image, doodle::Width / 10.5, doodle::Height / 4.0, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            draw_text(giraffe_text);
            //draw_customer(guest_image);
            draw_stand();
            draw_UI();
            yes.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Kitchen);
            no.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
            to_kitchen_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Kitchen);

            break;
        case State::Kitchen:
            doodle::clear_background(0, 255, 0);

            break;

        }
    }
}

int main(void)
{
    doodle::create_window("Team_GOAT");
    sm_Updatd();

}

void draw_stand()
{
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 0);
    doodle::draw_rectangle(0.0, 0.0, doodle::Width / 6.0 * 5.0, doodle::Height / 4.0);
    doodle::draw_triangle(doodle::Width / 6.0 * 5.0, doodle::Height / 4.0, doodle::Width / 6.0 * 5.0 + 100.0, 0.0, doodle::Width / 6.0 * 5.0, 0.0);
}

void draw_background()
{
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(128, 128, 0);
    doodle::draw_rectangle(doodle::Width / 12.0, doodle::Height / 4.0, doodle::Width / 3.0 * 2.0, doodle::Height / 7.0 * 4.4);
}

void draw_customer(doodle::Image guest_image)
{
    double guest_image_y = 0.0;
    double delta_time = 0.0;

    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::draw_image(guest_image, doodle::Width / 10.5, guest_image_y, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
    if (delta_time <= 2)
    {
        delta_time += doodle::DeltaTime;
        guest_image_y = doodle::Height / 2.0 * delta_time;
    }
}

void draw_UI()
{
    //시간
    doodle::draw_rectangle(doodle::Width / 12.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07 );
    //명성
    doodle::draw_rectangle(doodle::Width / 5.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.15, doodle::Height * 0.07);
    //돈
    doodle::draw_rectangle(doodle::Width / 2.75, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07);
    //밖에 손님 확인용
    doodle::draw_rectangle(doodle::Width * 4.0 / 5.0, doodle::Height / 8.0 * 5.0, doodle::Width * 0.15, doodle::Height * 0.35);
}

void draw_text(std::string text)
{
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::push_settings();
    doodle::set_fill_color(255, 255, 255);
    doodle::draw_rectangle(doodle::Width / 4.0, doodle::Height / 2.0, doodle::Width / 2.3, doodle::Height / 4.0);
    doodle::pop_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text(text, doodle::Width / 4.0 + doodle::Width / 30.0, doodle::Height / 2.0 + doodle::Height / 10.0);
}

