/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Amy.h
Project:    GAM150
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#pragma once
#include "Customer.h"

class Amy : public Customor
{
public:
	Amy(Customor* front);
	std::string Order_text()      { return "Could you give me a some AntSoup please?"; };
	std::string Grade_bad_text()  { return "Umm...It's bad"; }
	std::string Grade_soso_text() { return "It's quite edible~!"; }
	std::string Grade_good_text() { return "Wonderful!"; }
};