/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Elf.h
Project:    GAM150
Author:     Junyeong Cho
Created:    May 24, 2023
*/

#pragma once

#include "Customer.h"

class Elf : public Customor
{
public:
	Elf(Customor* front);
	std::string Order_text() { return "What are you looking at? \nMake a dazzling stir-fry soup!"; };
	std::string Grade_bad_text() { return "Ugh, What a food waste this is!"; }
	std::string Grade_soso_text() { return "Oh... You're pretty good, huh?"; }
	std::string Grade_good_text() { return "You are my master from now!"; }
};