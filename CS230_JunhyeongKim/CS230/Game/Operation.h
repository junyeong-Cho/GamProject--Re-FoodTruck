#pragma once
#include "InventoryName.h"
#include "ToolName.h"
#include "IngredientName.h"
#include "PetPropertyName.h"
#include "..\Engine\Texture.h"

class Operation
{
public:
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	static int wheel;
	static bool leftClick;
	static bool rightClick;

private:
	InventoryName clickInventory;
	CS230::Texture* operationTexture;
};

class Inventory : public Operation
{
public:
	Inventory();
	void Load() override;
	void Draw() override;
	void Update() override;
	InventoryName Return() { return inventory; }
private:
	InventoryName inventory = InventoryName::Nothing;
};

class ToolBox : public Operation
{
public:
	ToolBox();
	void Load() override;
	void Draw() override;
	void Update() override;
	ToolName Return() { return tool; }
private:
	ToolName tool = ToolName::HAND;
};

class Refrigerator : public Operation
{
public:
	Refrigerator();
	void Load() override;
	void Draw() override;
	void Update() override;
	IngredientName Return() { return ingredient; }
private:
	IngredientName ingredient = IngredientName::Nothing;
};

class PetProperty : public Operation
{
public:
	PetProperty();
	void Load() override;
	void Draw() override;
	void Update() override;
	PetPropertyName Return() { return property; }
private:
	PetPropertyName property = PetPropertyName::FIRE;
};
