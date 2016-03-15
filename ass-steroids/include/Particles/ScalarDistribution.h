#pragma once
#include <random>
class ScalarDistribution
{
public:
	ScalarDistribution();
	~ScalarDistribution();
	void SetDistribution(float low, float high);
	float GetNumber();
private:
	std::uniform_real_distribution<float> sDistribution;
	std::default_random_engine generator;
};

