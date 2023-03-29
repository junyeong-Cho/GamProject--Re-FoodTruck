#pragma once
#include "Sprite.h"
#include "Vec2.h"
#include "KitchenPosition.h"

class Ingredient
{
public:
	CS230::Sprite sprite;
	bool isClick = false;
	Math::vec2 position{ 100,300 };
	int cuttingNum = 5;
	KitchenPosition where;
	int number = 3;

	Ingredient(KitchenPosition whereis, Math::vec2 pos) 
	{ 
		where = whereis;
		position = pos;
	}

private:

};

class Lettuce : public Ingredient
{
public:

	Lettuce(KitchenPosition whereis, Math::vec2 pos):Ingredient(whereis, pos){}
private:
};

class Sauce : public Ingredient
{
public:
	Sauce(KitchenPosition whereis, Math::vec2 pos) :Ingredient(whereis, pos) {}
private:

};