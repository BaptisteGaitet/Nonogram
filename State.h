#ifndef STATE_H
#define STATE_H

#include <string>
#include <SFML\Graphics.hpp>

class State
{
private:
	std::string id;
	std::string nextStateId;
public:
	State(std::string _id);

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	std::string getNextStateId();
	void setNextStateId(std::string _nextStateId);
	void resetNextStateId();

	~State();
};

#endif