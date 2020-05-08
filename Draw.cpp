#include "Engine.hpp"

void Engine::draw()
{
	window.clear(sf::Color::White);

	if (!splitscreen)
	{
		window.setView(bg_main_view);
		window.draw(backgroud_sprite);
		window.setView(main_view);
	}
	else
	{
		window.setView(bg_left_view);
		window.draw(backgroud_sprite);
		window.setView(left_view);

		window.setView(bg_right_view);
		window.draw(backgroud_sprite);
		window.setView(right_view);
	}

	window.setView(hud_view);
	window.display();
}