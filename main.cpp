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
#include "GameState.h"

int main()
{
	srand(time(NULL));
	// TEST //
	bool tabShovel[25] = {
		false, true, true, true, false,
		false, true, true, true, false,
		false, false, true, false, false,
		false, false, true, false, false,
		false, false, true, false, false
	};

	Nonogram* nonoShovel = new Nonogram(5, 5, tabShovel);
	LevelManager::getInstance().addLevel(new Level("shovelSketch.png", "Your own shovel, your should\nbe a little more carefull with\nyour tools.", nonoShovel, false));

	bool tabRock[25] = {
		false, false, false, false, false,
		false, true, true, false, false,
		true, true, true, true, false,
		true, true, true, true, true,
		false, true, true, true, false
	};

	Nonogram* nonoRock = new Nonogram(5, 5, tabRock);
	LevelManager::getInstance().addLevel(new Level("rockSketch.png", "This is just a rock, you could\ndo better.", nonoRock, false));

	bool tabBone[25] = {
		false, false, false, false, false,
		true, false, false, false, true,
		false, true, true, true, false,
		true, false, false, false, true,
		false, false, false, false, false
	};

	Nonogram* nonoBone = new Nonogram(5, 5, tabBone);
	LevelManager::getInstance().addLevel(new Level("boneSketch.png", "Well... It's a bone, Good job,\nI Guess.", nonoBone, false));

	//////////

	sf::RenderWindow window(sf::VideoMode(800, 600), "Picr-Os");
	WindowManager::getInstance().initialize(&window);
	window.setMouseCursorVisible(false);

	MouseManager::getInstance().setWindow(&window);
	WindowManager::getInstance().updateDisplayArea(window.getSize(), sf::Vector2i(0,0));
	StateManager stateManager;
	TitleState* titleState = new TitleState();
	SettingsState* settingsState = new SettingsState();
	LevelSelectState* levelSelectState = new LevelSelectState();
	GameState* gameState = new GameState();
	stateManager.addState(titleState);
	stateManager.addState(settingsState);
	stateManager.addState(levelSelectState);
	stateManager.addState(gameState);
	stateManager.setCurrentStateId(titleState->getId());

	TextureManager::getInstance().addTexture("cursor.png");
	sf::RectangleShape cursor = sf::RectangleShape(sf::Vector2f(32,32));
	cursor.setTexture(TextureManager::getInstance().getTexture("cursor.png"));
	cursor.setTextureRect(sf::IntRect(0, 0, 32, 32));

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
				WindowManager::getInstance().updateDisplayArea(window.getSize(), sf::Vector2i(0,0));
			}
		}

		MouseManager::getInstance().update();
		WindowManager::getInstance().update();
		stateManager.update();
		cursor.setPosition(sf::Vector2f(MouseManager::getInstance().getPosition()));

		window.clear();
		
		stateManager.draw(&window);
		window.draw(cursor);

		window.display();
	}
	
	return 0;
}