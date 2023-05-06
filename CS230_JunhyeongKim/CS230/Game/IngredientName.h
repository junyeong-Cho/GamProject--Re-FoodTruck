#pragma once
enum class IngredientName
{
	Remon,
	Lettuce,
	Ant,
	Leaf,
	Salt,
	DragonFruit,
	MermaidScales,
	Nothing
};

inline IngredientName& operator+=(IngredientName& name, int value)
{
	if (name == IngredientName::Nothing)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == IngredientName::MermaidScales) ? IngredientName::Remon : IngredientName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == IngredientName::Remon) ? IngredientName::MermaidScales : IngredientName(static_cast<int>(name) + value);
	}
	return name;
}