#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dt_seconds)
{
	if (new_level_required)
	{
		load_level();
	}

	if (playing)
	{
		thomas.update(dt_seconds);
		bob.update(dt_seconds);

		if (detect_collisions(thomas) && detect_collisions(bob)) {
			new_level_required = true;
		} else {
			detect_collisions(bob);
		}

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
