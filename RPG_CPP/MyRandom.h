#pragma once
#include <vector>
#include <algorithm>
#include <random>

class MyRandom
{
public:	static std::vector<int>* GenerateRandomNumbers(int quantity, int downBound, int upperBound);
public: static int GenerateRandomNumber(int downBound, int UpperBound);
};

