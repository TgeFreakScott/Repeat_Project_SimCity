#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#pragma comment(lib,"thor-d.lib")
#pragma comment(lib,"sfeMovie-d.lib")
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#pragma comment(lib,"thor.lib")
#pragma comment(lib,"sfeMovie.lib")
#endif 

#pragma comment(lib,"libyaml-cppmdd") 

#include "Game.h"
#include "StateStart.h"

int main()
{
	Game game;

	game.pushState(new StateStart(&game));
	game.gameLoop();

	return 0;
}