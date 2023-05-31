/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#include <iostream>

#include "Engine/Engine.h"

#include "Game/Splash.h"
#include "Game/MainMenu.h"
#include "Game/Counter.h"
#include "Game/Kitchen.h"
#include "Game/Ending.h"
#include "Game/Credit.h"

int main() {
    try {
        Engine& engine = Engine::Instance();
        engine.Start("Re : Truck");

        Splash splash;
        engine.GetGameStateManager().AddGameState(splash);
        MainMenu main_menu;
        engine.GetGameStateManager().AddGameState(main_menu);
        Counter counter;
        engine.GetGameStateManager().AddGameState(counter);
        Kitchen kitchen;
        engine.GetGameStateManager().AddGameState(kitchen);
        Ending ending;
        engine.GetGameStateManager().AddGameState(ending);
        Credit credit;
        engine.GetGameStateManager().AddGameState(credit);

        while (engine.HasGameEnded() == false) 
        {
            engine.Update();
        }


        engine.Stop();

        return 0;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return -1;
    }
}

