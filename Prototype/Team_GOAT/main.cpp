
#include "doodle/doodle.hpp"

#include "Button.h"
#include "State.h"

#include "Kitchen.h"
#include "Cook.h"


#include "Store.h"
#include "Pet.h"



//stand
void draw_stand();
//돈, 명예, 시간 관련된 UI위치
void draw_UI(int complete_point);
//손님 뒤에 나올 배경 크기, 위치
void draw_background();
//손님 이미지 위치나 손님 관련 효과
void draw_customer(doodle::Image guest_image);
//손님 주문 텍스트
void draw_text(std::string text);
//요리 다 하고 100퍼 넘었을 때 카운터에서 보여주는 요리
void draw_Salad(doodle::Image image);
//엔딩멘트로 계속 지켜봐달라고 적을 text
void draw_ending_word();

extern State* state = new State{ State::Main };

void sm_Updatd()
{
    //State state = State::Main;
    const doodle::Image guest_image("giraffe.png");
    const doodle::Image fail_food("fail_food.png");
    Button main_button(600, 200, 250, 100, *state);
    Button yes(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    Button no(doodle::Width / 2, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    const std::string giraffe_text= "I'd like a pretty salad, please.";
    Button evauluation_button(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 5.0, doodle::Height / 10.0, *state);
    Button game_over_button(450, 300, 600, 300, *state);
    Button ending_word_button(doodle::Width / 3.0, doodle::Height / 3.0, doodle::Width / 10.0, doodle::Height / 10.0, *state);
    Button back_main_buton(600, 200, 250, 100, *state);

    Pet pet{};

    Kitchen kitchen{};

    Store store{};

    

     int complete_point = 0;
     double guest_image_x = -300.0;

    while (!doodle::is_window_closed())
    {
        pet.PetHungerUpdate();
        pet.DrawPetSprite(state);

        double Width_raito = doodle::Width / 1400.0; // 7
        double Height_raito = doodle::Height / 800.0; //  4

        doodle::update_window();

        switch (*state)
        {
        case State::Main:

            doodle::clear_background(255, 255, 255);
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft); 

            pet.PrintInfo();


            doodle::draw_text("Re:Truck", doodle::Width / 2 - doodle::Width / 12.0, doodle::Height / 2.0 + doodle::Height / 12.0);
            main_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Midnight, "Play");
            

            break;

        case State::Counter:

            complete_point = 0;
            doodle::clear_background(doodle::HexColor{ 0xEBE3C0FF });
            draw_background();
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            
            if (guest_image_x < 133.0 * Height_raito)
            {
                //delta_time += doodle::DeltaTime;
                guest_image_x += 10;
            }
            else if (guest_image_x >= 133 * Height_raito)
            {
                guest_image_x = 133 * Height_raito;
            }
            doodle::draw_image(guest_image, guest_image_x, Height_raito * 200 , doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            doodle::push_settings();
            doodle::set_fill_color(doodle::HexColor{ 0xEBE3C0FF });
            doodle::no_outline();
            doodle::draw_rectangle(0, 0, doodle::Width / 12.0, doodle::Height);
            doodle::pop_settings();
            //doodle::draw_image(guest_image, doodle::Width / 10.5, doodle::Height / 4.0, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            draw_text(giraffe_text);
            draw_stand();
            draw_UI(complete_point);

            doodle::push_settings();
            doodle::set_font_size(22);
            yes.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Kitchen, "Yes!");
            no.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Evaluation_screen, "NO!");
            doodle::pop_settings();
            
            if (*state != State::Counter)
            {
                guest_image_x = -300;
            }
            
            if (*state == State::Kitchen)
            {
                kitchen.cook.Load();
            }

            pet.PrintInfo();

            break;
        case State::Kitchen:


            doodle::clear_background(0, 255, 0);
            complete_point = kitchen.cook.GetPercentOfComplete();
            kitchen.Update(Width_raito, Height_raito);
            break;
        case State::Evaluation_screen:
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();

            doodle::clear_background(doodle::HexColor{ 0xEBE3C0FF });
            draw_background();
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            doodle::draw_image(guest_image, doodle::Width / 10.5, doodle::Height / 4.0, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
            draw_text(giraffe_text);
            draw_stand();
            draw_UI(complete_point);


            if (complete_point >= 100)
            {
                evauluation_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Ending_word);
                draw_text(" HAHA, Sooooooooooo delicious");
                draw_Salad(fail_food);

            }
            else if (complete_point == 0) // no dish
            {
                evauluation_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Game_over);
                draw_text(" I don't think that's \n how business works");
            }
            else
            {
                evauluation_button.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Game_over);
                draw_text(" Oooops, This is not food.\n It's an insult to the salad!!");
                draw_Salad(fail_food);
            }
            doodle::pop_settings();

            pet.PrintInfo();

            break;
        case State::Midnight:
            //store.Update(Width_raito, Height_raito);


        case State::Game_over:
            doodle::clear_background(255, 255, 255);
            doodle::push_settings();
            doodle::set_font_size(100.0);
            game_over_button.update("RE \n Try?", doodle::get_mouse_x(), doodle::get_mouse_y(), State::Counter);
            doodle::pop_settings();
            break;
        case State::Ending_word:
            doodle::clear_background(255, 255, 255, 200);
            doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
            draw_ending_word();
            back_main_buton.update(doodle::get_mouse_x(), doodle::get_mouse_y(), State::Main, "Main");
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
    double delta_time = 0.0;
    
    doodle::push_settings();
    //doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    double guest_image_y = -300.0;
    doodle::draw_image(guest_image, doodle::Width / 10.5, guest_image_y, doodle::Width / 6.0, doodle::Height / 7.0 * 4.4);
    if (guest_image_y <= 200.0)
    {
        //delta_time += doodle::DeltaTime;
        guest_image_y += 10;
    }
    doodle::pop_settings();
}

void draw_UI(int complete_point)
{
    //시간
    doodle::draw_rectangle(doodle::Width / 12.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Time", doodle::Width / 12.0 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.35);
    doodle::pop_settings();
    //명성
    doodle::draw_rectangle(doodle::Width / 5.0, doodle::Height / 8.0 * 7.3, doodle::Width * 0.15, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Rate : " + std::to_string(complete_point), doodle::Width / 5.0 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.35);
    doodle::pop_settings();
    //돈
    doodle::draw_rectangle(doodle::Width / 2.75, doodle::Height / 8.0 * 7.3, doodle::Width * 0.10, doodle::Height * 0.07);
    doodle::push_settings();
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::set_font_size(doodle::Width / 60.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Money", doodle::Width / 2.75 + doodle::Width * 0.025, doodle::Height / 8.0 * 7.35);
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

void draw_Salad(doodle::Image image)
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_fill_color(255, 255, 255);
    doodle::draw_ellipse(doodle::Width / 2.0, doodle::Height / 7.0, doodle::Width / 5.0, doodle::Height / 7.0);
    doodle::draw_image(image, (doodle::Width / 1400.0) * 560, doodle::Height / 11.5, doodle::Width / 5.0, doodle::Height / 7.0);
    doodle::pop_settings();
}

void draw_ending_word()
{
    doodle::push_settings();
    doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
    doodle::set_font_fade_out_interval(0.5, 0.0);
    doodle::no_outline();
    doodle::set_font_size(doodle::Width / 20.0);
    doodle::set_fill_color(0, 0, 0);
    doodle::draw_text("Thank you.\nPlease look forward to it.\n- Team G.O.A.T", doodle::Width / 9.0, doodle::Height / 2.0 + doodle::Height / 10.0);
    doodle::pop_settings();
}