#pragma once
#include "InventoryName.h"
#include "ToolName.h"
#include "IngredientName.h"
#include "PetPropertyName.h"

class Operation
{
public:
	Operation(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;

	static int wheel;
	static bool leftClick;
	static bool rightClick;

private:
	InventoryName clickInventory;

};

class Inventory : public Operation
{
public:
	Inventory() : Operation(){}
	void Draw() override;
	void Update() override;
	InventoryName Return() { return inventory; }
private:
	InventoryName inventory = InventoryName::Nothing;
};

class ToolBox : public Operation
{
public:
	ToolBox(){}
	void Draw() override;
	void Update() override;
	ToolName Return() { return tool; }
private:
	ToolName tool = ToolName::HAND;
};

class Refrigerator : public Operation
{
public:
	Refrigerator(){}
	void Draw() override;
	void Update() override;
	IngredientName Return() { return ingredient; }
private:
	IngredientName ingredient = IngredientName::Nothing;
};

class PetProperty : public Operation
{
public:
	PetProperty(){}
	void Draw() override;
	void Update() override;
	PetPropertyName Return() { return property; }
private:
	PetPropertyName property = PetPropertyName::FIRE;
};
