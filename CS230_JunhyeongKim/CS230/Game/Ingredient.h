#pragma once
#include "IngredientName.h"
#include "KitchenPos.h"
#include "..\Engine\vec2.h"
#include "..\Engine\Texture.h"
#include "..\Engine\Engine.h"
#include <vector>

class Ingredient
{
public:
    Ingredient(IngredientName id, Math::vec2 pos, int cuttingNumber);
    virtual void Load() = 0;
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

protected:
    IngredientName name;
    Math::vec2 position;
    int cutNum = 0;
    bool boiled = false;
    bool mouseClick = false;
    std::vector< CS230::Texture*> texture;
};

class Remon : Ingredient
{
public:
    Remon(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;

private:

};

class Legguce : Ingredient
{
public:
    Legguce(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Ant : Ingredient
{
public:
    Ant(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Leaf : Ingredient
{
public:
    Leaf(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class Salt : Ingredient
{
public:
    Salt(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class DragonFruit : Ingredient
{
public:
    DragonFruit(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

class MermaidScales : Ingredient
{
public:
    MermaidScales(IngredientName id, Math::vec2 pos, int cuttingNumber);
    void Load() override;
    void Update(double dt)override;
    void Draw()override;
private:


};

