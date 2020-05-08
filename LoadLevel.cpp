#include "Engine.hpp"

void Engine::load_level()
{
	playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < level_manager.get_level_size().y; ++i)
	{
		delete[] array_level[i];
	}
	delete[] array_level;

	// Load the next 2d array with the map for the level
	// And repopulate the vertex array as well
	array_level = level_manager.nextLevel(level);

	// How long is this new time limit
	time_remaining = level_manager.get_time_limit();

	// Spawn Thomas and Bob
	thomas.spawn(level_manager.get_start_position(), GRAVITY);
	bob.spawn(level_manager.get_start_position(), GRAVITY);

	// Make sure this code isn't run again
	new_level_required = false;
}
