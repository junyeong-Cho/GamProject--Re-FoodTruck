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



	//name, age, hungry, elementstate�� ��� constructor
	Pet();

	~Pet();


	//PetFoods���� 
	


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
	int ChangePetState(PetPropertyName state);
	
	/** Pet�� sprite�� ȭ�鿡 ��ġ�ϴ� ����Դϴ�. */
	void DrawPetSprite(State* state);

	/** Pet�� ���̸� �����ϰ� �Կ��ִ� ����Դϴ�.*/
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

