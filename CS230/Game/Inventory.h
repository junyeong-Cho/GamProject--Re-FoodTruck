#pragma once
#include "InventoryName.h"
#include "ToolName.h"
#include "IngredientName.h"
#include "PetPropertyName.h"

class InventoryManager
{
public:
	InventoryManager();
	virtual void Update() = 0;
	virtual void Draw() = 0;

	static int wheel;
	static bool leftClick;
	static bool rightClick;

private:
	int num = 3;
	InventoryName clickInventory;

	void Draw_Inventory();
	void Draw_ToolBoxInventory();
	void Draw_Refrigerator();
	void Draw_PetProperty();

	InventoryName ClickInventory();
	InventoryName ChooseInvenroty();
	ToolName Logic_TooBoxlInventory();
	IngredientName Logic_Refrigerator();


};

class Inventory : InventoryManager
{
public:
	void Draw() override;
	void Update() override;
private:
	InventoryName inventory = InventoryName::Nothing;
};

class ToolBox : InventoryManager
{
public:
	void Draw() override;
	void Update() override;
private:
	ToolName tool = ToolName::HAND;
};

class Refrigerator : InventoryManager
{
public:
	void Draw() override;
	void Update() override;
private:

};

class PetProperty : InventoryManager
{
public:
	void Draw() override;
	void Update() override;
private:
	PetPropertyName property = PetPropertyName::FIRE;
};
