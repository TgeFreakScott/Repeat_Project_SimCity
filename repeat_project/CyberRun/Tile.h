#ifndef TILE
#define TILE

#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"

enum class TileType
{
	EMPTY,
	GRASS,
	FOREST,
	WATER,
	RESIDENTIAL,
	COMMERCIAL,
	INDUSTRIAL,
	ROAD
};

std::string tileToString(TileType type);

class Tile
{
public:

	AnimationHandler animHandler;

	sf::Sprite sprite;

	TileType tileType;
	
	/*Same Tile different style*/
	int tileVariation;

	/*RegionID of tiles will pair tiles of the same region*/
	int regions[1];

	/*price of tiles*/
	int cost;

	/*Population of map*/
	double population;

	/*Maximum Population allowed*/
	int maxPopulation;

	/*Max number of Building*/
	int maxLevel;

	/*Output of the poplation*/
	float production;

	/*Storage for products*/
	float storeProduce;

	/* Constructor */
	Tile()
	{ 


	}

	Tile(
		const int tileSize,
		const int height,
		sf::Texture& texture,
		const::std::vector<Animation>& Animations,
		const TileType tileType,
		const int cost,
		const int mapPopulation,
		const int maxLevel)
	{
		this->tileType = tileType;
		this->tileVariation = 0;
		this->regions[0] = 0;
		this->cost = cost;
		this->population = 0;
		this->maxPopulation = maxPopulation;
		this->maxLevel = maxLevel;
		this->production = 0;
		this->storeProduce = 0;

		this->sprite.setOrigin(sf::Vector2f(0.0f, tileSize * (height - 1)));
		this->sprite.setTexture(texture);
		this->animHandler.frameSize = sf::IntRect(0, 0, tileSize * 2, tileSize * height);

		for (auto animation : Animations)
		{
			this->animHandler.addAnim(animation);
		}

		this->animHandler.update(0.0f);

	}

	void draw(sf::RenderWindow& window, float dt);

	void update();

	/*Return String of Cost*/
	std::string getCost()
	{
		return std::to_string(this->cost);
	}
};

#endif /* TILE */