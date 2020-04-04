/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
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
	int atoi(const char *str)
	{
		if (str == nullptr)
			return 0;

		while (*str == ' ')
		{
			++str;
		}
		bool negative = false;
		if (*str == '-')
		{
			negative = true;
			++str;
		}
		if (*str == '+')
			++str;
		long long res = 0;
		while (*str != '\0')
		{
			if (*str < '0' || *str > '9')
				return negative ? -res : res; //返回合理的部分，比如--0012a42 返回-12
			res = res * 10 + (*str) - '0';
			if (isOverFlow(res, negative))
				return negative == true ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
			++str;
		}
		return negative ? (-res) : (res);
	}

	bool isOverFlow(long long res, bool neg)
	{
		if (neg)
			return -res < std::numeric_limits<int>::min();
		return res > std::numeric_limits<int>::max();
	}

};

int main()
{
	Solution s;
	int res = s.atoi("-2147483649");
	assert(s.atoi("--0012a42") == -12);

	return 0;
}

