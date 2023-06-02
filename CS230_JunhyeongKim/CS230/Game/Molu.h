/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Molu.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    March 2, 2023
*/

#pragma once
#include "Customer.h"

class Molu : public Customor
{
public:
	Molu(Customor* front);
	std::string Order_text() { return "MO?LU"; };
};