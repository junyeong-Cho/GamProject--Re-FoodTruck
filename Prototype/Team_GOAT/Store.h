

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "State.h"
#include "SaleItem.h"

class Store
{
	public:
	Store();
	~Store();

	std::vector<SaleItem *> storeItems;
	std::vector<SaleItem *>	buyingItems;
	std::vector<SaleItem *>	inPocket;

	int itemNum{ 3 };

	void Load();

	void Update(double Width, double Height);

	void BuyItem();
	void DrawItem();
	void CreatingItems();
	void WriteItemsQuantity();


	Math::vec2   WhereIsMouse();
	ItemPosition GetWhere(Math::vec2 pos);


	double first_X{  50.0 };
	double first_Y{ 400.0 };
	double width  { 200.0 };
	double height { 200.0 };

	static bool isMouseClick;

	private:

		int whatMouseclickIndex = -1;

		double Width_raito = 0;
		double Height_raito = 0;

};
