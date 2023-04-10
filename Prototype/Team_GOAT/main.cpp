#include <iostream>
#include "doodle/doodle.hpp"
#include "Button.h"
#include "State.h"
#include <chrono>
#include "Cook.h"
#include "Kitchen.h"

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
//요리 다 하고 100퍼 넘었을 때 카운터에서 보여주는 요리
void draw_Salad();
//엔딩멘트로 계속 지켜봐달라고 적을 text
void draw_ending_word();

extern State* state = new State{ State::Main };
void sm_Updatd()
{
    //State state = State::Main;
    const doodle::Image guest_image("giraffe.png");
    Button main_button(600, 300, 200, 300, *state);
    Button yes(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    Button no(doodle::Width / 2, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    const std::string giraffe_text= "People without faith will go to hell.";
    Button counter_button(1250, 700, 50, 50, *state);
    Button game_over_button(800, 500, 100, 100, *state);
    Button ending_word_button(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    Button back_main_buton(doodle::Width / 2, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    
    Kitchen kitchen{};
    double Width_raito = doodle::Width / 1400.0; // 7
    double Height_raito = doodle::Height / 800.0; //  4

    int complete_point = 0;

    while (!doodle::is_window_closed())
    {
        doodle::update_window();

        switch (*state)
        {
        case State::Main:
            doodle::clear_background(255, 255, 255);
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            main_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
            break;
        case State::Counter:
            doodle::clear_background(doodle::HexColor{ 0xEBE3C0FF });
            draw_background();
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            doodle::draw_image(guest_image, doodle::Width / 10.5, doodle::Height / 4.0, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            draw_text(giraffe_text);
            //draw_customer(guest_image);
            draw_stand();
            draw_UI();

            doodle::push_settings();
            doodle::set_font_size(22);
            yes.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Kitchen, "Yes!");
            no.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Evaluation_screen, "NO!");
            doodle::pop_settings();
            if (*state == State::Kitchen)
            {
                kitchen.cook.Load();
            }

            break;
        case State::Kitchen:
            doodle::clear_background(0, 255, 0);
            complete_point = kitchen.cook.GetPercentOfComplete();
            kitchen.Update(Width_raito, Height_raito);
            break;
        case State::Evaluation_screen:
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();

            //speech bubble
            doodle::set_fill_color(0, 88);
            doodle::draw_rectangle(Width_raito*100, Height_raito * 100, Width_raito * 1200, Height_raito * 500);

            doodle::draw_rectangle(Width_raito * 100, Height_raito * 600, Width_raito * 400, Height_raito * 100);

            if (complete_point >= 100)
            {
                doodle::draw_text(" " + std::to_string(complete_point) + " % / ^^b", Width_raito * 100, Height_raito * 600);
                counter_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Clear);
                doodle::draw_text(" HAHA, Sooooooooooo delicious", Width_raito * 100, Height_raito * 500);
            }
            else if (complete_point == 0) // no dish
            {
                doodle::draw_text(" " + std::to_string(complete_point) + " % / TxT", Width_raito * 100, Height_raito * 600);
                counter_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Game_over);
                doodle::draw_text(" I don't think that's \n how business works", Width_raito * 100, Height_raito * 500);
            }
            else
            {
                doodle::draw_text(" " + std::to_string(complete_point) + " % / oxo", Width_raito * 100, Height_raito * 600);
                counter_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Game_over);
                doodle::draw_text(" Oooops, This is not food.\n This is blasphemy!!", Width_raito * 100, Height_raito * 500);

            }
            doodle::pop_settings();
            break;
        case State::Game_over:
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();
            doodle::set_font_size(100.0);
            doodle::draw_text(" RE \n Try?", Width_raito * 100, Height_raito * 350);
            doodle::pop_settings();
            game_over_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
            break;
        case State::Clear:
            doodle::clear_background(doodle::HexColor{ 0xEBE3C0FF });
            draw_background();
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            doodle::draw_image(guest_image, doodle::Width / 10.5, doodle::Height / 4.0, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            draw_stand();
            draw_UI();
            draw_Salad();
            ending_word_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Ending_word);
            break;
        case State::Ending_word:
            doodle::clear_background(255, 255, 255, 200);
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            draw_ending_word();
            back_main_buton.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Main);
            break;

        }
    }
}

void ys_Update()
{
    Kitchen kitchen{};

    while (!doodle::is_window_closed())
    {
        doodle::update_window();
        doodle::clear_background(255, 255, 255);

        double Width_raito = doodle::Width / 1400.0; // 7
        double Height_raito = doodle::Height / 800.0; //  4

        switch (*state)
        {
        case State::Main:

            break;

        case State::Counter:
            doodle::push_settings();
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            doodle::set_outline_color(doodle::HexColor{ 0xFF7171FF });
            doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
            doodle::draw_text("Counter", Width_raito * 700, Width_raito * 400);
            doodle::pop_settings();
            break;

        case State::Kitchen:
            
            kitchen.Update(Width_raito, Height_raito);

            break;

        }
    }
}

int main(void)
{
    doodle::create_window("Team_GOAT",1400, 800);

    sm_Updatd();

}

void draw_stand()
{
    doodle::push_settings();
    //doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 0);
    doodle::draw_rectangle(0.0, 0.0, doodle::Width / 6.0 * 5.0, doodle::Height / 4.0);
    doodle::draw_triangle(doodle::Width / 6.0 * 5.0, doodle::Height / 4.0, doodle::Width / 6.0 * 5.0 + 100.0, 0.0, doodle::Width / 6.0 * 5.0, 0.0);
    doodle::pop_settings();
}

void draw_background()
{
    doodle::push_settings();
   // doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(128, 128, 0);
    doodle::draw_rectangle(doodle::Width / 12.0, doodle::Height / 4.0, doodle::Width / 3.0 * 2.0, doodle::Height / 7.0 * 4.4);
    doodle::pop_settings();
}

void draw_customer(doodle::Image guest_image)
{
    double guest_image_y = 0.0;
    double delta_time = 0.0;
    
    doodle::push_settings();
    //doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::draw_image(guest_image, doodle::Width / 10.5, guest_image_y, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
    if (delta_time <= 2)
    {
        delta_time += doodle::DeltaTime;
        guest_image_y = doodle::Height / 2.0 * delta_time;
    }
    doodle::pop_settings();
}

void draw_UI()
{
    //시간
    doodle::draw_rectangle(doodle::Width / 12.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Time", doodle::Width / 12.0 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.3);
    doodle::pop_settings();
    //명성
    doodle::draw_rectangle(doodle::Width / 5.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.15, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Rate", doodle::Width / 5.0 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.3);
    doodle::pop_settings();
    //돈
    doodle::draw_rectangle(doodle::Width / 2.75, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Money", doodle::Width / 2.75 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.3);
    doodle::pop_settings();
    //밖에 손님 확인용
    doodle::draw_rectangle(doodle::Width * 4.0 / 5.0, doodle::Height / 8.0 * 5.0, doodle::Width * 0.15, doodle::Height * 0.35);
}

void draw_text(std::string text)
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 255);
    doodle::draw_rectangle(doodle::Width / 4.0, doodle::Height / 2.0, doodle::Width / 2.3, doodle::Height / 4.0);
    doodle::pop_settings();
 
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text(text, doodle::Width / 4.0 + doodle::Width / 30.0, doodle::Height / 2.0 + doodle::Height / 10.0);
    doodle::pop_settings();
}

void draw_Salad()
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 255);
    doodle::draw_ellipse(doodle::Width / 2.0, doodle::Height / 7.0, doodle::Width / 5.0, doodle::Height / 7.0);
    doodle::pop_settings();
}

void draw_ending_word()
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Thank you.\nPlease look forward to it.\n- Team G.O.A.T", doodle::Width / 4.0 + doodle::Width / 30.0, doodle::Height / 2.0 + doodle::Height / 10.0);
    doodle::pop_settings();
}