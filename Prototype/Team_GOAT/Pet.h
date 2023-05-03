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

	//name, age, hungry, elementstate�� ��� constructor
	Pet();

	~Pet();



	//Tutorial�� ���� �� �ִ� vector����
	std::vector<std::string> tutorial;

	/** Pet�� �̸��� �����ϴ� ����Դϴ�. */
	void SetInfo();

	/** Pet�� ������ ����ϴ� ����Դϴ�. */
	void PrintInfo();

	int GetAge()	const;
	int GetHungry() const;
	

	/** ���� �̸��� ��ȯ�ϴ� ����Դϴ�. */
	std::string GetName() const;

	/** ������� ������Ʈ �ϴ� ����Դϴ�. */
	void PetHungerUpdate();
	

	/** ���� ���¸� ������Ʈ �ϴ� ����Դϴ�. */
	int ChangePetState(ElementState state);
	
	/** Pet�� sprite�� ȭ�鿡 ��ġ�ϴ� ����Դϴ�. */
	void DrawPetSprite(State* state);

	/** Pet�� ���̸� �����ϰ� �Կ��ִ� ����Դϴ�.*/
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
