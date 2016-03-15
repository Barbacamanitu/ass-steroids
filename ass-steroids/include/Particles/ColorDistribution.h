#pragma once
#include <SFML\Graphics.hpp>


class ColorDistribution
{



public:

	ColorDistribution(){};

	void SetColorDistribution(sf::Color low,sf::Color high)
	{
		std::uniform_int_distribution<> rDistribution(low.r,high.r);
		std::uniform_int_distribution<> gDistribution(low.g, high.g);
		std::uniform_int_distribution<> bDistribution(low.b, high.b);
		std::uniform_int_distribution<> aDistribution(low.a, high.a);
		redDistribution = rDistribution;
		greenDistribution = gDistribution;
		blueDistribution = bDistribution;
		alphaDistribution = aDistribution;
	}
	sf::Color GetColor()
	{
		return sf::Color(redDistribution(generator), greenDistribution(generator), blueDistribution(generator), alphaDistribution(generator));
	}

private:
	std::uniform_int_distribution<> redDistribution;
	std::uniform_int_distribution<> greenDistribution;
	std::uniform_int_distribution<> blueDistribution;
	std::uniform_int_distribution<> alphaDistribution;
	std::default_random_engine generator;
};