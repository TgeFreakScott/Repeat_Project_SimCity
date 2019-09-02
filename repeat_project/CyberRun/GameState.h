#ifndef GAME_STATE
#define GAME_STATE

#include "game.h"

class GameState
{
public:

	Game* game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;
};

#endif /* GAME_STATE */