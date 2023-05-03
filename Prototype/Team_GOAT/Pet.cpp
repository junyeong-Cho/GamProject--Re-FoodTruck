#include "Pet.h"

Pet::Pet(int age, int hungry, std::string name)
	: age(age), hungry(hungry), name(name)
{
	std::cout << "Put your pet's age, hungry, name!" << std::endl;

	std::cin >> age;
	std::cin >> hungry;
	std::cin >> name;
}

Pet::~Pet()
{

}

void Pet::SetInfo(int age, int hungry, std::string name)
{
	this->age	 = age;
	this->hungry = hungry;
	this->name	 = name;
}


int Pet::GetAge() const
{
	return age;
}


int Pet::GetHungry() const
{
	return hungry;
}



std::string Pet::GetName() const
{
	return name;
}


void Pet::PrintInfo()
{
    //print info with doodle::draw_text()
	doodle::set_outline_color(0, 102, 153);
	doodle::set_fill_color(255);

	

	doodle::draw_text("Age: " + std::to_string(age), 100, 100);
	doodle::draw_text("Hungry: " + std::to_string(hungry), 100, 150);
	doodle::draw_text("Name: " + name, 100, 200);

}

void Pet::PetHungerUpdate()
{
	if (isCooking == true)
	{
		hungry -= 1;

		if (hungry == 0)
		{
			isHungry = true;
		}
	}
	else
	{
		isHungry = false;
	}
}


//¹Ì¿Ï¼º
int Pet::ChangePetState(short state)
{
	if (isHungry == true)
	{
		if (changeType == true)
		{
			switch (state)
			{
			case FIRE:
				return isCooking = true;
				break;

			case WATER:
				return isCooking = true;
				break;

			case GROUND:
				return isCooking = true;
				break;

			default:

				break;
			}
		}
	}
	else if (isHungry == false)
	{
		isCooking = false;
		canCooking = false;
		isSitting = false;
	}


	return 0;
}
