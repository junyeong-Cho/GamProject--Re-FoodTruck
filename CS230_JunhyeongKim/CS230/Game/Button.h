/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Button.h
Project:    GAM150
Author:     Junhyeong Kim
Created:    March 24, 2023
*/
#pragma once
#include <string>
#include "States.h"

struct Button
{
    //Button's position
    double x;
    double y;

    //Button's Size
    double width;
    double height;

    //Raito
    double Width_raito;
    double Height_raito;

    //Draw
    double  alpha = 255;

    //Check_button
    bool checkMouse = false;
    bool checkClick = false;

    //Mouse_
    int mouseX = 0;
    int mouseY = 0;

    /** Write down in the order of x coordinate, y coordinate, button horizontal length, button vertical length, and current scene variable*/
    Button(double tempX, double tempY, double tempWidth, double tempHeight);

    //have name button
    //Button(double tempX, double tempY, double tempWidth, double tempHeight, std::string name)
    //    : x(tempX), y(tempY), width(tempWidth), height(tempHeight), buttonName(name) {};


    void draw();
    void draw(std::string text);
    void text_draw(std::string text);
    void check_click();
    void check_click(States next_state);
    /** Write down mouse x coordinate, mouse y coordinate, and next scene in order*/
    void update(const int mouse_x, const int mouse_y, States next_state);

    void update(const int mouse_x, const int mouse_y);
    void DrawLoading();
    bool canLoadingText = false;
};