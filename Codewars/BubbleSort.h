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

	class BubbleSort
	{
	public:
		BubbleSort() {};
		std::vector<int> solution(std::vector<int> nums);
		void swap(int* xp, int* yp);

	};
}