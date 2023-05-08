/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Junyeong Cho
Created:    March 8,  2023
Updated:    April 27, 2023
*/
#pragma once


#include "doodle/input.hpp"

#include "Pet.h"
#include "States.h"


#include "..\Engine\GameStateManager.h"
#include "..\Engine\Engine.h"





Pet::Pet(Math::vec2 start_position) : GameObject(start_position)
{
    elementState = PetPropertyName::IDLE;
    hungry = 10;

    on_mouse_wheel = false;


    sprite.Load("Assets/Pet.spt");
    SetPosition(start_position);

    current_state = &state_idle;
    current_state->Enter(this);

}


void Pet::Update(double dt)
{
    GameObject::Update(dt);
    //PetHungerUpdate();
    //PetEatingFood();
}

void Pet::UpdatePetProperty(PetPropertyName name)
{
    elementState = name;
}

void Pet::PetHungerUpdate()
{
    if (isCooking == true)
    {
        hungry -= 1;

        if (hungry <= 0)
        {
            isHungry = true;
        }
    }
    else
    {
        isHungry = false;
    }
}

void Pet::PetEatingFood()
{
    if (doodle::MouseIsPressed == true && isCooking == true)
    {
        hungry -= 11;
        checkMouse = true;
    }
    else
    {
        checkMouse = false;
    }

    if (doodle::MouseIsPressed == false && checkMouse == true)
    {
        checkMouse = false;
    }
}




void Pet::State_Idle::Enter(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == "Counter")
    {
        if (pet->elementState == PetPropertyName::IDLE)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::IDLE_STANDING));
        }
        else if (pet->elementState == PetPropertyName::WATER)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::WATER_STANDING));
        }
        else if (pet->elementState == PetPropertyName::FIRE)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::FIRE_STANDING));
        }
    }
    else if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == "Kitchen")
    {
        if (pet->elementState == PetPropertyName::IDLE)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::IDLE_STANDING));
        }
        else if (pet->elementState == PetPropertyName::WATER)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::WATER_STANDING));
        }
        else if (pet->elementState == PetPropertyName::FIRE)
        {
            pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::FIRE_STANDING));
        }
    }
}

void Pet::State_Idle::Update(GameObject* object, double dt) { }

void Pet::State_Idle::CheckExit(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    pet->prev_state = pet->current_state;



    if (pet->on_mouse_wheel == true) //반환 받으면 바뀌게
    {
        pet->change_state(&pet->state_change_type);
    }

    if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == "Kitchen")
    {
        pet->change_state(&pet->state_cooking);
    }

    if (pet->hungry <= 0)
    {
        pet->change_state(&pet->state_hungry);
    }

}


void Pet::State_Cooking::Enter(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    if (pet->isCooking == true)
    {
        switch (pet->elementState)
        {
        case PetPropertyName::FIRE:

            pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::FIRE_COOKING));


            break;

        case PetPropertyName::WATER:

            pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::WATER_COOKING));


            break;

        case PetPropertyName::IDLE:

            pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::IDLE_COOKING));

            break;

        default:

            break;
        }
    }
}

void Pet::State_Cooking::Update(GameObject* object, double dt)
{
    Pet* pet = static_cast<Pet*>(object);

    pet->PetHungerUpdate();
}

void Pet::State_Cooking::CheckExit(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    pet->prev_state = pet->current_state;

    if (pet->on_mouse_wheel = true)
    {
        pet->change_state(&pet->state_change_type);
    }
    else if (pet->hungry <= 0)
    {
        pet->change_state(&pet->state_hungry);
    }
    else if (pet->isCooking == false)
    {
        pet->change_state(&pet->state_idle);
    }
}


void Pet::State_Hungry::Enter(GameObject* object)
{

}

void Pet::State_Hungry::Update(GameObject* object, double dt)
{
    Pet* pet = static_cast<Pet*>(object);

    pet->PetEatingFood();
}

void Pet::State_Hungry::CheckExit(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    if (pet->hungry > 0)
    {
        pet->change_state(&pet->state_idle);
    }
}


void Pet::State_ChangeType::Enter(GameObject* object)
{
    /*
    Pet* pet = static_cast<Pet*>(object);


    switch (pet->elementState)
    {
    case Pet::FIRE:

        if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Counter))
        {
            if(pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::FIRE_HUNGRY));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::FIRE_STANDING));
            }
        }
        else if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Kitchen))
        {
            if (pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::FIRE_HUNGRY));
            }
            else if (pet->isCooking == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::FIRE_COOKING));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::FIRE_STANDING));
            }
        }

        break;

    case Pet::WATER:

        if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Counter))
        {
            if (pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::WATER_HUNGRY));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::WATER_STANDING));
            }
        }
        else if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Kitchen))
        {
            if (pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::WATER_HUNGRY));
            }
            else if (pet->isCooking == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::WATER_COOKING));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::WATER_STANDING));
            }
        }

        break;

    case Pet::IDLE:

        if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Counter))
        {
            if (pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::IDLE_HUNGRY));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(CounterAnimations::IDLE_STANDING));
            }
        }
        else if (Engine::GetGameStateManager().GetCurrentGameState()->GetName() == StateToString(States::Kitchen))
        {
            if (pet->isHungry == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::IDLE_COOKING));
            }
            else if (pet->isCooking == true)
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::IDLE_HUNGRY));
            }
            else
            {
                pet->sprite.PlayAnimation(static_cast<int>(KitchenAnimations::IDLE_STANDING));
            }
        }

        break;

    default:

        break;


    }
    */

    std::map<std::string, int> stateToIndex =
    {
        {"Counter", 0},
        {"Kitchen", 1}
    };

    /*
    [0] : stateIndex    - 현재 state가 counter인지 Kitchen인지 찾아줌
    [1] : elementState  - Pet의 type이 어떤 타입인지 확인함
    [2] : isHungry      - Pet이 배고픈 상태인지 확인
    [3] : isCooking     - Pet이 요리를 하고 있는지 안하고 있는지 확인
    */
    int animationTable[2][3][2][3] =
    {
        // CounterAnimations
        {
            {
                {static_cast<int>(CounterAnimations::FIRE_STANDING), static_cast<int>(CounterAnimations::WATER_STANDING), static_cast<int>(CounterAnimations::IDLE_STANDING)},
                {static_cast<int>(CounterAnimations::FIRE_HUNGRY)  , static_cast<int>(CounterAnimations::WATER_HUNGRY)  , static_cast<int>(CounterAnimations::IDLE_HUNGRY)}
            },
            {
                {static_cast<int>(CounterAnimations::FIRE_STANDING), static_cast<int>(CounterAnimations::WATER_STANDING), static_cast<int>(CounterAnimations::IDLE_STANDING)},
                {static_cast<int>(CounterAnimations::FIRE_HUNGRY)  , static_cast<int>(CounterAnimations::WATER_HUNGRY)  , static_cast<int>(CounterAnimations::IDLE_HUNGRY)}
            }
        },
        // KitchenAnimations
        {
            {
                {static_cast<int>(KitchenAnimations::FIRE_STANDING), static_cast<int>(KitchenAnimations::WATER_STANDING), static_cast<int>(KitchenAnimations::IDLE_STANDING)},
                {static_cast<int>(KitchenAnimations::FIRE_HUNGRY)  , static_cast<int>(KitchenAnimations::WATER_HUNGRY)  , static_cast<int>(KitchenAnimations::IDLE_HUNGRY)}
            },
            {
                {static_cast<int>(KitchenAnimations::FIRE_COOKING), static_cast<int>(KitchenAnimations::WATER_COOKING), static_cast<int>(KitchenAnimations::IDLE_COOKING)},
                {static_cast<int>(KitchenAnimations::FIRE_HUNGRY) , static_cast<int>(KitchenAnimations::WATER_HUNGRY) , static_cast<int>(KitchenAnimations::IDLE_HUNGRY)}
            }
        }
    };

    Pet* pet = static_cast<Pet*>(object);
    std::string currentStateName = Engine::GetGameStateManager().GetCurrentGameState()->GetName();

    int stateIndex = stateToIndex[currentStateName];

    // Set the animation based on the current state, element, hunger, and cooking status
    int animationIndex = animationTable[stateIndex][static_cast<int>(pet->elementState)][pet->isHungry][pet->isCooking];
    pet->sprite.PlayAnimation(animationIndex);
}

void Pet::State_ChangeType::Update(GameObject* object, double dt)
{
    Pet* pet = static_cast<Pet*>(object);

    //pet->UpdatePetProperty();
}

void Pet::State_ChangeType::CheckExit(GameObject* object)
{
    Pet* pet = static_cast<Pet*>(object);

    pet->change_state(pet->prev_state);
}



