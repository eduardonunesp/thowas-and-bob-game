#include "Engine.hpp"

bool Engine::detect_collisions(PlayableCharacter& character)
{
	bool reached_goal = false;

	// Make a rect for all his parts
	sf::FloatRect detection_zone = character.get_position();

	// Make a sf::FloatRect to test each block
	sf::FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detection_zone.left / TILE_SIZE) - 1;
	int startY = (int)(detection_zone.top / TILE_SIZE) - 1;
	int endX = (int)(detection_zone.left / TILE_SIZE) + 2;

	// Thomas is quite tall so check a few tiles vertically
	int endY = (int)(detection_zone.top / TILE_SIZE) + 3;

	// Make sure we don't test positions lower than zero
	// Or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= level_manager.get_level_size().x)
		endX = level_manager.get_level_size().x;
	if (endY >= level_manager.get_level_size().y)
		endY = level_manager.get_level_size().y;

	// Has the character fallen out of the map?
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!This can be part of level manager!!!!!!!!!!!!!!!!!!!!!!!!
	sf::FloatRect level(0, 0, level_manager.get_level_size().x * TILE_SIZE, level_manager.get_level_size().y * TILE_SIZE);
	if (!character.get_position().intersects(level))
	{
		// respawn the character
		character.spawn(level_manager.get_start_position(), GRAVITY);
	}

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has character been burnt or drowned?
			// Use head as this allows him to sink a bit
			if (array_level[y][x] == 2 || array_level[y][x] == 3)
			{
				if (character.get_head().intersects(block))
				{
					character.spawn(level_manager.get_start_position(), GRAVITY);
					// Which sound should be played?
					if (array_level[y][x] == 2)// Fire, ouch!
					{
						// Play a sound

					}
					else // Water
					{
						// Play a sound
					}
				}
			}


			// Is character colliding with a regular block
			if (array_level[y][x] == 1)
			{

				if (character.get_right().intersects(block))
				{
					character.stop_right(block.left);
				}
				else if (character.get_left().intersects(block))
				{
					character.stop_left(block.left);
				}


				if (character.get_feet().intersects(block))
				{
					character.stop_falling(block.top);
				}
				else if (character.get_head().intersects(block))
				{
					character.stop_jump();
				}
			}
			
			// More collision detection here once we have learned about particle effects

			// Has the character reached the goal?
			if (array_level[y][x] == 4)
			{
				// Character has reached the goal
				reached_goal = true;
			}

		}

	}

	// All done, return, wheteher or not a new level might be required
	return reached_goal;
}
