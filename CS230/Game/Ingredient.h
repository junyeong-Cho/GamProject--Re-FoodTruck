#pragma once
#include "IngredientName.h"
#include "KitchenPos.h"
#include "..\Engine\vec2.h"
#include "..\Engine\Sprite.h"

class Ingredient
{
public:
    Ingredient(IngredientName id, Math::vec2 pos, int cuttingNumber);
    virtual void Update(double dt) = 0;
    virtual void Draw() = 0;

    void Cut() { --cutNum; }
    int GetCutNum() { return cutNum; }
    void Boil() { boiled = true; }
    bool GetBoiled() { return boiled; }
    void ChangeMouseClick(bool ForT) { mouseClick = ForT; }
    bool IsMouseOn() { return mouseClick; }
    void ChangePos(Math::vec2 pos) { position = pos; }
    Math::vec2 GetPos() { return position; }
    CS230::Sprite sprite;

private:
    IngredientName name;
    Math::vec2 position;
    int cutNum;
    bool boiled = false;
    bool mouseClick = false;

};

class Remon : Ingredient
{
public:
    Remon(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;

private:

};

class Legguce : Ingredient
{
public:
    Legguce(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

class Ant : Ingredient
{
public:
    Ant(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

class Leaf : Ingredient
{
public:
    Leaf(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

class Salt : Ingredient
{
public:
    Salt(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

class DragonFruit : Ingredient
{
public:
    DragonFruit(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

class MermaidScales : Ingredient
{
public:
    MermaidScales(Ingredient id, Math::vec2 pos, int cuttingNumber);
    void Update(double dt)override;
    void Draw()override;
private:


};

