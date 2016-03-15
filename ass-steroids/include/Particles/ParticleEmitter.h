#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "VectorDistribution.h"
#include "ScalarDistribution.h"
#include "ColorDistribution.h"



class ParticleEmitter : public sf::Transformable, public sf::Drawable
{
public:
	struct Particle
	{
		sf::Vector2f velocity;
		sf::Vector2f position;
		sf::Color color;
		float timeLeft;
		size_t particleSize;
	};
	ParticleEmitter();
	~ParticleEmitter();


	void CreateParticles(size_t particleCount);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float delta);
	void SetVisibility(bool visible);
	void SetActive(bool active);

	VectorDistribution initialLocationDistribution;
	VectorDistribution initialVelocityDistribution;
	ScalarDistribution initialLifetimeDistribution;
	ColorDistribution  initialColorDistribution;
	ScalarDistribution initialSizeDistribution;
private:
	sf::Texture* spriteTexture;
	sf::VertexArray vertices;
	std::vector<Particle> particles;
	void SetParticleLocation(size_t index, sf::Vector2f position);
	void MoveParticle(size_t index, sf::Vector2f movement);
	void UpdateVertices(size_t index);
	void ResetParticle(size_t index);
	bool isVisible;
	bool isActive;


	

};

