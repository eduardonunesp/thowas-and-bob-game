#include "PlayableCharacter.hpp"

void PlayableCharacter::spawn(sf::Vector2f start_position, float _gravity)
{
	// Place the player at the starting point
	position.x = start_position.x;
	position.y = start_position.y;

	// Initialize the gravity
	gravity = _gravity;

	// Move the sprite in to position
	sprite.setPosition(position);
}

void PlayableCharacter::update(float elapsed_time)
{

	if (right_pressed)
	{
		position.x += speed * elapsed_time;
	}

	if (left_pressed)
	{
		position.x -= speed * elapsed_time;
	}

	// Handle Jumping
	if (is_jumping)
	{
		// Update how long the jump has been going
		time_this_jump += elapsed_time;

		// Is the jump going upwards
		if (time_this_jump < jump_duration)
		{
			// Move up at twice gravity
			position.y -= gravity * 2 * elapsed_time;
		}
		else
		{
			is_jumping = false;
			is_falling = true;
		}
	}

	// Apply gravity
	if (is_falling)
	{
		position.y += gravity * elapsed_time;
	}

	// Update the rect for all body parts
	sf::FloatRect r = get_position();

	// Feet
	feet.left = r.left + 3;
	feet.top = r.top + r.height - 1;
	feet.width = r.width - 6;
	feet.height = 1;

	// Head
	head.left = r.left;
	head.top = r.top + (r.height * .3);
	head.width = r.width;
	head.height = 1;

	// Right
	right.left = r.left + r.width - 2;
	right.top = r.top + r.height * .35;
	right.width = 1;
	right.height = r.height * .3;

	// Left
	left.left = r.left;
	left.top = r.top + r.height * .5;
	left.width = 1;
	left.height = r.height * .3;

	// Move the sprite into position
	sprite.setPosition(position);
}

sf::FloatRect PlayableCharacter::get_position()
{
	return sprite.getGlobalBounds();
}

sf::Vector2f PlayableCharacter::get_center()
{
	return sf::Vector2f(
		position.x + sprite.getGlobalBounds().width / 2,
		position.y + sprite.getGlobalBounds().height / 2
	);
}

sf::FloatRect PlayableCharacter::get_feet()
{
	return feet;
}

sf::FloatRect PlayableCharacter::get_head()
{
	return head;
}

sf::FloatRect PlayableCharacter::get_left()
{
	return left;
}

sf::FloatRect PlayableCharacter::get_right()
{
	return right;
}

sf::Sprite PlayableCharacter::get_sprite()
{
	return sprite;
}

void PlayableCharacter::stop_falling(float _position)
{
	position.y = _position - get_position().height;
	sprite.setPosition(position);
	is_falling = false;
}

void PlayableCharacter::stop_right(float _position)
{

	position.x = _position - sprite.getGlobalBounds().width;
	sprite.setPosition(position);
}

void PlayableCharacter::stop_left(float _position)
{
	position.x = _position + sprite.getGlobalBounds().width;
	sprite.setPosition(position);
}

void PlayableCharacter::stop_jump()
{
	// Stop a jump early
	is_jumping = false;
	is_falling = true;
}
