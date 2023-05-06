#include "Cook.h"

Cook::Cook()
{

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

	//얘가 항상 제일 위에 그려져야함.
	operation.Draw();
}
