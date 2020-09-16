#include "BlockSequance.h"

namespace DzX
{

	using namespace std;
#pragma region 4Ku
	//
	//https://www.codewars.com/kata/5e1ab1b9fe268c0033680e5f/train/cpp


	/*Addition to digit sizes for numbers with 2 or more digits
	example:
	if we have 1 2 3 4 5 6 7 8 9 10 - that is 10 numbers but 11 characters.
	This function adds difference to character count.

	@n - current number
	@expon - size of current n in digits as char


	(n-ex((n-ex)+1))/2

	*/
	long long BlockSeq::addition(int n, int expon)
	{
		//Local size for additional characters
		long long localSumm = 0;
		/*Loop every smaller digits size
		Example: if N=101 this will loop 1x for 2 digit numbers and 1x for 3 digit numbers,
		there are no adition for 1 digit numbers because they take same characters as they have digits.
		*/
		for (int ln = 1; ln < expon; ln++)
		{
			/*Local string to collect increase for exponential number
			Example: for 2 digit number Exponent is 9, 3 digit exp is 99, 4 digits exp is 999, and so on...
			*/
			string exstr = "";
			/*Loop to make exponent number same as number of digits require
			Two digits number starts first with 9, then 3 digits with 99,etc.
			*/
			for (int lx = 0; lx < ln; lx++)
			{
				//Add 9 for each digit size
				exstr += "9";
			}
			//Convert string to long long
			long long ex = std::stoi(exstr);
			/*Calculate how many additional characters there are for number current digit of number N
			First itteration of loop starts with 2 digit numbers, and this will add to summ additional chars for 2 digit numbers,
			then 2nd itteration for 3 digit numbers(if there are any) and so on...
			*/
			localSumm += ((n - ex) * ((n - ex) + 1)) / 2;
		}
		//Return complete sum of additional digit characters.
		return localSumm;
	}


	/*
	For 10^18 N largest number in subseqence is 9 digit number. This function calculate if position is iniside which portion of digits and return useful parameters.
	@InVal - size in characters of last full sequance.
	@InPos - size in characters from 1st number of last full sequance to asked position (n)
	@Remain - size of remaining characters from position to sequance end.
	@SmallestDigitNo - smallest number before current digit size started ( ex: for 3 digit numbers = 99)
	@OnlyLastDigitNumbers - amount of numbers for last digit size in last full sequance( ex: for number 101 = 2, because 101-99 = 2, for 1234-999=235...)
	@lowerDigitSubs - amount of characters contained in all digits for all numbers with lower digit count then current size(ex: for 3 digit number =189, because there are 9x 1digit and 180 2digit characters)
	*/
	int BlockSeq::FindLastDigit(long long InVal, long long InPos, long long& Remain, long long& SmallestDigitNo, long long& OnlyLastDigitNumbers, long long& lowerDigitSubs)
	{
		//If position value is lower then the largest number of this digit
		if (InPos <= 9)
		{
			//Set remaining numbers by calculating difference between full sequance size and size of position in sequance.
			Remain = InVal - InPos;
			//Smallest digit for this digit size
			SmallestDigitNo = 0;
			//Amount of characters contained in all digits for all numbers with lower digit count then current size
			lowerDigitSubs = 0;
			//amount of numbers for last digit size in last full sequance = ( Full sequance size - characters from lower digit sizes) / number of digits
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs);
			//Return number of digits
			return 1;
		}
		if (InPos <= 189)
		{

			SmallestDigitNo = 9;
			Remain = InVal - InPos;
			lowerDigitSubs = 9;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 2;
			return 2;
		}
		if (InPos <= 2889)
		{

			SmallestDigitNo = 99;
			Remain = InVal - InPos;
			lowerDigitSubs = 189;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 3;
			return 3;
		}
		if (InPos <= 38889)
		{
			SmallestDigitNo = 999;
			Remain = InVal - InPos;
			lowerDigitSubs = 2889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 4;
			return 4;
		}
		if (InPos <= 488889)
		{

			SmallestDigitNo = 9999;
			Remain = InVal - InPos;
			lowerDigitSubs = 38889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 5;
			return 5;
		}
		if (InPos <= 5888889)
		{
			SmallestDigitNo = 99999;
			Remain = InVal - InPos;
			lowerDigitSubs = 488889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 6;
			return 6;
		}
		if (InPos <= 68888889)
		{
			SmallestDigitNo = 999999;
			Remain = InVal - InPos;
			lowerDigitSubs = 5888889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 7;
			return 7;
		}
		if (InPos <= 788888889)
		{
			SmallestDigitNo = 9999999;
			Remain = InVal - InPos;
			lowerDigitSubs = 68888889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 8;
			return 8;
		}
		if (InPos <= 8888888889)
		{
			SmallestDigitNo = 99999999;
			Remain = InVal - InPos;
			lowerDigitSubs = 788888889;
			OnlyLastDigitNumbers = (InVal - lowerDigitSubs) / 9;
			return 9;
		}
		return 0;
	}

	long long BlockSeq::BlockSeq_solve(long long n)
	{
		//Local placeholder for exact number
		std::string sum = "";

		//Size of all characters after adding last sequance to the count.
		long long SizeAfterLastSequance = 0;
		//Size of all characters before adding sequance where position is.
		long long SizeBeforeLastSequance = 0;

		//Fast search increment by 100k to find last sequance aprox position before looping by 1 number
		long long temp_LastSeqSize100k = 0;
		//Closest itteration to start looping <100k numbers by +1 increment
		long long temp_closestIteration = 1;

		/*loop with increment of 100k to get aproximate position before looping with +1 increment.
		start with number 1 and calclulate all characters from 0 to i considering multidigit numbers.
		@i=1
		@while size of current array is smaller then position n
		@increase by 100k numbers
		*/
		for (long long i = 1; temp_LastSeqSize100k < n; i += 100000)
		{
			//Get size of current number in digits
			long long nsize = std::to_string(i).size();
			//Get all additional characters for current number (input: current number, size in digits)
			long long addto = addition(i, nsize);
			//Calculate all characters up to current number/itteration
			temp_LastSeqSize100k = long long((i * 0.5 + 0.5) * i) + addto;
			//Get last itteration size, when stop looping closest smaller number/itteration will remain.
			temp_closestIteration = i > 10000 ? i - 100000 : i;
		}
		/*loop with increment +1 to get accurate size of this collection.
		start with previously calculated closest itteration and calclulate all characters 0 to i considering multidigit numbers.
		@i=temp_closestIteration - start with closest itteration.
		@while size of array is smaller then position n
		@increase number by +1
		*/
		for (long long i = temp_closestIteration; SizeAfterLastSequance < n; i++)
		{
			//Get size of current number in digits
			long long nsize = std::to_string(i).size();
			//Get all additional characters for current number (input: current number, size in digits)
			long long addto = addition(i, nsize);
			//Set size of current sequance to be size of last sequnace before calculation
			SizeBeforeLastSequance = SizeAfterLastSequance;
			//Calculate size of last number(sequance)
			SizeAfterLastSequance = long long((i * 0.5 + 0.5) * i) + addto;
		}
		//Remaining numbers from position to end of last sequnace
		long long Remain = 0;
		//Amount of numbers with the largest digit size in last sequance
		long long OnlyLastDigits = 0;
		//Get size of last sequnace only
		long long SizeLastSequance = SizeAfterLastSequance - SizeBeforeLastSequance;
		//Get size from last sequnace to position
		long long SizePos = n - SizeBeforeLastSequance;
		//Smallest number before current digit size start
		long long SmallestDigitNo = 0;
		//Amount of characters for all numbers before current digit size start
		long long SubsLowerDigit = 0;
		//Get parameters above, and get in how many digits number n position is in.
		int fromDigits = FindLastDigit(SizeLastSequance, SizePos, Remain, SmallestDigitNo, OnlyLastDigits, SubsLowerDigit);

		/*Only number where position is pointing inside.
		If n=3 we have (1,1,2) so this will be number 2(because its 1 digit number)
		If n=100 this will be number 13 (because n=100 points to [1]3)
		*/
		int NoOnPosition = SmallestDigitNo + OnlyLastDigits - (Remain / fromDigits);

		/*
		((size from last sequance start to position) - (all character for numbers with lower digit count)) / (number of digits for current number)*(number of digits for current number)
		= get remaining charactrs to substract from position. this is used to pinpoint position of exact digit in last number.
		*/
		int PosDifference = (SizePos - SubsLowerDigit) % fromDigits != 0 ? ((SizePos - SubsLowerDigit) / fromDigits) * fromDigits : ((SizePos - SubsLowerDigit) / fromDigits - 1) * fromDigits;

		//Exact position inside the last number (-1 because string array starts with index 0 not 1)
		int Pos = SizePos - SubsLowerDigit - PosDifference - 1;

		//Make a string out of number that is pointed by n
		sum += std::to_string(NoOnPosition);

		//Get character from string array at position
		char ExactNo = sum[Pos];
		//Convert char to int
		int ia = ExactNo - '0';
		//Return number
		return ia;
	}

#pragma endregion 4Ku

}