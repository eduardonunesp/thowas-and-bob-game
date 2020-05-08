#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dt_seconds)
{
	if (new_level_required)
	{
		thomas.spawn(sf::Vector2f(0, 0), GRAVITY);
		bob.spawn(sf::Vector2f(100, 0), GRAVITY);

		time_remaining = 10;
		new_level_required = false;
	}

	if (playing)
	{
		thomas.update(dt_seconds);
		bob.update(dt_seconds);

		time_remaining -= dt_seconds;
		if (time_remaining <= 0)
		{
			new_level_required = true;
		}
	}

	if (splitscreen)
	{
		left_view.setCenter(thomas.get_center());
		right_view.setCenter(bob.get_center());
	}
	else
	{
		if (character_1)
		{
			main_view.setCenter(thomas.get_center());
		}
		else
		{
			main_view.setCenter(bob.get_center());
		}
	}
}