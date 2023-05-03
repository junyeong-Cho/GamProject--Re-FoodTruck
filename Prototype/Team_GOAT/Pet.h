#include<doodle/input.hpp>
#include<doodle/drawing.hpp>

#include<iostream>
#include<string>
#include<map>

class Pet
{
public:
	
	const enum ElementState
	{
		FIRE,
		WATER,
		GROUND
	};

	Pet(int age, int hungry, std::string name);
	~Pet();

	void SetInfo(int age, int hungry, std::string name);
	void PrintInfo();

	int GetAge()	const;
	int GetHungry() const;


	std::string GetName() const;

	/** 배고픔을 업데이트 하는 기능입니다. */
	void PetHungerUpdate();
	
	int ChangePetState(short state);
	



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

	

};
