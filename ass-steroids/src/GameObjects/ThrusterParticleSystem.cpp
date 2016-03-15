#include "stdafx.h"
#include "..\..\include\GameObjects\ThrusterParticleSystem.h"



void ThrusterParticleSystem::update(float delta)
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		// update the particle lifetime
		Particle& p = m_particles[i];
		p.lifetime -= delta * 1000;

		// if the particle is dead, respawn it
		if (p.lifetime <= 0)
			resetParticle(i);

		// update the position of the corresponding vertex
		m_vertices[i].position += p.velocity * delta;

		// update the alpha (transparency) of the particle according to its lifetime
		float ratio = p.lifetime / m_lifetime;
		m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
	}
}

void ThrusterParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// our particles don't use a texture
	states.texture = NULL;

	// draw the vertex array
	target.draw(m_vertices, states);
}

void ThrusterParticleSystem::resetParticle(std::size_t index)
{
	// give a random velocity and lifetime to the particle
	float angle = ((std::rand() % 30)-195) * 3.14f / 180.f;
	float speed = (std::rand() % 50) + 50.f;
	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].lifetime = (std::rand() % 2000) + 1000;

	// reset the position of the corresponding vertex
	m_vertices[index].position = m_emitter;
	m_vertices[index].color.r = static_cast<sf::Uint8>(0);
	m_vertices[index].color.b = static_cast<sf::Uint8>((std::rand() % 55) + 200);
	m_vertices[index].color.g = static_cast<sf::Uint8>((std::rand() % 55) + 200);
}
