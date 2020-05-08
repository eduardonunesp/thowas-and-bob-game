#include "Engine.hpp"

void Engine::populate_emitters(
		std::vector<sf::Vector2f> &sound_emitters, int **array_level)
{
	// Make sure the vector is empty
	sound_emitters.empty();

	// Keep track of the previous emitter
	// so we don't make too many
	sf::FloatRect previousEmitter;

	// Search for fire in the level
	for (int x = 0; x < (int)level_manager.get_level_size().x; x++)
	{
		for (int y = 0; y < (int)level_manager.get_level_size().y; y++)
		{
			if (array_level[y][x] == 2) // fire is present
			{
				// Skip over any fire tiles too
				// near a previous emitter
				if (!sf::FloatRect(x * TILE_SIZE,
													 y * TILE_SIZE,
													 TILE_SIZE,
													 TILE_SIZE)
								 .intersects(previousEmitter))
				{
					// Add the coordiantes of this water block
					sound_emitters.push_back(
							sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					// Make a rectangle 6 blocks x 6 blocks,
					// so we don't make any more emitters
					// too close to this one
					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}

	return;
}
