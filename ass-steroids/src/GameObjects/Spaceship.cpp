#include "stdafx.h"
#include "..\..\include\GameObjects\Spaceship.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "Render\RenderMath.h"
#define RAD_TO_DEG 180/M_PI
#define DEG_TO_RAD M_PI/180

Spaceship::Spaceship()
{
	sf::Texture* spriteTexture = new sf::Texture(); //Create a pointer to the texture so it is allocated on the heap.
	//Stack allocated textures get destroyed at end of function, meaning the sprite can't reference them


	bool loaded = spriteTexture->loadFromFile("sprites/spaceship.png");
	mSprite.setTexture(*spriteTexture);

	//Move the sprite so it is offset
	sf::Vector2u textureSize = spriteTexture->getSize();
	sf::Vector2f textureSizeFloat(textureSize.x, textureSize.y);
	//mSprite.move(textureSizeFloat * -.5f);	
	mSprite.setOrigin(textureSizeFloat * .5f);



	//Initiate particles
	tPart = std::make_unique<ParticleEmitter>();
	
	tPart->initialLocationDistribution.SetDistribution(sf::Vector2f(-5, 0), sf::Vector2f(5, 0));
	tPart->initialVelocityDistribution.SetDistribution(sf::Vector2f(-50, 150), sf::Vector2f(50, 500));
	tPart->initialLifetimeDistribution.SetDistribution(.1f,.25f);
	tPart->initialSizeDistribution.SetDistribution(5, 10);
	sf::Color low(0, 100, 100, 100);
	sf::Color high(0, 100, 255, 200);
	tPart->initialColorDistribution.SetColorDistribution(low, high);
	tPart->CreateParticles(1000);
	lastPosition = getPosition();
	lastAngle = getRotation();
	tPart->move(sf::Vector2f(0, 30));
	tPart->SetVisibility(true);
}


Spaceship::~Spaceship()
{
}

void Spaceship::Draw(sf::RenderTarget& target, sf::RenderStates states, float alpha)
{
	//Create interpolated transform from last transform to current transform
	sf::Transform tt = RenderMath::InterpolateTransforms(lastPosition, getPosition(), lastAngle, getRotation(), getScale(),getScale(), alpha);

	states.transform.combine(tt);
	target.draw(*tPart, states); 
	target.draw(mSprite, states);	
	lastAngle = getRotation();
	lastPosition = getPosition();

}

void Spaceship::Update(float delta)
{
	int rotSpeed = 100;
	//Rotate
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rotate(delta * -rotSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rotate(delta * rotSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		ApplyForwardForce();
		tPart->SetActive(true);
	}
	else
	{
		tPart->SetActive(false);
	}
	ApplyVelocity(delta);
	tPart->Update(delta);
	
}

void Spaceship::ApplyDrag(float delta)
{
	//Move velocity toward 0 
}

void Spaceship::ApplyForwardForce()
{
	float speed = .1f;
	double move_x = speed * cos((getRotation() -90) * DEG_TO_RAD);
	double move_y = speed * sin((getRotation()-90 ) * DEG_TO_RAD);
	sf::Vector2f temp(move_x, move_y);
	velocity += temp;
	
}

void Spaceship::ApplyVelocity(float delta)
{
	move(velocity);
}
