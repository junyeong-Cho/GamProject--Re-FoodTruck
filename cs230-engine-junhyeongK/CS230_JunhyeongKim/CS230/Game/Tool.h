#pragma once
#include "ToolName.h"

class Tool 
{
public:
    Tool();
    void Update(double dt);
    virtual void Draw() = 0;
    void ChangeTool(ToolName toolName) { tool = toolName; }
    ToolName GetTool() { return tool; }
 
private:
    ToolName tool = ToolName::HAND;
    
};

class Hand : Tool
{
public:
    Hand();
    void Draw() override;

private:


};

class Knife : Tool
{
public:
    Knife();
    void Draw() override;

private:


};

class Ladle : Tool
{
public:
    Ladle();
    void Draw() override;

private:


};

class Scoop : Tool
{
public:
    Scoop();
    void Draw() override;

private:


};

class TrashCan : Tool
{
    TrashCan();
    void Draw() override;
};