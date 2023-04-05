#include <iostream>
#include "doodle/window.hpp"
#include "Button.h"
#include "State.h"
#include "Cook.h"
#include "Kitchen.h"

void ys_Update()
{
    State state = State::Kitchen;
    Kitchen kitchen{};

    while (!doodle::is_window_closed())
    {
        doodle::update_window();
        doodle::clear_background(255, 255, 255);

        double Width_raito = doodle::Width / 1400.0; // 7
        double Height_raito = doodle::Height / 800.0; //  4

        switch (state)
        {
        case State::Main:

            break;

        case State::Counter:


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