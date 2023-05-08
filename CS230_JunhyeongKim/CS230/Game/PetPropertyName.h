#pragma once
enum class PetPropertyName
{
	FIRE,
	WATER,
	IDLE
};

inline PetPropertyName& operator+=(PetPropertyName& name, int value)
{
	if (name == PetPropertyName::IDLE)
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