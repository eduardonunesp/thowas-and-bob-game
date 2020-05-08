
#ifndef __HUD_HPP
#define __HUD_HPP

#include <SFML/Graphics.hpp>

class Hud
{
private:
	sf::Font font;
	sf::Text start_text;
	sf::Text time_text;
	sf::Text level_text;

public:
	Hud();
	sf::Text get_message();
	sf::Text get_level();
	sf::Text get_time();

	void set_level(sf::String text);
	void set_time(sf::String text);
};

#endif // __HUD_HPP
