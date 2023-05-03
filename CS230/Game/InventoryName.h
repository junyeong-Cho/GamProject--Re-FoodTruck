#pragma once
enum class InventoryName
{
	ToolBox,
	Refrigerator,
	PetProperty,
	Nothing
};

inline InventoryName& operator+=(InventoryName& name, int value)
{
	if (name == InventoryName::Nothing)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == InventoryName::PetProperty) ? InventoryName::ToolBox : InventoryName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == InventoryName::ToolBox) ? InventoryName::PetProperty : InventoryName(static_cast<int>(name) + value);
	}
	return name;
}