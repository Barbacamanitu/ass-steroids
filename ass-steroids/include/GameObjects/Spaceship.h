#pragma once
#include <SFML/Graphics.hpp>
class Spaceship : public sf::Transformable
{
public:
	Spaceship();
	~Spaceship();
	void Draw(sf::RenderTarget& target, sf::RenderStates states);
private:
	sf::Sprite mSprite;
};

