#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "TitleState.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Picr-Os");
	window.setFramerateLimit(60);

	StateManager stateManager;
	TitleState* titleState = new TitleState();
	stateManager.addState(titleState);
	stateManager.setCurrentStateId(titleState->getId());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		stateManager.update();

		window.clear();
		
		stateManager.draw(&window);

		window.display();
	}
	
	return 0;
}