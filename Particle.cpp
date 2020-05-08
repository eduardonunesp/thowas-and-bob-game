#include "Particle.hpp"

Particle::Particle(sf::Vector2f direction)
{
	velocity.x = direction.x;
	velocity.y = direction.y;
}

void Particle::update(float dtAsSeconds)
{
	// Move the particle
	position += velocity * dtAsSeconds;
}

void Particle::set_position(sf::Vector2f position)
{
	position = position;
}

sf::Vector2f Particle::get_position()
{
	return position;
}
