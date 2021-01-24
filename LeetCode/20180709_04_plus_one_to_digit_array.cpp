/*
Given a number represented as an array of digits, plus one to the number.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
class Solution
{
public:
	std::vector<int> plusOne(std::vector<int> &digits)
	{
		if (digits.empty())
			return{};

		int carry = 1; //初始carry为1，就是加1
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			int curDigit = digits[i] + carry;
			carry = 0;
			if (curDigit >= 10)
			{
				curDigit -= 10;
				carry = 1;
			}
			digits[i] = curDigit;
		}

		if (carry == 1)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main()
{
	Solution s;
	std::vector<int> arr = { 1,0 };
	auto res = s.plusOne(arr);

	return 0;
}