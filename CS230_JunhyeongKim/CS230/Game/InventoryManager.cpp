#include "InventoryManager.h"

InventoryManager::InventoryManager()
{
	operation.push_back(new Inventory());
	operation.push_back(new ToolBox());
	operation.push_back(new PetProperty());
	operation.push_back(new Refrigerator());
}