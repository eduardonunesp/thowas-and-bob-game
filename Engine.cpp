#include "Engine.hpp"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	window.create(sf::VideoMode(resolution.x, resolution.y),
								"Thomas was late",
								sf::Style::Resize);

	// Initialize the full screen view
	main_view.setSize(resolution);
	hud_view.reset(
			sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Inititialize the split-screen Views
	left_view.setViewport(
			sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	right_view.setViewport(
			sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	bg_left_view.setViewport(
			sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	bg_right_view.setViewport(
			sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	// Can this graphics card use shaders?
	if (!sf::Shader::isAvailable())
	{
		// Time to get a new PC
		window.close();
	}

	background_texture = TextureHolder::get_texture(
			"graphics/background.png");

	// Associate the sprite with the texture
	backgroud_sprite.setTexture(background_texture);

	texture_tiles = TextureHolder::get_texture("graphics/tiles_sheet.png");
}

void Engine::run()
{
	// Timing
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		// Update the total game time
		game_time_total += dt;
		// Make a decimal fraction from the delta time
		float dt_seconds = dt.asSeconds();

		input();
		update(dt_seconds);
		draw();
	}
}
