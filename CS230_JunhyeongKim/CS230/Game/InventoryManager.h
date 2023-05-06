#pragma once
#include "Operation.h"
#include <vector>

class InventoryManager
{
public:
	InventoryManager();
	void Draw();
	void Update();
private:
	std::vector<Operation*> operation;
};