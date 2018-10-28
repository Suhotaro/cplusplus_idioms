#include "stdafx.h"

class Game
{
public:
	static Game createSinglePlayerGame() { return Game(0); } // named constructor
	static Game createMultiPlayerGame() { return Game(1); }  // named constructor
protected:
	Game(int game_type) {}
};

void named_constructor()
{
	Game g1 = Game::createSinglePlayerGame(); // Using named constructor
	//Game g2 = Game(1); // error: multiplayer game; without named constructor (does not compile)
}