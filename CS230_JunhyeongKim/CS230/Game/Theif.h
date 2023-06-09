/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Theif.h
Project:    GAM150
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#pragma once
#include "Customer.h"

class Theif : public Customor
{
public:
	Theif(Customor* front);
	std::string Order_text()	  { return "Give me watersoupt quick!!"; };
	std::string Grade_bad_text()  { return "Well...Well.."; }
	std::string Grade_soso_text() { return "It's quite edible~!"; }
	std::string Grade_good_text() { return "That was perfect!"; }
};