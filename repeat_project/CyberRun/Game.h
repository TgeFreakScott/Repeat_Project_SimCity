#ifndef GAME
#define GAME

#include <stack>
#include <SFML/Graphics.hpp>
#include <map>
#include<string>

#include "ResourceManager.h"
#include "Tile.h"
#include "GUI.h"

class GameState;

class Game
{
private:

	void loadTextures();
	void loadTiles();
	void loadStylesheets();
	void loadFonts();

public:

	const static int tileSize = 8;

	std::stack<GameState*> states;

	sf::RenderWindow window;

	ResourceManager resourceMgr;

	sf::Sprite background;

	std::map < std::string, Tile> TileWorld;
	std::map<std::string, GuiStyle> stylesheets;
	std::map<std::string, sf::Font> fonts;

	//insert an element at the top of the stack.
	void pushState(GameState* state);

	//remove an element from the top of the stack
	void popState();
	void changeState(GameState* state);

	//It returns the Object at the top of the Stack.
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

#endif /* GAME */