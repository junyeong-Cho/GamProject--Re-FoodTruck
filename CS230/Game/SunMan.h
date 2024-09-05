/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SunMan.h
Project:    GAM150
Author:     Junyeong Cho
Created:    June 3, 2023
*/

#pragma once
#include "Customer.h"

class SunMan : public Customor
{
public:
	SunMan(Customor* front);
	std::string Order_text()      { return "Give me a one beautiful Lemon Salad!"; };
	std::string Grade_bad_text()  { return "You're gonna have a bad time"; }
	std::string Grade_soso_text() { return "Umm! Not bad"; }
	std::string Grade_good_text() { return "Great! Exactly what I asked for."; }
};