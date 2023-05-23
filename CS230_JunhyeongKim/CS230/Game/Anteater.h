/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Anteater.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    March 2, 2023
*/

#pragma once
#include "Customer.h"

class Anteater : public Customor
{
public:
	Anteater(Customor* front);
	std::string Order_text() { return "MO?LU"; };
};