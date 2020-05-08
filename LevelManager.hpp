
#ifndef __LEVEL_MANAGER_HPP
#define __LEVEL_MANAGER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class LevelManager
{
private:
	sf::Vector2i level_size;
	sf::Vector2f start_position;

	float timer_modifier = 1;
	float base_time_limit = 0;
	int current_level = 0;

	const int NUM_LEVELS = 4;

public:
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float get_time_limit();

	sf::Vector2f get_start_position();

	int **nextLevel(sf::VertexArray &vertex_array_level);

	sf::Vector2i get_level_size();

	int get_current_level();
};

#endif
