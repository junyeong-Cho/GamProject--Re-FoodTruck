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
    Ingredient(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    virtual void Load() = 0;
    virtual void Update(double dt) = 0;
    virtual void Draw() = 0;

    void Cut() { --cutNum; }
    int GetCutNum() { return cutNum; }
    virtual void Boil() { boiled = true; }
    virtual bool GetBoiled() { return boiled; }
    void ChangeMouseClick(bool ForT) { mouseClick = ForT; }
    bool IsMouseOn(Math::vec2 mousePos);
    void ChangePos(Math::vec2 pos) { position = pos; }
    Math::vec2 GetPos() { return position; }
    IngredientName GetName() { return name; }
    void ChangePalce(KitchenPosition where) { place = where; }
    KitchenPosition GetPlace() { return place; }

protected:
    IngredientName name;
    Math::vec2 position;
    int cutNum = 0;
    bool boiled = false;
    bool mouseClick = false;
    std::vector< CS230::Texture*> texture;
    KitchenPosition place;
};

class Lemon : public Ingredient
{
public:
    Lemon(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;

private:

};

class Lettuce : public Ingredient
{
public:
    Lettuce(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Ant : public Ingredient
{
public:
    Ant(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Leaf : public Ingredient
{
public:
    Leaf(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Salt : public Ingredient
{
public:
    Salt(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class DragonFruit : public Ingredient
{
public:
    DragonFruit(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class MermaidScales : public Ingredient
{
public:
    MermaidScales(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Water : public Ingredient
{
public:
    Water(IngredientName id, Math::vec2 pos, int cuttingNumber, KitchenPosition place);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:
};
