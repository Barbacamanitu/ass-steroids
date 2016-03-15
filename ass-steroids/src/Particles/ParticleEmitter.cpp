#include "stdafx.h"
#include "..\..\include\Particles\ParticleEmitter.h"




ParticleEmitter::~ParticleEmitter()
{
}



void ParticleEmitter::CreateParticles(size_t particleCount)
{


	spriteTexture = new sf::Texture();
	bool loaded = spriteTexture->loadFromFile("sprites/particle_white.png");
	vertices.setPrimitiveType(sf::PrimitiveType::Quads);
	for (int i = 0; i < particleCount; i++)
	{
		vertices.append(sf::Vertex(sf::Vector2f(0,0), sf::Color::White, sf::Vector2f(0, 0)));
		vertices.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::White, sf::Vector2f(16, 0)));
		vertices.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::White, sf::Vector2f(16, 16)));
		vertices.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::White, sf::Vector2f(0, 16)));

		//Create particle structs to keep up with the data for each particle
		particles.push_back(Particle());

		//Reset all particles so they have the correct lifetime and starting position
		ResetParticle(i);
	}

	
}

void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!isVisible)
		return;
	states.transform = states.transform.combine(getTransform());
	//states.blendMode = sf::
	states.texture = spriteTexture;
	states.blendMode = sf::BlendAdd;
	target.draw(vertices, states);
}

void ParticleEmitter::Update(float delta)
{

	

	for (int x = 0; x < particles.size(); x++)
	{
		//Check for whether current particle should be reset
		particles[x].timeLeft -= delta;
		if (particles[x].timeLeft <= 0)
		{
			ResetParticle(x);
		}

		//Apply velocity
		MoveParticle(x, particles[x].velocity * delta);
	}
}

void ParticleEmitter::ResetParticle(size_t i)
{
	//Move particle to correct starting location based on the distribution.

	//Only allow a particle to be created if isActive is true.
	//If not, set color to invisible
	particles[i].position = initialLocationDistribution.GetVector();
	particles[i].timeLeft = initialLifetimeDistribution.GetNumber();
	particles[i].velocity = initialVelocityDistribution.GetVector();
	particles[i].color = initialColorDistribution.GetColor();
	particles[i].particleSize = initialSizeDistribution.GetNumber();

	if (!isActive)
	{
		particles[i].color.a = 0;
	}
	UpdateVertices(i);


	


}


ParticleEmitter::ParticleEmitter()
{
	isVisible = false;
	isActive = false;
}

void ParticleEmitter::SetParticleLocation(size_t index, sf::Vector2f position)
{
	particles[index].position = position;
	UpdateVertices(index);
}

void ParticleEmitter::MoveParticle(size_t index, sf::Vector2f movement)
{
	particles[index].position += movement;
	UpdateVertices(index);
}

void ParticleEmitter::UpdateVertices(size_t index)
{
	vertices[(index * 4) + 0].position = particles[index].position + sf::Vector2f(particles[index].particleSize / -2.0f, particles[index].particleSize/-2.0f);
	vertices[(index * 4) + 1].position = particles[index].position + sf::Vector2f(particles[index].particleSize / 2.0f, particles[index].particleSize / -2.0f);
	vertices[(index * 4) + 2].position = particles[index].position + sf::Vector2f(particles[index].particleSize / 2.0f, particles[index].particleSize / 2.0f);
	vertices[(index * 4) + 3].position = particles[index].position + sf::Vector2f(particles[index].particleSize / -2.0f, particles[index].particleSize / 2.0f);

	vertices[(index * 4) + 0].color = particles[index].color;
	vertices[(index * 4) + 1].color = particles[index].color;
	vertices[(index * 4) + 2].color = particles[index].color;
	vertices[(index * 4) + 3].color = particles[index].color;
}

void ParticleEmitter::SetVisibility(bool visible)
{
	isVisible = visible;
}

void ParticleEmitter::SetActive(bool active)
{
	isActive = active;
}
