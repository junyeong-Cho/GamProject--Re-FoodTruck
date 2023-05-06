#include "Kitchen.h"

Kitchen::Kitchen() : cook(Cook{})
{
	
}

void Kitchen::Load()
{
	cook.Load();
}

void Kitchen::Update(double dt)
{
	cook.Update(dt);
}
void Kitchen::Draw()
{
	Engine::GetWindow().Clear(0xFFFFFFFF);
	Draw_UI();
	cook.Draw();
}
void Kitchen::Unload()
{

}

void Kitchen::Draw_UI()
{
	Draw_Base();

}

void Kitchen::Draw_Base()
{
	//�ֹ濡 �ִ� ����
}

void Kitchen::Draw_Clock()
{
	//�ð�
}

void Kitchen::Draw_Money()
{
	//��
}

void Kitchen::Draw_Recipe()
{

}