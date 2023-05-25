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
    Ingredient(Math::vec2 pos);
    void Draw(const std::vector<std::vector<CS230::Texture*>>& texture);
    void SlotDraw(Math::vec2 pos, const std::vector<std::vector<CS230::Texture*>>& texture);
    virtual void SetScale(Math::vec2 raito) = 0; // 재료가 그려지는 곳 마다 이게 업데이트 되어야함.

    void Cut() { --cutNum; }
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

protected:
    IngredientName name = IngredientName::Lemon;
    Math::vec2 position;
    int cutNum = 0;
    bool boiled = false;
    bool mouseClick = false;
    KitchenPosition place = KitchenPosition::COUNTER1;
    double scale = 1;
};

class Lemon : public Ingredient
{
public:
    Lemon(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;

private:

};

class Lettuce : public Ingredient
{
public:
    Lettuce(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};

class Ant : public Ingredient
{
public:
    Ant(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};

class Leaf : public Ingredient
{
public:
    Leaf(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};

class Salt : public Ingredient
{
public:
    Salt(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};

class DragonFruit : public Ingredient
{
public:
    DragonFruit(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};

class MermaidScales : public Ingredient
{
public:
    MermaidScales(Math::vec2 pos);
    void SetScale(Math::vec2 raito) override;
private:


};
