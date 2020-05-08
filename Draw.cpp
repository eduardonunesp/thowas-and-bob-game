#include "Engine.hpp"

void Engine::draw()
{
	window.clear(sf::Color::White);

	if (!splitscreen)
	{
		window.setView(bg_main_view);
		window.draw(backgroud_sprite);
		window.setView(main_view);

		window.draw(level, &texture_tiles);

		window.draw(thomas.get_sprite());
		window.draw(bob.get_sprite());
	}
	else
	{
		window.setView(bg_left_view);
		window.draw(backgroud_sprite);
		window.setView(left_view);

		window.draw(level, &texture_tiles);

		window.draw(bob.get_sprite());
		window.draw(thomas.get_sprite());

		window.setView(bg_right_view);
		window.draw(backgroud_sprite);
		window.setView(right_view);

		window.draw(level, &texture_tiles);

		window.draw(bob.get_sprite());
		window.draw(thomas.get_sprite());
	}

	window.setView(hud_view);
	window.display();
}
