#pragma once


#include "../Engine/GameObject.h"
#include "../Engine/Input.h"
#include "../Engine/Matrix.h"
#include "PetPropertyName.h"



class Pet : public CS230::GameObject
{
    //friend int main();

public:
    Pet(Math::vec2 start_position);

    void Update(double dt) override;

    const Math::vec2& GetPosition() const { return GameObject::GetPosition(); }

    /*PetPropertyName  elementState;*/

private:

    int  hungry;

    bool isHappy = false;
    bool isHungry = false;
    bool isCooking = false;

    bool checkMouse = false;

    bool on_mouse_wheel = false;


    void UpdatePetProperty(PetPropertyName name);

    void PetHungerUpdate();

    void PetEatingFood();

    enum class CounterAnimations
    {
        IDLE_STANDING,
        FIRE_STANDING,
        WATER_STANDING,

        IDLE_HUNGRY,
        FIRE_HUNGRY,
        WATER_HUNGRY,

        IDLE_HAPPY,
        FIRE_HAPPY,
        WATER_HAPPY,

        IDLE_SAD,
        FIRE_SAD,
        WATER_SAD,
    };

    enum class KitchenAnimations
    {
        IDLE_STANDING,
        FIRE_STANDING,
        WATER_STANDING,

        IDLE_HUNGRY,
        FIRE_HUNGRY,
        WATER_HUNGRY,

        IDLE_COOKING,
        FIRE_COOKING,
        WATER_COOKING
    };

    //Finite State Machines
    class State_Idle : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Jumping"; }
    };

    class State_Cooking : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Jumping"; }
    };

    class State_Hungry : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };

    class State_ChangeType : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Falling"; }
    };


    State_Idle 	     state_idle;

    State_Cooking    state_cooking;

    State_Hungry     state_hungry;

    State_ChangeType state_change_type;

   PetPropertyName  elementState;
};
