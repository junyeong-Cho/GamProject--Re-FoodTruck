#include "RecipeName.h"
#include "Ingredient.h"
#include <vector>
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#pragma once
class Recipe
{
public:
	Recipe(RecipeName name, int TotalNum);
	virtual void Load() = 0;
	virtual void Draw() = 0;
	int CheckComplete(std::vector<Ingredient*>& plating);
	void Update();
	void Unload();
protected:
	CS230::Texture* texture;
	Math::vec2 texturePos;
	RecipeName recippeName;
	std::vector<Ingredient*> recipe;

	Lemon* lemon;
	Lemon* boiledLemon;

	Lettuce* lettuce;
	
	Ant* ant;
	Ant* boiledAnt;
	
	Leaf* leaf;
	Leaf* boiledLeaf;
	
	Salt* salt;
	Salt* boiledSalt;
	
	DragonFruit* dragonFruit;
	DragonFruit* boiledDragonFruit;
	
	MermaidScales* mermaidScales;
	MermaidScales* boiledMermaidScales;
	
	Water* boiledwater;

	int score = 0;
	int totalNum = 0;
};

class LemonSalad : public Recipe
{
public:
	LemonSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:
};

class SaltSalad : public Recipe
{
public:
	SaltSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class LeafSalad : public Recipe
{
public:
	LeafSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class AntSalad : public Recipe
{
public:
	AntSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class DragonFruitSalad : public Recipe
{
public:
	DragonFruitSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class MermaidScalesSalad : public Recipe
{
public:
	MermaidScalesSalad(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class WaterSoup : public Recipe
{
public:
	WaterSoup(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class AntSoup : public Recipe
{
public:
	AntSoup(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};

class StrongSoup : public Recipe
{
public:
	StrongSoup(RecipeName name, int TotalNum);
	void Load() override;
	void Draw() override;
private:

};
