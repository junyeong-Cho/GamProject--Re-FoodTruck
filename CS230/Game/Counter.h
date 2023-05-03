/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter.h
Project:    CS230 Engine
Author:     Seo
Created:    April 30, 2023
*/

#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "Button.h"

class Counter : public CS230::GameState
{
public:
    Counter();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    void Clear();
    void Draw_UI();
    void Draw_text(std::string text);
    
    std::string GetName() override { return "Counter"; }
private:
    CS230::Texture* guest_image;
    Math::vec2 guest_position;

    Button yes_button;
};