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
	
}

Store::~Store()
{

}

void Store::Load()
{
	isMouseClick = false;

	Apple* apple_pocket = new Apple(ItemPosition::LEFT, Math::vec2{ first_X, first_Y }, ItemName::APPLE, 0);
	Apple* apple_store  = new Apple(ItemPosition::LEFT, Math::vec2{ first_X, first_Y }, ItemName::APPLE, 5);
	
	
	Pizza* pizza_pocket = new Pizza(ItemPosition::MIDDLE, Math::vec2{ first_X + width, first_Y }, ItemName::PIZZA, 0);
	Pizza* pizza_store  = new Pizza(ItemPosition::MIDDLE, Math::vec2{ first_X + width, first_Y }, ItemName::PIZZA, 5);


	Chicken* chicken_pocket = new Chicken(ItemPosition::RIGHT, Math::vec2{ first_X + width * 2, first_Y }, ItemName::CHICKEN, 0);
	Chicken* chicken_store = new Chicken(ItemPosition::RIGHT, Math::vec2{ first_X + width * 2, first_Y }, ItemName::CHICKEN, 5);

		storeItems.push_back(apple_store);

		storeItems.push_back(pizza_store);

		storeItems.push_back(chicken_store);

		buyingItems.push_back(apple_pocket);

		buyingItems.push_back(pizza_pocket);

		buyingItems.push_back(chicken_pocket);

}

void Store::Update(double Width, double Height)
{
	Width_raito = Width;
	Height_raito = Height;

	doodle::push_settings();

	doodle::set_frame_of_reference(doodle::FrameOfReference::RightHanded_OriginBottomLeft);

	//CreatingItems();
	BuyItem();

	DrawItem();
	//WriteItemsQuantity();


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

		if (doodle::MouseIsPressed == true)
		{
			buyingItems[0]->itemNum += 1;
			storeItems[0]->itemNum -= 1;
			isMouseClick = false;

			if (GetWhere(WhereIsMouse()) == ItemPosition::MIDDLE)
			{
				buyingItems[1]->itemNum += 1;
				storeItems[1]->itemNum -= 1;

				isMouseClick = false;
			}
			else if (GetWhere(WhereIsMouse()) == ItemPosition::RIGHT)
			{
				buyingItems[2]->itemNum += 1;
				storeItems[2]->itemNum -= 1;

				isMouseClick = false;
			}
		}
	}
}

void Store::DrawItem()
{
	if (storeItems.size() != 0)
	{
		for (int i = 0; i < storeItems.size(); ++i)
		{
			if (storeItems.size() != 0)
			{
				storeItems[i]->DrawImage();
				//doodle::draw_text(std::to_string(storeItems[i]->itemNum), 200, 200);
			}
		}
	}
}
/*
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
					doodle::draw_text("5 out of " + std::to_string(buyingItems[i]->itemNum) + "left",400, 400);
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
*/

void Store::CreatingItems()
{
	if (storeItems.size() != 0)
	{
		for (int i = 0; i < storeItems.size(); ++i)
		{
			if (storeItems.size() != 0)
			{
				buyingItems.push_back(storeItems[i]);

				storeItems[i]->itemNum -= 1;
							
				whatMouseclickIndex = buyingItems.size() - 1;
			}
			else if (storeItems[i]->itemNum >= 3)
			{
				break;
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
