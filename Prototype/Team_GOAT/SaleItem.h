#pragma once

#include "ItemPosition.h"
#include "ItemName.h"
#include "Vec2.h"



class SaleItem
{
public:
	Math::vec2 position{ 100,300 };

	int itemNum = 5;
	
	double spriteHalfWidth = 100;


	ItemPosition   where;
	ItemName		name;


	SaleItem(ItemPosition whereis, Math::vec2 pos, ItemName id)
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


class Apple : public SaleItem
{
public:

	Apple(ItemPosition whereis, Math::vec2 pos, ItemName id)
		:SaleItem(whereis, pos, id) {}

	void DrawImage() override;

private:
};

class Pizza : public SaleItem
{
public:
	Pizza(ItemPosition whereis, Math::vec2 pos, ItemName id)
		:SaleItem(whereis, pos, id) {}

	void DrawImage() override;
private:

};

class Chicken : public SaleItem
{
public:
	Chicken(ItemPosition whereis, Math::vec2 pos, ItemName id)
		:SaleItem(whereis, pos, id) {}

	void DrawImage() override;
private:
};