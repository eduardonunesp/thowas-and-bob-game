
#ifndef __ENGINE_HPP
#define __ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "TextureHolder.hpp"
#include "Thomas.hpp"
#include "Bob.hpp"
#include "LevelManager.hpp"

class Engine
{
private:
	TextureHolder th;
	Thomas thomas;
	Bob bob;
	LevelManager level_manager;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	const int GRAVITY = 300;

	sf::RenderWindow window;

	sf::View main_view;
	sf::View left_view;
	sf::View right_view;

	sf::View bg_main_view;
	sf::View bg_left_view;
	sf::View bg_right_view;

	sf::View hud_view;

	sf::Sprite backgroud_sprite;
	sf::Texture background_texture;

	bool playing = false;
	bool character_1 = true;
	bool splitscreen = false;
	float time_remaining = 10;
	sf::Time game_time_total;
	bool new_level_required = true;

	sf::VertexArray level;
	int** array_level = NULL;
	sf::Texture texture_tiles;

	void input();
	void update(float dt_seconds);
	void draw();
	void load_level();
	bool detect_collisions(PlayableCharacter& character);

public:
	Engine();

	void run();
};

#endif
