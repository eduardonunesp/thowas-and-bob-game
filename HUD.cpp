#include "HUD.hpp"

Hud::Hud()
{
	sf::Vector2u resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	// Load the font
	font.loadFromFile("fonts/Roboto-Light.ttf");

	// Paused
	start_text.setFont(font);
	start_text.setCharacterSize(100);
	start_text.setFillColor(sf::Color::White);
	start_text.setString("Press Enter when ready!");

	// Position the text
	sf::FloatRect text_rect = start_text.getLocalBounds();

	start_text.setOrigin(
		text_rect.left +
		text_rect.width / 2.0f,
		text_rect.top +
		text_rect.height / 2.0f
	);

	start_text.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

	// Time
	time_text.setFont(font);
	time_text.setCharacterSize(75);
	time_text.setFillColor(sf::Color::White);
	time_text.setPosition(resolution.x - 150, 0);
	time_text.setString("------");

	// Level
	level_text.setFont(font);
	level_text.setCharacterSize(75);
	level_text.setFillColor(sf::Color::White);
	level_text.setPosition(25, 0);
	level_text.setString("1");
}

sf::Text Hud::get_message()
{
	return start_text;
}

sf::Text Hud::get_level()
{
	return level_text;
}

sf::Text Hud::get_time()
{
	return time_text;
}

void Hud::set_level(sf::String text)
{
	level_text.setString(text);
}

void Hud::set_time(sf::String text)
{
	time_text.setString(text);
}
