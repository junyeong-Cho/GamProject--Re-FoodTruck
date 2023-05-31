/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Anteater.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    May 24, 2023
*/

#pragma once
#include "Customer.h"

class Anteater : public Customor
{
public:
	Anteater(Customor* front);
	std::string Order_text()	  { return "One plain ant salad, please!"; };
	std::string Grade_bad_text()  { return "BRUH It might be better to go see \nthe Little Mermaid movie!"; }
	std::string Grade_soso_text() { return "It's quite edible~!"; }
	std::string Grade_good_text() { return "Great! Exactly what I asked for"; }
};