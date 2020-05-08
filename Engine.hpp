
#ifndef __ENGINE_HPP
#define __ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "TextureHolder.hpp"
#include "Thomas.hpp"
#include "Bob.hpp"
#include "LevelManager.hpp"
#include "SoundManager.hpp"
#include "HUD.hpp"
#include "ParticleSystem.hpp"

class Engine
{
private:
	TextureHolder th;
	ParticleSystem particle_system;
	Thomas thomas;
	Bob bob;
	LevelManager level_manager;
	SoundManager sound_manager;
	Hud hud;

	int frames_since_last_hud_update = 0;
	int target_fps_hud_update = 500;

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

	sf::Shader ripple_shader;

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
	void populate_emitters(
		std::vector <sf::Vector2f>& sound_emitters, 
		int** array_level
	);

	std::vector <sf::Vector2f> fire_emitters;

public:
	Engine();

	void run();
};

#endif
