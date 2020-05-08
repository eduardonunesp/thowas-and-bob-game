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
			sound_manager.play_reach_goal();
		} else {
			detect_collisions(bob);
		}

		time_remaining -= dt_seconds;
		if (time_remaining <= 0)
		{
			new_level_required = true;
		}
	}

		// Check if a fire sound needs to be played
	std::vector<sf::Vector2f>::iterator it;

	// Iterate through the vector of Vector2f objects
	for (it = fire_emitters.begin(); it != fire_emitters.end(); it++)
	{
		// Where is this emitter?
		// Store the location in pos
		float posX = (*it).x;
		float posY = (*it).y;

		// is the emiter near the player?
		// Make a 500 pixel rectangle around the emitter
		sf::FloatRect localRect(posX - 250, posY - 250, 500, 500);

		// Is the player inside localRect?
		if (thomas.get_position().intersects(localRect))
		{
			// Play the sound and pass in the location as well
			sound_manager.play_fire(sf::Vector2f(posX, posY), thomas.get_center());
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

	// Time to update the HUD?
	// Increment the number of frames since the last HUD calculation
	frames_since_last_hud_update++;

	// Update the HUD every target_fps_hud_update frames
	if (frames_since_last_hud_update > target_fps_hud_update)
	{
		// Update game HUD text
		std::stringstream ss_time;
		std::stringstream ss_level;

		// Update the time text
		ss_time << (int)time_remaining;
		hud.set_time(ss_time.str());

		// Update the level text
		ss_level << "Level:" << level_manager.get_current_level();
		hud.set_level(ss_level.str());

		frames_since_last_hud_update = 0;
	}
}
