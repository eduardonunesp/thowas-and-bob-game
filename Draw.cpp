#include "Engine.hpp"

void Engine::draw()
{
	window.clear(sf::Color::White);

	ripple_shader.setUniform("uTime", game_time_total.asSeconds());

	if (!splitscreen)
	{
		window.setView(bg_main_view);
		window.draw(backgroud_sprite, &ripple_shader);
		window.setView(main_view);

		window.draw(level, &texture_tiles);

		window.draw(thomas.get_sprite());
		window.draw(bob.get_sprite());

		if (particle_system.running()) {
			window.draw(particle_system);
		}
	}
	else
	{
		window.setView(bg_left_view);
		window.draw(backgroud_sprite, &ripple_shader);
		window.setView(left_view);

		window.draw(level, &texture_tiles);

		window.draw(bob.get_sprite());
		window.draw(thomas.get_sprite());

		if (particle_system.running()) {
			window.draw(particle_system);
		}

		window.setView(bg_right_view);
		window.draw(backgroud_sprite, &ripple_shader);
		window.setView(right_view);

		window.draw(level, &texture_tiles);

		window.draw(bob.get_sprite());
		window.draw(thomas.get_sprite());

		if (particle_system.running()) {
			window.draw(particle_system);
		}
	}

	window.setView(hud_view);
	window.draw(hud.get_level());
	window.draw(hud.get_time());

	if (!playing) {
		window.draw(hud.get_message());
	}

	window.setView(hud_view);
	window.display();
}
