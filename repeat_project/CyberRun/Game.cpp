
#include <stack>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"
#include "ResourceManager.h"
#include "Animation.h"
#include "Tile.h"

void Game::loadTiles()
{
	Animation staticAnim(0, 0, 1.0f);

	this->TileWorld["grass"] =
		Tile(this->tileSize, 1, resourceMgr.getRef("grass"),
			{ staticAnim },
			TileType::GRASS, 50, 0, 1);

	this->TileWorld["forest"] =
		Tile(this->tileSize, 1, resourceMgr.getRef("forest"),
			{ staticAnim },
			TileType::FOREST, 100, 0, 1);

	this->TileWorld["water"] =
		Tile(this->tileSize, 1, resourceMgr.getRef("water"),
			{ Animation(0, 3, 0.5f),
			Animation(0, 3, 0.5f),
			Animation(0, 3, 0.5f) },
			TileType::WATER, 0, 0, 1);

	this->TileWorld["residential"] =
		Tile(this->tileSize, 2, resourceMgr.getRef("residential"),
			{ staticAnim, staticAnim, staticAnim,
			staticAnim, staticAnim, staticAnim },
			TileType::RESIDENTIAL, 300, 50, 6);

	this->TileWorld["commercial"] =
		Tile(this->tileSize, 2, resourceMgr.getRef("commercial"),
			{ staticAnim, staticAnim, staticAnim, staticAnim },
			TileType::COMMERCIAL, 300, 50, 4);

	this->TileWorld["industrial"] =
		Tile(this->tileSize, 2, resourceMgr.getRef("industrial"),
			{ staticAnim, staticAnim, staticAnim, staticAnim },
			TileType::INDUSTRIAL, 300, 50, 4);

	this->TileWorld["road"] =
		Tile(this->tileSize, 1, resourceMgr.getRef("road"),
			{ staticAnim, staticAnim, staticAnim,staticAnim,
			staticAnim, staticAnim,staticAnim, staticAnim,
			staticAnim,staticAnim, staticAnim },
			TileType::ROAD, 100, 0, 1);

	return;
}

void Game::loadTextures()
{
	resourceMgr.loadTexture("grass",		"ASSETS/IMAGES/grass.png");
	resourceMgr.loadTexture("forest",		"ASSETS/IMAGES/forest.png");
	resourceMgr.loadTexture("water",		"ASSETS/IMAGES/water.png");
	resourceMgr.loadTexture("residential",	"ASSETS/IMAGES/residential.png");
	resourceMgr.loadTexture("commercial",	"ASSETS/IMAGES/commercial.png");
	resourceMgr.loadTexture("industrial",	"ASSETS/IMAGES/industrial.png");
	resourceMgr.loadTexture("road",			"ASSETS/IMAGES/road.png");
	resourceMgr.loadTexture("background",	"ASSETS/IMAGES/background.png");
}

void Game::loadFonts()
{
	sf::Font font;
	font.loadFromFile("ASSETS/FONTS/Ordinary.ttf");
	this->fonts["main_font"] = font;

	return;
}

void Game::loadStylesheets()
{
	this->stylesheets["button"] = GuiStyle(&this->fonts.at("main_font"), 1,
		sf::Color(0xc6, 0xc6, 0xc6), 
		sf::Color(0x94, 0x94, 0x94),
		sf::Color(0x00, 0x00, 0x00),
		sf::Color(0x61, 0x61, 0x61),
		sf::Color(0x94, 0x94, 0x94), 
		sf::Color(0x00, 0x00, 0x00));

	this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
		sf::Color(0x00, 0x00, 0x00, 0x00),
		sf::Color(0x00, 0x00, 0x00), 
		sf::Color(0xff, 0xff, 0xff),
		sf::Color(0x00, 0x00, 0x00, 0x00),
		sf::Color(0x00, 0x00, 0x00), 
		sf::Color(0xff, 0x00, 0x00));

	return;
}

void Game::pushState(GameState* state)
{
	this->states.push(state);

	return;
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
	{
		popState();
	}
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty())
	{
		return nullptr;
	}
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr)
		{
			continue;
		}

		peekState()->handleInput();
		peekState()->update(dt);

		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);

		this->window.display();
	}
}

Game::Game()
{
	this->loadTextures();
	this->loadTiles();
	this->loadFonts();
	this->loadStylesheets();

	this->window.create(sf::VideoMode(800, 600), "DEFINITELY NOT SIM CITY");
	this->window.setFramerateLimit(60);

	this->background.setTexture(this->resourceMgr.getRef("background"));
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}