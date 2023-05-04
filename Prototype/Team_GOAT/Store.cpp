#include "Store.h"
#include "Pet.h"
#include "State.h"

//#include <doodle.h>
#include<iostream>
#include<string>
#include<map>

bool Store::isMouseClick = false;


Store::Store()
{
	for (int i = 0; i < itemNum; i++)
	{
		storeItems.push_back(std::vector<SaleItem*>());
	}
}

Store::~Store()
{

}

void Store::Load()
{
	isMouseClick = false;

	Apple* apple = new Apple(ItemPosition::LEFT, Math::vec2{ first_X, first_Y }, ItemName::APPLE);
	
	Pizza* pizza = new Pizza(ItemPosition::MIDDLE, Math::vec2{ first_X + width, first_Y }, ItemName::PIZZA);

	Chicken* chicken = new Chicken(ItemPosition::RIGHT, Math::vec2{ first_X + width * 2, first_Y }, ItemName::CHICKEN);


	if (storeItems.size() == itemNum)
	{
		storeItems[0].push_back(apple);

		storeItems[1].push_back(pizza);

		storeItems[2].push_back(chicken);
	}
}

void Store::Update(double Width, double Height)
{
	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);


	BuyItem();
	CreatingItems();
	WriteItemsQuantity();


	doodle::pop_settings();
}


Math::vec2 Store::WhereIsMouse()
{
	return Math::vec2(doodle::get_mouse_x(), doodle::get_mouse_y());
}


void Store::BuyItem()
{
	if (buyingItems.size() != 0)
	{
		for (int i = 0; i < buyingItems.size(); ++i)
		{
			if (buyingItems[i]->IsMouseOn(WhereIsMouse()) == true && isMouseClick == true && (GetWhere(WhereIsMouse()) == ItemPosition::LEFT || GetWhere(WhereIsMouse()) == ItemPosition::MIDDLE || GetWhere(WhereIsMouse()) == ItemPosition::RIGHT))
			{
				if (buyingItems[i]->itemNum > 0)
				{
					--buyingItems[i]->itemNum;
				}
				
				isMouseClick = false;
			}
		}
	}
}

void Store::WriteItemsQuantity()
{
	if (buyingItems.size() != 0)
	{
		for (int i = 0; i < buyingItems.size(); ++i)
		{
			if (buyingItems[i]->where == ItemPosition::LEFT)
			{
				doodle::push_settings();
				doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);
				doodle::set_font_size(width / 2);
				if (buyingItems[i]->itemNum > 0)
				{
					doodle::draw_text("5 out of " + std::to_string(buyingItems[i]->itemNum) + "left",
						buyingItems[i]->position.x - buyingItems[i]->spriteHalfWidth / 2.0,
						buyingItems[i]->position.y);
				}
				else
				{
					doodle::draw_text("Out of stock!",
						buyingItems[i]->position.x - buyingItems[i]->spriteHalfWidth / 2.0,
						buyingItems[i]->position.y);
				}

				doodle::pop_settings();
			}
		}
	}
}


void Store::CreatingItems()
{
	if (storeItems.size() != 0)
	{
		if (isMouseClick == true)
		{
			for (int i = 0; i < storeItems.size(); ++i)
			{
				if (storeItems[i].size() != 0)
				{
					for (int j = 0; j < storeItems[i].size(); ++j)
					{
						if (storeItems[i][j]->where == GetWhere(WhereIsMouse()) && whatMouseclickIndex == -1)
						{
							buyingItems.push_back(storeItems[i][j]);
							storeItems[i].erase(storeItems[i].begin() + j);
							whatMouseclickIndex = buyingItems.size() - 1;
							isMouseClick = false;
						}
					}
				}
			}
		}
	}
}



ItemPosition Store::GetWhere(Math::vec2 pos)
{
	doodle::push_settings();
	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	if (pos.y > first_Y && pos.y < first_Y + height)
	{
		if (pos.x > first_X + width * 0 && pos.x <= first_X + width * 0 + width)
		{
			return ItemPosition::LEFT;
		}
		else if (pos.x > first_X + width * 1 && pos.x <= first_X + width * 1 + width)
		{
			return ItemPosition::MIDDLE;
		}
		else if (pos.x > first_X + width * 2 && pos.x <= first_X + width * 2 + width)
		{
			return ItemPosition::RIGHT;
		}
	}

	doodle::pop_settings();

	return ItemPosition::ELSE;
}
