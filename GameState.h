#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
class GameState :
	public State
{
public:
	GameState();

	void update();
	void draw(sf::RenderWindow* window);

	~GameState();
};

#endif