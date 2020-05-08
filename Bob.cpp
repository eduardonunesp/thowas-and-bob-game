#include "Bob.hpp"
#include "TextureHolder.hpp"
#include <SFML/Window.hpp>

Bob::Bob()
{
	// Associate a texture with the sprite
	sprite = sf::Sprite(TextureHolder::get_texture(
			"graphics/bob.png"));

	jump_duration = 0.25f;
}

bool Bob::handle_input()
{
	just_jumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!is_jumping && !is_falling)
		{
			is_jumping = true;
			time_this_jump = 0;
			just_jumped = true;
		}
	}
	else
	{
		is_jumping = false;
		is_falling = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		left_pressed = true;
	}
	else
	{
		left_pressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		right_pressed = true;
	}
	else
	{
		right_pressed = false;
	}

	return just_jumped;
}