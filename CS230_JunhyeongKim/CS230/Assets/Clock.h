#pragma once



#pragma once

#include "..\Engine\GameObject.h" 
#include "..\Engine\Input.h"
#include "..\Engine\Camera.h"


class Clock : public CS230::GameObject
{
public:
    Clock(Math::vec2 start_position);
    void Update(double dt) override;



private:
    enum class Animations
    {
        Idle,
        Moving,
    };



    //Finite State Machines
    class State_Idle : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };

    class State_Moving : public State
    {
    public:
        virtual void Enter(GameObject* object) override;
        virtual void Update(GameObject* object, double dt) override;
        virtual void CheckExit(GameObject* object) override;
        std::string GetName() override { return "Idle"; }
    };


    State_Idle state_idle;

    State_Moving state_moving;


};
