#include "Recipe.h"

Recipe::Recipe(RecipeName name, int TotalNum) : recippeName(name), totalNum(TotalNum)
{
	lemon = new Lemon(IngredientName::Lemon, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledLemon = new Lemon(IngredientName::Lemon, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledLemon->Boil();

	lettuce = new Lettuce(IngredientName::Lettuce, { 0,0 }, 0, KitchenPosition::COUNTER1);

	ant = new Ant(IngredientName::Ant, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledAnt = new Ant(IngredientName::Ant, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledAnt->Boil();

	leaf = new Leaf(IngredientName::Leaf, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledLeaf = new Leaf(IngredientName::Leaf, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledLeaf->Boil();

	salt = new Salt(IngredientName::Salt, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledSalt = new Salt(IngredientName::Salt, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledSalt->Boil();

	dragonFruit = new DragonFruit(IngredientName::DragonFruit, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledDragonFruit = new DragonFruit(IngredientName::DragonFruit, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledDragonFruit->Boil();

	mermaidScales = new MermaidScales(IngredientName::MermaidScales, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledMermaidScales = new MermaidScales(IngredientName::MermaidScales, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledMermaidScales->Boil();

	boiledwater = new Water(IngredientName::Water, { 0,0 }, 0, KitchenPosition::COUNTER1);
	boiledwater->Boil();
}

int Recipe::CheckComplete(std::vector<Ingredient*>& plating)
{
	int checkTotal = 0;
	score = 0;
	size_t size = (plating.size() > recipe.size()) ? recipe.size() : plating.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (plating[i]->GetName() == recipe[i]->GetName())
		{
			score += 100 / (totalNum-1);
			if (plating[i]->GetCutNum() == recipe[i]->GetCutNum())
			{
				score += 100 / totalNum;
				checkTotal += 1;
			}
			if (plating[i]->GetBoiled() == recipe[i]->GetBoiled())
			{
				score += 100 / totalNum;
				checkTotal += 1;
			}
		}
	}
	if (totalNum == checkTotal)
	{
		score = 100;
	}
	return score;
}
void Recipe::Update()
{
	texturePos = Math::vec2((double)Engine::GetWindow().GetSize().x / 4,
		(double)Engine::GetWindow().GetSize().y / 7);
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

	delete boiledwater;
}



LemonSalad::LemonSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2
	recipe.push_back(lemon); //3
}
void LemonSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_LemonSalad.png");
}
void LemonSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




SaltSalad::SaltSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(salt); //1
}
void SaltSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_SaltSalad.png");
}
void SaltSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



LeafSalad::LeafSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(leaf); //1

	recipe.push_back(salt); //1
}
void LeafSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_LeafSalad.png");
}
void LeafSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



AntSalad::AntSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
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
}
void AntSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSalad.png");
}
void AntSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}


DragonFruitSalad::DragonFruitSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(dragonFruit); //1
	recipe.push_back(dragonFruit); //2
	recipe.push_back(dragonFruit); //3
	recipe.push_back(dragonFruit); //4
}
void DragonFruitSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_DragonFruitSalad.png");
}
void DragonFruitSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



MermaidScalesSalad::MermaidScalesSalad(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(lettuce); //1
	recipe.push_back(lettuce); //2
	recipe.push_back(lettuce); //3

	recipe.push_back(mermaidScales); //1
	recipe.push_back(mermaidScales); //2
	recipe.push_back(mermaidScales); //3
	recipe.push_back(mermaidScales); //4
	recipe.push_back(mermaidScales); //5

}
void MermaidScalesSalad::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_MermaidScalesSalad.png");
}
void MermaidScalesSalad::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




WaterSoup::WaterSoup(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(boiledwater); //1
	recipe.push_back(boiledwater); //2
	recipe.push_back(boiledwater); //3

	recipe.push_back(boiledSalt); //1
}
void WaterSoup::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_WaterSoup.png");
}
void WaterSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}




AntSoup::AntSoup(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(boiledwater); //1
	recipe.push_back(boiledwater); //2
	recipe.push_back(boiledwater); //3

	recipe.push_back(boiledAnt); //1
	recipe.push_back(boiledAnt); //2
	recipe.push_back(boiledAnt); //3

	recipe.push_back(boiledSalt); //1
}
void AntSoup::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_AntSoup.png");
}
void AntSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}



StrongSoup::StrongSoup(RecipeName name, int TotalNum) : Recipe(name, TotalNum)
{
	recipe.push_back(boiledwater); //1
	recipe.push_back(boiledwater); //2
	recipe.push_back(boiledwater); //3

	recipe.push_back(lemon); //1
	recipe.push_back(lemon); //2

	recipe.push_back(boiledLeaf); //1

	recipe.push_back(boiledDragonFruit); //1

	recipe.push_back(boiledMermaidScales); //1

	recipe.push_back(boiledSalt); //1
	recipe.push_back(boiledSalt); //2

	recipe.push_back(ant); //1
	recipe.push_back(ant); //2
}
void StrongSoup::Load()
{
	texture = Engine::GetTextureManager().Load("Assets/Recipe_StrongSoup.png");
}
void StrongSoup::Draw()
{
	Math::TransformationMatrix matrix = Math::TranslationMatrix(texturePos) * Math::RotationMatrix(0) * Math::ScaleMatrix(0.2);
	texture->Draw(matrix);
}

