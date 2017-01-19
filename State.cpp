#include "State.h"

/*
This class must be inherited to represent a single independent screen in the game.
*/

// Creates the state with a corresponding ID
State::State(std::string _id)
{
	id = _id;
	nextStateId = "";
}

// Returns the state to switch for (empty string if no switching requested)
std::string State::getNextStateId()
{
	return nextStateId;
}

// Sets nextStateId when switching to a new state is required
void State::setNextStateId(std::string _nextStateId)
{

}

// Resets nestStateId to an empty string, meaning no switching requested
void State::resetNextStateId()
{
	nextStateId = "";
}

State::~State()
{
}
