#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"
#include <math.h>

void ParticleSystem::init(int num_particles)
{
	vertices.setPrimitiveType(sf::Points);
	vertices.resize(num_particles);

	// Create the particles

	for (int i = 0; i < num_particles; i++)
	{
		srand(time(0) + i);
		float angle = (rand() % 360) * 3.14f / 180.f;
		float speed = (rand() % 600) + 600.f;

		sf::Vector2f direction;

		direction = sf::Vector2f(cos(angle) * speed,
														 sin(angle) * speed);

		particles.push_back(Particle(direction));
	}
}

void ParticleSystem::update(float dt)
{
	duration -= dt;
	std::vector<Particle>::iterator i;
	int current_vertex = 0;

	for (i = particles.begin(); i != particles.end(); i++)
	{
		// Move the particle
		(*i).update(dt);

		// Update the vertex array
		vertices[current_vertex].position = (*i).get_position();

		// Move to the next vertex
		current_vertex++;
	}

	if (duration < 0)
	{
		is_running = false;
	}
}

void ParticleSystem::emit_particles(sf::Vector2f startPosition)
{
	is_running = true;
	duration = 2;

	std::vector<Particle>::iterator i;
	int current_vertex = 0;

	for (i = particles.begin(); i != particles.end(); i++)
	{
		vertices[current_vertex].color = sf::Color::Yellow;
		(*i).set_position(startPosition);

		current_vertex++;
	}
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(vertices, states);
}

bool ParticleSystem::running()
{
	return is_running;
}
