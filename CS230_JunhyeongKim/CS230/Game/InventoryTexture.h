#pragma once
enum class InventoryTexture
{
	ToolBox,
	PetProperty,
	Refrigerator,
	Hand,
	Knife,
	Ladle,
	Scoop,
	TrashCan,
	Fire,
	Water,
	Ingredient,
	Nothing
};

inline InventoryTexture& operator+=(InventoryTexture& name, int value)
{
	if (name == InventoryTexture::Ingredient)
	{
		return name = InventoryTexture::Ingredient;
	}
	if (name == InventoryTexture::Nothing)
	{
		return name = InventoryTexture::Nothing;
	}
	if (value > 0)
	{
		if (name >= InventoryTexture::ToolBox && name <= InventoryTexture::Refrigerator)
		{
			name = (name == InventoryTexture::Refrigerator) ? InventoryTexture::ToolBox : InventoryTexture(static_cast<int>(name) + value);
		}
		else if (name >= InventoryTexture::Hand && name <= InventoryTexture::TrashCan)
		{
			name = (name == InventoryTexture::TrashCan) ? InventoryTexture::Hand : InventoryTexture(static_cast<int>(name) + value);
		}
		else if (name >= InventoryTexture::Fire && name <= InventoryTexture::Water)
		{
			name = (name == InventoryTexture::Water) ? InventoryTexture::Fire : InventoryTexture(static_cast<int>(name) + value);
		}
	}
	else if (value < 0)
	{
		if (name >= InventoryTexture::ToolBox && name <= InventoryTexture::Refrigerator)
		{
			name = (name == InventoryTexture::ToolBox) ? InventoryTexture::Refrigerator : InventoryTexture(static_cast<int>(name) + value);
		}
		else if (name >= InventoryTexture::Hand && name <= InventoryTexture::TrashCan)
		{
			name = (name == InventoryTexture::Hand) ? InventoryTexture::TrashCan : InventoryTexture(static_cast<int>(name) + value);
		}
		else if (name >= InventoryTexture::Fire && name <= InventoryTexture::Water)
		{
			name = (name == InventoryTexture::Fire) ? InventoryTexture::Water : InventoryTexture(static_cast<int>(name) + value);
		}
	}
	return name;
}