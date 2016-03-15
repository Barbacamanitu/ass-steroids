#include "stdafx.h"
#include "..\..\include\Particles\ScalarDistribution.h"


ScalarDistribution::ScalarDistribution()
{
}


ScalarDistribution::~ScalarDistribution()
{
}

void ScalarDistribution::SetDistribution(float low, float high)
{
	std::uniform_real_distribution<float> sTemp(low, high);
	sDistribution = sTemp;
}

float ScalarDistribution::GetNumber()
{
	return sDistribution(generator);
}
