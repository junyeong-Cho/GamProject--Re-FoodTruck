#pragma once
#include <vector>
#include <map>
#include "Ingredient.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"

class Slot
{
public:
	Slot(Math::vec2 pos);
	virtual void Load() = 0;
	virtual void Draw(int index) = 0;
	void DrawIngredient();
	void Update(double dt);
	void Unload();
	virtual void ButtonDraw() = 0;
	void ChangePos(Math::vec2 pos) { position = pos; }
	bool PutIngredient(Ingredient* ingredient);
	std::vector<Ingredient*> vector;

protected:
	std::vector<CS230::Texture*> texture;
	Math::vec2 position;
	std::map<int, Math::vec2> slotPos;

private:


};

class Plate : public Slot
{
public:
	Plate(Math::vec2 pos);
	void Load() override;
	bool ButtonClick(Math::vec2 pos);
	void ButtonDraw() override;
	void Draw(int index)override;

private:

};

class Pot : public Slot
{
public:
	Pot(Math::vec2 pos);
	void Load() override; 
	void ButtonDraw() override;
	bool ButtonClick(Math::vec2 pos);
	void Draw(int index)override;

private:
	

};