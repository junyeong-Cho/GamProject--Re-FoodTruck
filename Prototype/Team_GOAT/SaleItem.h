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


	SaleItem(ItemPosition whereis, Math::vec2 pos, ItemName id, int num)
	{
		where	 = whereis;
		position = pos;
		name	 = id;
		itemNum  = num;
	}

	virtual void DrawImage() = 0;
	virtual void GetName() = 0;

	void ChangePos(Math::vec2 pos);
	bool IsMouseOn(Math::vec2 mousePos);


private:

};


class Apple : public SaleItem
{
public:

	Apple(ItemPosition whereis, Math::vec2 pos, ItemName id, int num)
		:SaleItem(whereis, pos, id, num) {}

	void DrawImage() override;
	void GetName() override;

private:
};

class Pizza : public SaleItem
{
public:
	Pizza(ItemPosition whereis, Math::vec2 pos, ItemName id, int num)
		:SaleItem(whereis, pos, id, num) {}

	void DrawImage() override;
	void GetName() override;
private:

};

class Chicken : public SaleItem
{
public:
	Chicken(ItemPosition whereis, Math::vec2 pos, ItemName id, int num)
		:SaleItem(whereis, pos, id, num) {}

	void DrawImage() override;
	void GetName() override;
private:
};