#include "stdafx.h"
#include "..\..\include\Particles\VectorDistribution.h"


VectorDistribution::VectorDistribution()
{
}


VectorDistribution::~VectorDistribution()
{
}

void VectorDistribution::SetDistribution(sf::Vector2f low, sf::Vector2f high)
{
	std::uniform_real_distribution<float> hDist(low.x, high.x);
	std::uniform_real_distribution<float> vDist(low.y, high.y);
	hDistribution = hDist;
	vDistribution = vDist;
}

sf::Vector2f VectorDistribution::GetVector()
{
	return sf::Vector2f(hDistribution(generator), vDistribution(generator));
}
