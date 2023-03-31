#pragma once
#include <string>
#include <doodle/doodle.hpp>
#include "State.h"

struct Button
{
    //Button's position
    double      x;
    double      y;

    //Button's Size
    double      width;
    double      height;

    //State
    State* current_state;

    //Button_name
    std::string   buttonName;

    //Check_button
    bool checkMouse = false;

    /** x좌표, y좌표, 버튼 가로길이, 버튼 세로길이, 현재장면변수 순으로 적으세용*/
    Button(double tempX, double tempY, double tempWidth, double tempHeight, State& current_state)
        : x(tempX), y(tempY), width(tempWidth), height(tempHeight), current_state(&current_state)
    {
    };


    //have name button
    //Button(double tempX, double tempY, double tempWidth, double tempHeight, std::string name)
    //    : x(tempX), y(tempY), width(tempWidth), height(tempHeight), buttonName(name) {};


    void draw(const int mouse_x, const int mouse_y);
    void check_click(const int mouse_x, const int mouse_y, State next_state);

    /** 마우스x좌표, 마우스y좌표, 다음장면 순으로 적으세용*/
    void update(const int mouse_x, const int mouse_y, State next_state);
};