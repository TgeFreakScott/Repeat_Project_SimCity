#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "ResourceManager.h"

void ResourceManager::loadTexture(const std::string& name, const std::string& filename)
{
	/* Load Texture */
	sf::Texture tex;

	tex.loadFromFile(filename);

	/*Add to texture List*/
	this->textures[name] = tex;

	return;
}

sf::Texture& ResourceManager::getRef(const std::string& texture)
{
	return this->textures.at(texture);
}