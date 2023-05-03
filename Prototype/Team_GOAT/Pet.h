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
	
	const enum ElementState
	{
		NORMAL,
		FIRE,
		WATER,
		GROUND
	};

	const enum PetFoods
	{
		APPLE,
		CHICKEN,
		PIZZA,
		CAKE,
		ICECREAM,
		CHOCOLATE,
		PIE
	};

	//name, age, hungry, elementstate를 담는 constructor
	Pet();

	~Pet();



	//Tutorial을 담을 수 있는 vector생성
	std::vector<std::string> tutorial;

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
	int ChangePetState(ElementState state);
	
	/** Pet의 sprite를 화면에 배치하는 기능입니다. */
	void DrawPetSprite(State* state);

	/** Pet의 먹이를 구매하고 먹여주는 기능입니다.*/
	void catRevive();

private:
	bool canCooking = false;

	bool isCooking  = false;
	bool isHungry   = false;
	bool isSitting  = false;
	
	bool changeType = false;

	bool cookState  = false;

	int  age;
	int  hungry;

	std::string name;

	ElementState elementState;

	std::vector<PetFoods> *petfoods;
};
