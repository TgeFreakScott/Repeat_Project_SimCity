#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "Tile.h"


void Tile::draw(sf::RenderWindow& window, float dt)
{
	/*Change tile to Variation*/
	this->animHandler.changeAnim(this->tileVariation);

	/*Update Animation*/
	this->animHandler.update(dt);

	/*Update Sprite*/
	this->sprite.setTextureRect(this->animHandler.bounds);

	/*Draw Tile*/
	window.draw(this->sprite);

	return;
}

void Tile::update()
{
	/*Max Population can increase the level of a Tile*/
	if((
		this->tileType == TileType::COMMERCIAL ||
		this->tileType == TileType::INDUSTRIAL ||
		this->tileType == TileType::RESIDENTIAL) &&
		this->population == this->maxPopulation * (this->tileVariation) &&
		this->tileVariation < this->maxLevel)
	{
		if (rand() % int(1e4) < 1e2 / (this->tileVariation + 1))
		{
			++this->tileVariation;
		}

		return;
	}
}

std::string tileToString(TileType type)
{
	switch (type)
	{
		default:
		case TileType::EMPTY:           
			return "Empty";
		case TileType::GRASS:           
			return "Flat";
		case TileType::FOREST:          
			return "Forest";
		case TileType::WATER:           
			return "Water";
		case TileType::RESIDENTIAL:     
			return "Residential Zone";
		case TileType::COMMERCIAL:      
			return "Commercial Zone";
		case TileType::INDUSTRIAL:      
			return "Industrial Zone";
	}
}