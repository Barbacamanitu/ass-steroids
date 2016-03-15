#pragma once
#include "SFML/Graphics.hpp"
#include <random>
class VectorDistribution
{
public:
	VectorDistribution();
	~VectorDistribution();
	void SetDistribution(sf::Vector2f low, sf::Vector2f high);
	sf::Vector2f GetVector();
private:
	std::uniform_real_distribution<float> hDistribution;
	std::uniform_real_distribution<float> vDistribution;
	std::default_random_engine generator;
};

