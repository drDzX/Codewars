#pragma once


#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <math.h>   
#include <set>
#include <thread>
#include <locale.h>

namespace DzX
{

	class BlockSeq
	{
	public:
		BlockSeq() {};
		long long addition(int n, int expon);
		int FindLastDigit(long long InVal, long long InPos, long long& Remain, long long& SmallestDigitNo, long long& OnlyLastDigitNumbers, long long& lowerDigitSubs);
		long long BlockSeq_solve(long long n);
	};
}