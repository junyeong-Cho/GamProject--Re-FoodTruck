#pragma once
enum class RecipeName
{
	LemonSalad,
	SaltSalad,
	LeafSalad,
	AntSalad,
	DragonFruitSalad,
	MermaidScalesSalad,
	WaterSoup,
	AntSoup,
	StrongSoup
};

inline RecipeName& operator+=(RecipeName& name, int value)
{
	if (value > 0)
	{
		name = (name == RecipeName::StrongSoup) ? RecipeName::StrongSoup : RecipeName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == RecipeName::LemonSalad) ? RecipeName::LemonSalad : RecipeName(static_cast<int>(name) + value);
	}
	return name;
}