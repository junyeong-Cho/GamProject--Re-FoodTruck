/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

//#include <SFML/Audio.hpp>


#include <iostream>

#include "Engine/SoundComponentManager.h"
#include "Engine/Engine.h"

#include "Game/Splash.h"
#include "Game/MainMenu.h"
#include "Game/Counter.h"
#include "Game/Kitchen.h"
#include "Game/Ending.h"
#include "Game/Credit.h"


//int music_checker = 0;

//sf::Music music;


int main() {
    try {

        /*
        if (!music.openFromFile("Assets/Sound/Theme/main_theme_1.ogg")) 
        {
            std::cout << "Failed to load the music file: Assets/Sound/Theme/main_theme_2.ogg" << std::endl;
        }
        */

        /*
        music.setLoop(true);
        music.setVolume(60);
        */




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

