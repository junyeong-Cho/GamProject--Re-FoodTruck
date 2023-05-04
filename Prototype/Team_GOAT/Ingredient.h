#pragma once
#include "Vec2.h"
#include "KitchenPosition.h"
#include "IngredientName.h"

class Ingredient
{
public:
	Math::vec2 position{ 100,300 };
	int cuttingNum = 5;
	KitchenPosition where;
	double spriteHalfWidth = 30;
	IngredientName name;


	Ingredient(KitchenPosition whereis, Math::vec2 pos, IngredientName id)
	{ 
		where	 = whereis;
		position = pos;
		name	 = id;
	}

	virtual void DrawImage() = 0;
	void ChangePos(Math::vec2 pos);
	bool IsMouseOn(Math::vec2 mousePos);

private:

};

class Lettuce : public Ingredient
{
public:

	Lettuce(KitchenPosition whereis, Math::vec2 pos,IngredientName id)
		:Ingredient(whereis, pos, id){}
	void DrawImage() override;
private:
};

class Sauce : public Ingredient
{
public:
	Sauce(KitchenPosition whereis, Math::vec2 pos, IngredientName id)
		:Ingredient(whereis, pos, id) {}
	void DrawImage() override;
private:

};