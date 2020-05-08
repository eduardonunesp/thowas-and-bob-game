#include "Engine.hpp"

void Engine::input()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				playing = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				character_1 = !character_1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				splitscreen = !splitscreen;
			}
		}
	}
}