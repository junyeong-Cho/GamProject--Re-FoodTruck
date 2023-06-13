/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Zilien.h
Project:    GAM150
Author:     Junyeong Cho
Created:    June 1, 2023
*/

#pragma once
#include "Customer.h"

class Zilien : public Customor
{
public:
	Zilien(Customor* front);
	std::string Order_text()	  { return "Ah, I'd kindly ask for \njust one Salt Salad, if you please"; };
	std::string Grade_bad_text()  { return "I've already seen your demise. \nIt was a painful end indeed"; }
	std::string Grade_soso_text() { return "Oho not bad"; }
	std::string Grade_good_text() { return "Well, this is downright delicious!"; }
};