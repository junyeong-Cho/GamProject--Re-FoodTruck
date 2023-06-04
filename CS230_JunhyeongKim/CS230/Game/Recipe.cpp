#include "Recipe.h"
#include <iostream>

Recipe::Recipe()
{
	lemon = new Lemon({ 0,0 });
	boiledLemon = new Lemon({ 0,0 });
	boiledLemon->Boil();

	lettuce = new Lettuce({ 0,0 });

	ant = new Ant({ 0,0 });
	boiledAnt = new Ant({ 0,0 });
	boiledAnt->Boil();

	leaf = new Leaf({ 0,0 });
	boiledLeaf = new Leaf({ 0,0 });
	boiledLeaf->Boil();

	salt = new Salt({ 0,0 });
	boiledSalt = new Salt({ 0,0 });
	boiledSalt->Boil();

	dragonFruit = new DragonFruit({ 0,0 });
	boiledDragonFruit = new DragonFruit({ 0,0 });
	boiledDragonFruit->Boil();

	mermaidScales = new MermaidScales({ 0,0 });
	boiledMermaidScales = new MermaidScales({ 0,0 });
	boiledMermaidScales->Boil();

	double recipePagePosX = static_cast<double>(Engine::GetWindow().GetSize().x / 5);
	double recipePagePosY = static_cast<double>(Engine::GetWindow().GetSize().y / 7);

	texturePos = Math::vec2(recipePagePosX, recipePagePosY);
}

int Recipe::CheckComplete(std::vector<Ingredient*>& plating)
{
	double totalScore = 0;

	double perfectOneScore = 100.0 / totalNum;

	double putSomething = perfectOneScore * 0.1;
	double sameIngredient = perfectOneScore * 0.3;
	double sameBoil = perfectOneScore * 0.3;
	double sameCut = perfectOneScore * 0.3;

	for (size_t i = 0; i < plating.size(); ++i)
	{
		double differCutScore = sameCut / (recipe[i]->GetCutNum() - 1);
		if (recipe[i]->GetCutNum() == 1)
		{
			differCutScore = 0;
		}
		double tempSameCut = sameCut;
		
		//재료가 들어오기만 하면 일단 점수+
		totalScore += putSomething;

		//같은 재료이면 점수+
		if (plating[i]->GetName() == recipe[i]->GetName())
		{
			totalScore += sameIngredient;

			tempSameCut -= differCutScore * (plating[i]->GetCutNum() - 1);
			totalScore += tempSameCut;

			//같은 boiled이면 점수+
			if (plating[i]->GetBoiled() == recipe[i]->GetBoiled())
			{
				totalScore += sameBoil;
			}
		}
	}
	if (totalScore > 99)
	{
		totalScore = 100;
	}
	return (int)totalScore;
}

void Recipe::Update()
{
	/*texturePos = Math::vec2((double)Engine::GetWindow().GetSize().x / 4,
		(double)Engine::GetWindow().GetSize().y / 7);*/

	//empty
}

void Recipe::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(1.0);
	texture->Draw(matrix);
}

void Recipe::Unload()
{
	delete lemon;
	delete boiledLemon;

	delete lettuce;

	delete ant;
	delete boiledAnt;

	delete leaf;
	delete boiledLeaf;

	delete salt;
	delete boiledSalt;

	delete dragonFruit;
	delete boiledDragonFruit;

	delete mermaidScales;
	delete boiledMermaidScales;

	recipe.clear();
}



LemonSalad::LemonSalad() : Recipe()
{
	recippeName = RecipeName::LemonSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2
	recipe.push_back(lemon); //3

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_LemonSalad.png");
}
void LemonSalad::Load()
{}




SaltSalad::SaltSalad() : Recipe()
{
	recippeName = RecipeName::SaltSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(salt); //1

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_SaltSalad.png");
}
void SaltSalad::Load()
{}



LeafSalad::LeafSalad() : Recipe()
{
	recippeName = RecipeName::LeafSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(leaf); //1

	recipe.push_back(salt); //1

	totalNum = recipe.size();
	
	texture = Engine::GetTextureManager().Load("Assets/Recipe_LeafSalad.png");
}
void LeafSalad::Load()
{}





AntSalad::AntSalad() : Recipe()
{
	recippeName = RecipeName::AntSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(ant); //1
	recipe.push_back(ant); //2
	recipe.push_back(ant); //3
	recipe.push_back(ant); //4
	recipe.push_back(ant); //5
	recipe.push_back(ant); //6
	recipe.push_back(ant); //7

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSalad.png");
}
void AntSalad::Load()
{}




DragonFruitSalad::DragonFruitSalad() : Recipe()
{
	recippeName = RecipeName::DragonFruitSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(dragonFruit); //1
	recipe.push_back(dragonFruit); //2
	recipe.push_back(dragonFruit); //3
	recipe.push_back(dragonFruit); //4

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_DragonFruitSalad.png");
}
void DragonFruitSalad::Load()
{}




MermaidScalesSalad::MermaidScalesSalad() : Recipe()
{
	recippeName = RecipeName::MermaidScalesSalad;
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(mermaidScales); //1
	recipe.push_back(mermaidScales); //2
	recipe.push_back(mermaidScales); //3
	recipe.push_back(mermaidScales); //4
	recipe.push_back(mermaidScales); //5

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_MermaidScalesSalad.png");
}
void MermaidScalesSalad::Load()
{}





WaterSoup::WaterSoup() : Recipe()
{
	recippeName = RecipeName::WaterSoup;

	recipe.push_back(boiledSalt); //1
	recipe.push_back(boiledSalt); //2
	recipe.push_back(boiledSalt); //3


	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_WaterSoup.png");
}
void WaterSoup::Load()
{}





AntSoup::AntSoup() : Recipe()
{
	recippeName = RecipeName::AntSoup;

	recipe.push_back(boiledAnt); //1
	recipe.push_back(boiledAnt); //2
	recipe.push_back(boiledAnt); //3

	recipe.push_back(boiledSalt); //1

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSoup.png");
}
void AntSoup::Load()
{}




StrongSoup::StrongSoup() : Recipe()
{
	recippeName = RecipeName::StrongSoup;

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2

	recipe.push_back(boiledLeaf); //1

	recipe.push_back(boiledDragonFruit); //1

	recipe.push_back(boiledMermaidScales); //1

	recipe.push_back(boiledSalt); //1
	recipe.push_back(boiledSalt); //2

	recipe.push_back(ant); //1
	recipe.push_back(ant); //2

	totalNum = recipe.size();

	texture = Engine::GetTextureManager().Load("Assets/Recipe_StrongSoup.png");
}
void StrongSoup::Load()
{}

