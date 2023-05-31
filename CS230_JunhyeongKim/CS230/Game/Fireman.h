/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Fireman.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 1, 2023
*/

#pragma once
#include "Customer.h"

class Fireman : public Customor
{
public:
	Fireman(Customor* front);
	std::string Order_text()	  { return "Brr(Give me a Water Soup for my litte ghost)"; };
	std::string Grade_bad_text()  { return "Fwoosh!(What is wrong with you!)"; }
	std::string Grade_soso_text() { return "Bla Bla(Not bad!)"; }
	std::string Grade_good_text() { return "Pshoom!(What a nice Soup!)"; }
};