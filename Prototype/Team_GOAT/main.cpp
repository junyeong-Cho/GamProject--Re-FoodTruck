#include <iostream>
#include "doodle/doodle.hpp"
#include "Button.h"
#include "State.h"
#include "Cook.h"

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

void ys_Update()
{
    State state = State::Kitchen;
    Cook cook{};

    while (!doodle::is_window_closed())
    {
        doodle::update_window();
        doodle::clear_background(255, 255, 255);
        cook.Update();
    }
}

int main(void)
{
    doodle::create_window("Team_GOAT");
    ys_Update();

}