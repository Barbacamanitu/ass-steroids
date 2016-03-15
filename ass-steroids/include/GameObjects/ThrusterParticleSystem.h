#pragma once
#include <SFML/Graphics.hpp>
class ThrusterParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ThrusterParticleSystem(unsigned int count) :
		m_particles(count),
		m_vertices(sf::Points, count),
		m_lifetime(3000),
		m_emitter(0, 0)
	{
	}

	void setEmitter(sf::Vector2f position)
	{
		m_emitter = position;
	}

	void update(float delta);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	struct Particle
	{
		sf::Vector2f velocity;
		float lifetime;
	};

	void resetParticle(std::size_t index);

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	float m_lifetime;
	sf::Vector2f m_emitter;
};