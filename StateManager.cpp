#include "StateManager.h"

StateManager::StateManager()
{
	// Initialize current state to an empty string
	currentState = "";
}

void StateManager::update()
{
	// If the current state is valid
	if (hasState(currentState))
	{
		// Update it
		states.at(currentState)->update();
	}
}

void StateManager::draw(sf::RenderWindow* window)
{
	// If the current state is valid
	if (hasState(currentState))
	{
		// Draw it
		states.at(currentState)->draw(window);
	}
}

void StateManager::addState(State* _state)
{
	// Insert a new state to the map, whith its id as string key
	states.insert(std::pair<std::string, State*>(_state->getId(), _state));
}

bool StateManager::hasState(std::string _id)
{
	// Declare return value as strue;
	bool valid = true;

	// Try to access the corresponding state
	try
	{
		states.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "StateManager Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

StateManager::~StateManager()
{
}
