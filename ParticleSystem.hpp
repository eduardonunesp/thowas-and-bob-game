
#ifndef __PARTICLE_SYSTEM_HPP
#define __PARTICLE_SYSTEM_HPP

#include <SFML/Graphics.hpp>
#include "Particle.hpp"

class ParticleSystem : public sf::Drawable
{
private:
	std::vector<Particle> particles;
	sf::VertexArray vertices;
	float duration;
	bool is_running = false;

public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void init(int count);
	void emit_particles(sf::Vector2f position);
	void update(float elapsed);
	bool running();
};

#endif // __PARTICLE_SYSTEM_HPP
