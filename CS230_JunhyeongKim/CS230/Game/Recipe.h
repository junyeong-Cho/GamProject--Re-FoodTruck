#include "RecipeName.h"
#include "Ingredient.h"
#include <vector>
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#pragma once
class Recipe
{
public:
	Recipe();
	virtual void Load() = 0;
	virtual void Draw() = 0;
	int CheckComplete(std::vector<Ingredient*>& plating);
	void Update();
	void Unload();
	int GetTotalNum() { return totalNum; }
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
	
	double score = 100;
	double totalNum = 0;
};

class LemonSalad : public Recipe
{
public:
	LemonSalad();
	void Load() override;
	void Draw() override;
private:
};

class SaltSalad : public Recipe
{
public:
	SaltSalad();
	void Load() override;
	void Draw() override;
private:

};

class LeafSalad : public Recipe
{
public:
	LeafSalad();
	void Load() override;
	void Draw() override;
private:

};

class AntSalad : public Recipe
{
public:
	AntSalad();
	void Load() override;
	void Draw() override;
private:

};

class DragonFruitSalad : public Recipe
{
public:
	DragonFruitSalad();
	void Load() override;
	void Draw() override;
private:

};

class MermaidScalesSalad : public Recipe
{
public:
	MermaidScalesSalad();
	void Load() override;
	void Draw() override;
private:

};

class WaterSoup : public Recipe
{
public:
	WaterSoup();
	void Load() override;
	void Draw() override;
private:

};

class AntSoup : public Recipe
{
public:
	AntSoup();
	void Load() override;
	void Draw() override;
private:

};

class StrongSoup : public Recipe
{
public:
	StrongSoup();
	void Load() override;
	void Draw() override;
private:

};
