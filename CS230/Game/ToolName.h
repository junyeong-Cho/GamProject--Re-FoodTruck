#pragma once
enum class ToolName
{
	HAND,
	KNIFE,
	LADLE,
	SCOOP,
	TRASHCAN,
	Nothing
};

inline ToolName& operator+=(ToolName& name, int value)
{
	if (name == ToolName::Nothing)
	{
		return name;
	}
	if (value > 0)
	{
		name = (name == ToolName::TRASHCAN) ? ToolName::HAND : ToolName(static_cast<int>(name) + value);
	}
	else if (value < 0)
	{
		name = (name == ToolName::HAND) ? ToolName::TRASHCAN : ToolName(static_cast<int>(name) + value);
	}
	return name;
}