#pragma once
#include "../Engine/vec2.h"
#include "../Engine/Texture.h"
class SideBowl
{
public:
	SideBowl(Math::vec2 pos, std::string cost);
	void Draw();
	bool MouseOn(Math::vec2 mouse);
	bool Refill();
	void DrawCost();
	void DrawButton();
	void ReduceNum(int num);

private:
	Math::vec2 position;
	CS230::Texture* texture;
	std::string cost;
	int number = 3;
};