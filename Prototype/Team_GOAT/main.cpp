#include <iostream>
#include "doodle/window.hpp"
#include "doodle/drawing.hpp"
#include "Button.h"
#include "State.h"
#include "Cook.h"
#include "Kitchen.h"

extern State* state = new State{ State::Kitchen };
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
    doodle::create_window("Team_GOAT");
    ys_Update();

}