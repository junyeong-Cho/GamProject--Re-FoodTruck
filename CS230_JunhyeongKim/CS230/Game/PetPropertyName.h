#pragma once
enum class PetPropertyName
{
	FIRE,
	WATER,
	NORMAL
};

inline PetPropertyName& operator+=(PetPropertyName& name, int value)
{
	if (name == PetPropertyName::NORMAL)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == PetPropertyName::WATER) ? PetPropertyName::FIRE : PetPropertyName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == PetPropertyName::FIRE) ? PetPropertyName::WATER : PetPropertyName(static_cast<int>(name) + value);
	}
	return name;
}