#include "Thomas.hpp"
#include "TextureHolder.hpp"
#include <SFML/Window.hpp>

Thomas::Thomas()
{
	// Associate a texture with the sprite
	sprite = sf::Sprite(TextureHolder::get_texture("graphics/thomas.png"));
	jump_duration = 0.45f;
}

// A virtual function
bool Thomas::handle_input()
{
	just_jumped = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		left_pressed = true;
	}
	else
	{
		left_pressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		right_pressed = true;
	}
	else
	{
		right_pressed = false;
	}

	return just_jumped;
}