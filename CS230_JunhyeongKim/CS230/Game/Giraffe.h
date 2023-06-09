/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Giraffe.h
Project:    GAM150
Author:     Junhyeong Kim
Created:    March 2, 2023
*/

#pragma once
#include "Customer.h"

class Giraffe : public Customor
{
public:
	Giraffe(Customor* front);
	std::string Order_text() { return "I'd like a pretty salad, please!"; };
	std::string Grade_bad_text() { return "I don't think that's \n how business works!"; }
	std::string Grade_soso_text() { return " Oooops, It's an insult to the salad!"; }
	std::string Grade_good_text() { return "HAHA, Sooooooooooo delicious!"; }

};