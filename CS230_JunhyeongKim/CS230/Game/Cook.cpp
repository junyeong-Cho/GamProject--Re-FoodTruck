#include "Cook.h"

Cook::Cook()
{
	/*ingredients.push_back(new Lemon{IngredientName::Lemon, })*/
}

void Cook::Load()
{
	operation.Load();
	tool.Load();
}

void Cook::Update(double dt)
{
	operation.Update();
	tool.ChangeTool(operation.Return());
}

void Cook::Draw()
{
	tool.Draw();

	//�갡 �׻� ���� ���� �׷�������.
	operation.Draw();
}
