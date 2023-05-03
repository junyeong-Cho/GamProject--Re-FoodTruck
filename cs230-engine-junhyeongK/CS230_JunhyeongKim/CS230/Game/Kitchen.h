#pragma once

#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"
#include "../Engine/Engine.h"
#include "States.h"
#include "Button.h"
#include "Cook.h"

class Kitchen : public CS230::GameState
{
public:
    Kitchen();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    std::string GetName() override { return "Kitchen"; }

private:
    Cook cook;
};