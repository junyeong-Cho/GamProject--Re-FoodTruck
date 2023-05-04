#pragma once

#include<doodle/input.hpp>
#include<doodle/drawing.hpp>
#include<doodle/image.hpp>

#include<iostream>
#include<string>
#include<map>

#include "State.h"


class Pet
{
public:
	
	const enum PetPropertyName
	{
		FIRE,
		WATER,
		NORMAL
	};



	//name, age, hungry, elementstate를 담는 constructor
	Pet();

	~Pet();


	//PetFoods들을 
	


	/** Pet의 이름을 설정하는 기능입니다. */
	void SetInfo();

	/** Pet의 정보를 출력하는 기능입니다. */
	void PrintInfo();

	int GetAge()	const;
	int GetHungry() const;
	

	/** 펫의 이름을 반환하는 기능입니다. */
	std::string GetName() const;

	/** 배고픔을 업데이트 하는 기능입니다. */
	void PetHungerUpdate();
	

	/** 펫의 상태를 업데이트 하는 기능입니다. */
	int ChangePetState(PetPropertyName state);
	
	/** Pet의 sprite를 화면에 배치하는 기능입니다. */
	void DrawPetSprite(State* state);

	/** Pet의 먹이를 구매하고 먹여주는 기능입니다.*/
	void catRevive();


private:
	bool canCooking = false;

	bool isCooking = false;
	bool isHungry   = false;
	bool isSitting  = false;
	
	bool changeType = false;

	bool cookState  = false;

	int  age;
	int  hungry;

	std::string name;

	PetPropertyName elementState;

};

