
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include "LevelManager.hpp"


int** LevelManager::nextLevel(sf::VertexArray& vertex_array_level)
{
	level_size.x = 0;
	level_size.y = 0;

	// Get the next level
	current_level++;
	if (current_level > NUM_LEVELS)
	{
		current_level = 1;
		timer_modifier -= .1f;
	}

	// Load the appropriate level from a text file
	std::string level_to_load;
	switch (current_level)
	{
	
	case 1:
		level_to_load = "levels/level1.txt";
		start_position.x = 100;
		start_position.y = 100;
		base_time_limit = 30.0f;
		break;

	case 2:
		level_to_load = "levels/level2.txt";
		start_position.x = 100;
		start_position.y = 3600;
		base_time_limit = 100.0f;
		break;

	case 3:
		level_to_load = "levels/level3.txt";
		start_position.x = 1250;
		start_position.y = 0;
		base_time_limit = 30.0f;
		break;

	case 4:
		level_to_load = "levels/level4.txt";
		start_position.x = 50;
		start_position.y = 200;
		base_time_limit = 50.0f;
		break;


	}

	std::ifstream input_file(level_to_load);
	std::string s;

	// Count the number of rows in the file
	while (getline(input_file, s))
	{
		++level_size.y;
	}

	// Store the length of the rows
	level_size.x = s.length();

	// Go back to the start of the file
	input_file.clear();
	input_file.seekg(0, std::ios::beg);

	// Prepare the 2d array to hold the int values from the file
	int** array_level = new int*[level_size.y];
	for (int i = 0; i < level_size.y; ++i)
	{
		// Add a new array into each array element
		array_level[i] = new int[level_size.x];
	}

	// Loop through the file and store all the values in the 2d array
	std::string row;
	int y = 0;
	while (input_file >> row)
	{
		for (int x = 0; x < row.length(); x++) {

			const char val = row[x];
			array_level[y][x] = atoi(&val);
		}

		y++;
	}

	// close the file
	input_file.close();

	// What type of primitive are we using?
	vertex_array_level.setPrimitiveType(sf::Quads);

	// Set the size of the vertex array
	vertex_array_level.resize(level_size.x * level_size.y * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < level_size.x; x++)
	{
		for (int y = 0; y < level_size.y; y++)
		{
			// Position each vertex in the current quad
			vertex_array_level[currentVertex + 0].position = 
				sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);

			vertex_array_level[currentVertex + 1].position = 
				sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);

			vertex_array_level[currentVertex + 2].position = 
				sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

			vertex_array_level[currentVertex + 3].position = 
				sf::Vector2f((x * TILE_SIZE), (y * TILE_SIZE) + TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = array_level[y][x] * TILE_SIZE;

			vertex_array_level[currentVertex + 0].texCoords = 
				sf::Vector2f(0, 0 + verticalOffset);

			vertex_array_level[currentVertex + 1].texCoords = 
				sf::Vector2f(TILE_SIZE, 0 + verticalOffset);

			vertex_array_level[currentVertex + 2].texCoords = 
				sf::Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);

			vertex_array_level[currentVertex + 3].texCoords = 
				sf::Vector2f(0, TILE_SIZE + verticalOffset);

			// Position ready for the next four vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	return array_level;
}

sf::Vector2i LevelManager::get_level_size()
{
	return level_size;
}

int LevelManager::get_current_level()
{
	return current_level;
}

float LevelManager::get_time_limit()
{
	return base_time_limit * timer_modifier;

}
sf::Vector2f LevelManager::get_start_position()
{
	return start_position;
}
