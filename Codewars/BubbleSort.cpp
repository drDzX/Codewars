#include "BubbleSort.h"


namespace DzX
{

	void BubbleSort::swap(int* xp, int* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	std::vector<int> BubbleSort::solution(std::vector<int> nums)
	{
		int i, j;
		std::vector<int> localVector = nums;
		int n = localVector.size();
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (localVector[j] > localVector[j + 1])
				{
					swap(&localVector[j], &localVector[j + 1]);
				}

			}
		}
		return localVector;
	}

}