#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "TitleState.h"
#include "SettingsState.h"
#include "LevelSelectState.h"
#include "MouseManager.h"
#include "WindowManager.h"
#include "Nonogram.h"
#include "Level.h"
#include "LevelManager.h"

int main()
{
	// TEST //

	bool tab[25] = {
		true, false, true, false, true,
		false, false, false, false, false,
		true, true, true, true, true,
		true, false, true, true, true,
		true, false, true, false, true
	};

	
	for (int i = 0; i < 8; i++)
	{
		Nonogram* nono =new Nonogram(5, 5, tab);
		LevelManager::getInstance().addLevel(new Level("boneSketch.png", "Well... It's a bone, Good job,\nI Guess.", nono, false));
	}

	LevelManager::getInstance().getLevel(0)->setBeaten(true);

	//////////

	sf::RenderWindow window(sf::VideoMode(800, 600), "Picr-Os");
	WindowManager::getInstance().initialize(&window);

	MouseManager::getInstance().setWindow(&window);
	WindowManager::getInstance().updateDisplayArea(window.getSize());
	StateManager stateManager;
	TitleState* titleState = new TitleState();
	SettingsState* settingsState = new SettingsState();
	LevelSelectState* levelSelectState = new LevelSelectState();
	stateManager.addState(titleState);
	stateManager.addState(settingsState);
	stateManager.addState(levelSelectState);
	stateManager.setCurrentStateId(titleState->getId());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || WindowManager::getInstance().getRequestExit())
			{
				window.close();
			}
			if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
				WindowManager::getInstance().updateDisplayArea(window.getSize());
			}
		}

		MouseManager::getInstance().update();
		stateManager.update();

		window.clear();
		
		stateManager.draw(&window);

		window.display();
	}
	
	return 0;
}