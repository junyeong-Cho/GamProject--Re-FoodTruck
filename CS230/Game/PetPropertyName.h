#pragma once
enum class PetPropertyName
{
	FIRE,
	WATER,
	NOTHING
};

inline PetPropertyName& operator+=(PetPropertyName& name, int value)
{
	if (name == PetPropertyName::NOTHING)
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