#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "Operation.h"

class Cook
{
public:
	Cook();
    void Load();
	void Update(double dt);
    void Draw();
    
private:
    std::vector<Cook> cooks;
    std::vector<Ingredient*> ingredients;
    Tool tool;
    Operation operation;
};