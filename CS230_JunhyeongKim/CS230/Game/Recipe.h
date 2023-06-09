/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Recipe.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 10, 2023
Upeated:    June 2, 2023
*/
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
	virtual void Draw();
	int CheckComplete(std::vector<Ingredient*>& plating);
	void Unload();
	int GetTotalNum() { return totalNum; }
	Math::vec2 GetRecipeTexturePos() { return texturePos; }
	Math::ivec2 GetRecipeTextureSize() { return texture->GetSize(); }

protected:
	//variables
	//Recipe Page
	CS230::Texture* texture;
	Math::vec2 texturePos{ 280.0, 110.0 };
	Math::vec2 textureSize{ 830.0, 600.0 };

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
private:
};

class SaltSalad : public Recipe
{
public:
	SaltSalad();
	void Load() override;
private:

};

class LeafSalad : public Recipe
{
public:
	LeafSalad();
	void Load() override;
private:

};

class AntSalad : public Recipe
{
public:
	AntSalad();
	void Load() override;
private:

};

class DragonFruitSalad : public Recipe
{
public:
	DragonFruitSalad();
	void Load() override;
private:

};

class MermaidScalesSalad : public Recipe
{
public:
	MermaidScalesSalad();
	void Load() override;
private:

};

class WaterSoup : public Recipe
{
public:
	WaterSoup();
	void Load() override;
private:

};

class AntSoup : public Recipe
{
public:
	AntSoup();
	void Load() override;
private:

};

class StrongSoup : public Recipe
{
public:
	StrongSoup();
	void Load() override;
private:

};
