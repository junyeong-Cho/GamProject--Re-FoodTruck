#pragma once
#include "Sprite.h"
#include "Vec2.h"
#include "KitchenPosition.h"

class Ingredient
{
public:
	CS230::Sprite sprite;
	Math::vec2 position{ 100,300 };
	int cuttingNum = 5;
	KitchenPosition where;
	double spriteHalfWidth = 30;

	Ingredient(KitchenPosition whereis, Math::vec2 pos) 
	{ 
		where = whereis;
		position = pos;
	}

	virtual void DrawImage() = 0;
	void ChangePos(Math::vec2 pos);
	bool IsMouseOn(Math::vec2 mousePos);
	void ChangeWhere();

private:

};

class Lettuce : public Ingredient
{
public:

	Lettuce(KitchenPosition whereis, Math::vec2 pos)
		:Ingredient(whereis, pos){}
	void DrawImage() override;
private:
};

class Sauce : public Ingredient
{
public:
	Sauce(KitchenPosition whereis, Math::vec2 pos) 
		:Ingredient(whereis, pos) {}
	void DrawImage() override;
private:

};