/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Greendragon.h
Project:    GAM150
Author:     Junyeong Cho
Created:    June 1, 2023
*/

#pragma once
#include "Customer.h"

class Greendragon : public Customor
{
public:
	Greendragon(Customor* front);
	std::string Order_text() { return "...Strong Soup"; };
	std::string Grade_bad_text() { return "..."; }
	std::string Grade_soso_text() { return "...!"; }
	std::string Grade_good_text() { return "...It's good than I thought"; }
};