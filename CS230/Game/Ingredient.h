/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Ingredient.h
Project:    GAM150
Author:     Yeaseul Lim
Created:    March 10, 2023
Updated:    June 8, 2023
*/
#pragma once
#include "IngredientName.h"
#include "..\Engine\vec2.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#include "KitchenPosition.h"
#include <vector>

class Ingredient
{
public:
    Ingredient(Math::vec2 pos, Math::vec2 size);
    void Draw(const std::vector<std::vector<CS230::Texture*>>& texture);
    void SlotDraw(Math::vec2 pos, Math::vec2 size, const std::vector<std::vector<CS230::Texture*>>& texture);

    void Cut();
    int GetCutNum() const { return cutNum; }
    void Boil() { boiled = true; }
    bool GetBoiled() const { return boiled; }
    void ChangeMouseClick(bool ForT) { mouseClick = ForT; }
    bool IsMouseOn(Math::vec2 mousePos, const std::vector<std::vector<CS230::Texture*>>& texture);
    void ChangePos(Math::vec2 pos) { position = pos; }
    Math::vec2 GetPos() const { return position; }
    IngredientName GetName() const { return name; }
    void ChangePalce(KitchenPosition where) { place = where; }
    KitchenPosition GetPlace() const { return place; }
    void SetWet() { wet = true; }
    bool GetWet() { return wet; }

    void Scoop();

protected:
    IngredientName name = IngredientName::Lemon;
    Math::vec2 position;
    Math::vec2 size;
    int cutNum = 0;
    bool boiled = false;
    bool mouseClick = false;
    KitchenPosition place = KitchenPosition::COUNTER1;
    double scale = 1;
    bool wet = false;
};

class Lemon : public Ingredient
{
public:
    Lemon(Math::vec2 pos, Math::vec2 size);

private:

};

class Lettuce : public Ingredient
{
public:
    Lettuce(Math::vec2 pos, Math::vec2 size);
private:


};

class Ant : public Ingredient
{
public:
    Ant(Math::vec2 pos, Math::vec2 size);
private:


};

class Leaf : public Ingredient
{
public:
    Leaf(Math::vec2 pos, Math::vec2 size);
private:


};

class Salt : public Ingredient
{
public:
    Salt(Math::vec2 pos, Math::vec2 size);
private:


};

class DragonFruit : public Ingredient
{
public:
    DragonFruit(Math::vec2 pos, Math::vec2 size);
private:

};

class MermaidScales : public Ingredient
{
public:
    MermaidScales(Math::vec2 pos, Math::vec2 size);
private:


};
