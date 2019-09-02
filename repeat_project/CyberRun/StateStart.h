#ifndef STATE_START
#define STATE_START

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "GameState.h"
#include "GUI.h"

class StateStart : public GameState
{
private:

	sf::View view;

	std::map<std::string, Gui> guiSystem;

	void loadgame();

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	StateStart(Game* game);
};

#endif /* STATE_START */