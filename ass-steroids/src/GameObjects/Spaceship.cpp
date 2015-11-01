#include "stdafx.h"
#include "..\..\include\GameObjects\Spaceship.h"


Spaceship::Spaceship()
{
	sf::Texture* spriteTexture = new sf::Texture(); //Create a pointer to the texture so it is allocated on the heap.
	//Stack allocated textures get destroyed at end of function, meaning the sprite can't reference them


	bool loaded = spriteTexture->loadFromFile("sprites/spaceship.png");
	mSprite.setTexture(*spriteTexture);

	//Move the sprite so it is offset
	sf::Vector2u textureSize = spriteTexture->getSize();
	sf::Vector2f textureSizeFloat(textureSize.x, textureSize.y);
	mSprite.move(textureSizeFloat * -.5f);
}


Spaceship::~Spaceship()
{
}

void Spaceship::Draw(sf::RenderTarget& target, sf::RenderStates states)
{
	states.transform.combine(getTransform());
	target.draw(mSprite, states);
}
