/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Animation.h
Project:    GAM150
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once
#include <vector>
#include <fstream>

enum class CommandType
{
    PlayFrame,
    Loop,
    End,
};


class Command 
{
public:
    virtual ~Command() {}
    virtual CommandType Type() = 0;
};


class End : public Command 
{
public:
    virtual CommandType Type() override { return CommandType::End; }
private:
};


class Loop : public Command
{
public:
    Loop(int loop_index) : loop_index(loop_index){}
    virtual CommandType Type() override { return CommandType::Loop; }
    int LoopIndex() { return loop_index; }
private:
    int loop_index;
};

class PlayFrame : public Command 
{
public:
    PlayFrame(int frame, double duration) : frame(frame), target_time(duration), timer(0)
    {}

    virtual CommandType Type() override { return CommandType::PlayFrame; }
    void Update(double dt);
    bool Ended()
    {
        if (timer < target_time)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void ResetTime()
    {
        timer = 0;
    }

    int Frame()
    {
        return frame;
    }

private:
    int frame;
    double target_time;
    double timer = 0.0;
};




namespace CS230 {
    class Animation {
    public:
        Animation();
        Animation(const std::filesystem::path& animation_file);
        ~Animation();

        void Update(double dt);
        int CurrentFrame();
        void Reset();
        bool Ended();
    private:


        int current_command;
        std::vector<Command*> commands;
        bool ended;
        PlayFrame* current_frame;
    };


}
