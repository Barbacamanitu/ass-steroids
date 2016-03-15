#pragma once
#include <SFML/Graphics.hpp>
#include "ThrusterParticleSystem.h"
#include <memory>
#include "Particles/ParticleEmitter.h"
class Spaceship : public sf::Transformable
{
public:
	Spaceship();
	~Spaceship();
	void Draw(sf::RenderTarget& target, sf::RenderStates states, float alpha);
	void Update(float delta);
private:
	sf::Sprite mSprite;
	sf::Vector2f velocity;
	void ApplyDrag(float delta);
	void ApplyVelocity(float delta);
	void ApplyForwardForce();
	std::unique_ptr<ParticleEmitter> tPart;
	sf::Vector2f lastPosition;
	float lastAngle;
};

