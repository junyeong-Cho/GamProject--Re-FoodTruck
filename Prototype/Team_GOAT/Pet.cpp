#include "Pet.h"

Pet::Pet()
{
	std::cout << "Choose your pet name!" << std::endl;
	std::getline(std::cin, name);

	age			 = 0;
	hungry		 = 5;
	name;
	elementState = NORMAL;
}

Pet::~Pet()
{

}

void Pet::SetInfo()
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
	doodle::set_outline_color(0, 102, 153);
	doodle::set_fill_color(255);


	doodle::draw_text("Age: " + std::to_string(age), 100, 300);
	doodle::draw_text("Hungry: " + std::to_string(hungry), 100, 250);
	doodle::draw_text("Name: " + name, 100, 200);

	if (elementState == NORMAL)
	{
		doodle::draw_text("Element: NORMAL", 100, 150);
	}
	else if (elementState == FIRE)
	{
		doodle::draw_text("Element: FIRE", 100, 150);
	}
	else if (elementState == WATER)
	{
		doodle::draw_text("Element: WATER", 100, 150);
	}
	
	doodle::draw_text("isCooking: " + std::to_string(isCooking), 100, 100);
	doodle::draw_text("isHungry : " + std::to_string(isHungry), 100, 50);

}


void Pet::PetHungerUpdate()
{
	if (isCooking == true)
	{
		hungry -= 1;

		if (hungry <= 0)
		{
			isHungry = true;
		}
	}
	else
	{
		isHungry = false;
	}
}



int Pet::ChangePetState(PetPropertyName state)
{
	if (isHungry == false)
	{
		if (changeType == true)
		{
			switch (state)
			{
			case NORMAL:
				elementState = NORMAL;
				canCooking = false;
				break;

			case FIRE:
				elementState = FIRE;
				canCooking = true;

				break;

			case WATER:
				elementState = WATER;
				canCooking = true;

				break;

			default:

				break;
			}
		}
	}
	else
	{
		elementState = NORMAL;
		canCooking = false;
	}


	return 0;
}

void Pet::DrawPetSprite(State* state)
{
	switch (*state)
	{
	case State::Encount:

		doodle::draw_text("He is watching you!", 100, 100);

		break;

	case State::Counter:
		  if (elementState == NORMAL)
		  {
			  if (isHungry == true)
			  {
				  doodle::draw_text("He is hungry right now!", 100, 100);
			  }
			  else
			  {
				  doodle::draw_text("He is now happy!", 200, 300);
			  }
		  }
		  else if (elementState == FIRE)
		  {
			  if (isHungry == true)
			  {
				  doodle::draw_text("He is hungry right now!", 100, 100);
			  }
			  else
			  {
				  doodle::draw_text("He is now happy!", 200, 300);
			  }
		  }
		  else if (elementState == WATER)
		  {
			  if (isHungry == true)
			  {
				  doodle::draw_text("He is hungry right now!", 100, 100);
			  }
			  else
			  {
				  doodle::draw_text("He is now happy!", 200, 300);
			  }
		  }

		break;


	case State::Evaluation_screen:
		switch (elementState)
		{
			case Pet::NORMAL:
				//blabla
			break;
		
			case Pet::FIRE:
				//blabla
			break;
		
			case Pet::WATER:
			//blabla
			break;

			default:
			
				break;
		}

		break;

	case State::Kitchen:
		if (isHungry == false)
		{
			doodle::draw_text("Ready to cook!", 50, 400);

			if (canCooking == true && isCooking == true)
			{
				doodle::draw_text("He is making something right now!", 200, 300);
			}
		}
		else
		{
			doodle::draw_text("He is hungry!", 200, 300);
		}
		break;
	}
}


