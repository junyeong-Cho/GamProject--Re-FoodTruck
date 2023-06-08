#pragma once
#include <vector>
#include <map>
#include "Ingredient.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"

class Slot
{
public:
	Slot(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize);
	virtual void Load() = 0;
	void Draw(int index);
	void DrawIngredient(const std::vector<std::vector<CS230::Texture*>>& texture);
	void Update(double dt, int size);
	void Unload();
	void ButtonDraw();
	bool ButtonClick(Math::vec2 pos);
	void ChangePos(Math::vec2 pos) { position = pos; }
	virtual bool PutIngredient(Ingredient* ingredient) = 0;
	std::vector<Ingredient*>& GetIngredientVec();
	void DrawSlotRect();
	void SetSlotPos();

protected:
	std::vector<CS230::Texture*> texture;
	Math::vec2 position;
	Math::vec2 size;
	std::vector<Ingredient*> vector;

	//variables
	//slotRect
	Math::vec2 standardSlotRectPos{ 0.0,350.0 };
	Math::vec2 standardSlotRectPadding{ 10.0, 10.0 };
	Math::vec2 standardSlotRectSize{ 50.0,50.0 };
	std::map<int, Math::vec2> slotPos;

	//button
	Math::vec2 buttonPos;
	Math::vec2 buttonSize;

protected:
	int putSize = 0;

};

class Plate : public Slot
{
public:
	Plate(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize);
	void Load() override;
	bool PutIngredient(Ingredient* ingredient) override;
	
private:
	double padding = 30.0;
};

class Pot : public Slot
{
public:
	Pot(Math::vec2 pos, Math::vec2 size, Math::vec2 buttonPos, Math::vec2 buttonSize);
	void Load() override;
	bool PutIngredient(Ingredient* ingredient) override;

private:
	double padding = 80.0;

};