#pragma once
#include <vector>
#include "Ingredient.h"
#include "Tool.h"
#include "InventoryManager.h"

class Cook
{
public:
	Cook();
	void Update(double dt);
    void Draw();
    
private:
    std::vector<Cook> cooks;
    std::vector<Ingredient*> ingredients;
    std::vector<Tool*> tools;
    std::vector<InventoryManager> inventoryManager;
};