#ifndef STATE_EDITOR
#define STATE_EDITOR

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Map.h"
#include "GUI.h"
#include "City.h"

enum class ActionState
{ 
	NONE, 
	PANNING,
	SELECTING
};

class StateEditor : public GameState
{
private:

	ActionState actionState;

	sf::View gameView;
	sf::View guiView;

	City city;

	sf::Vector2i panningAnchor;
	float zoomLevel;

	sf::Vector2i selectionStart;
	sf::Vector2i selectionEnd;

	Tile* currentTile;
	std::map<std::string, Gui> guiSystem;

public:

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	StateEditor(Game* game);
};

#endif /* STATE_EDITOR */