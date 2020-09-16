#include <iostream>
#include "BlockSequance.h"
#include <algorithm>
#include <string>


using namespace std;

void IsEqual(int A, int B)
{
	if (A == B)
	{
		std::cout << to_string(A) + "==" + to_string(B) + " = true" << endl;
	}
	else
	{
		std::cout << to_string(A) + "!=" + to_string(B) + " = false" << endl;
	}
}
int main()
{
		DzX::BlockSeq* BS = new DzX::BlockSeq();

		IsEqual(BS->BlockSeq_solve(1), 1);
		IsEqual(BS->BlockSeq_solve(2), 1);
		IsEqual(BS->BlockSeq_solve(3), 2);
		IsEqual(BS->BlockSeq_solve(100), 1);
		IsEqual(BS->BlockSeq_solve(2100), 2);
		IsEqual(BS->BlockSeq_solve(31000), 2);
		IsEqual(BS->BlockSeq_solve(55), 1);
		IsEqual(BS->BlockSeq_solve(123456), 6);
		IsEqual(BS->BlockSeq_solve(123456789), 3);
		IsEqual(BS->BlockSeq_solve(999999999999999999), 4);
		IsEqual(BS->BlockSeq_solve(1000000000000000000), 1);
		IsEqual(BS->BlockSeq_solve(999999999999999993), 7);

		std::cout << BS->BlockSeq_solve(999999999999999993) << std::endl;

	std::cin.get();
}
