#include "MyRandom.h"

std::vector<int>* MyRandom::GenerateRandomNumbers(int quantity, int downBound, int upperBound) {
	std::random_device rd{};
	std::mt19937_64	generator{ rd() };
	if (downBound > upperBound)
	{
		int swap = downBound;
		downBound = upperBound;
		upperBound = swap;
	}
	std::uniform_int_distribution<int> distribution(downBound, upperBound);
	std::vector<int>* retVector = new std::vector<int>{};

	for (int i = 0; i < quantity; i++)
	{		//int random_number = distribution(generator);
		(*retVector).push_back(distribution(generator));
	}
	return retVector;
}

int MyRandom::GenerateRandomNumber(int downBound, int UpperBound)
{
	return 0;
}
