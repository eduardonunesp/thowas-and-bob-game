
#ifndef __PARTICLE_HPP
#define __PARTICLE_HPP

#include <SFML/System/Vector2.hpp>

class Particle
{
private:
	sf::Vector2f position;
	sf::Vector2f velocity;

public:
	Particle(sf::Vector2f direction);
	void update(float dt);
	void set_position(sf::Vector2f position);
	sf::Vector2f get_position();
};


#endif // __PARTICLE_HPP
