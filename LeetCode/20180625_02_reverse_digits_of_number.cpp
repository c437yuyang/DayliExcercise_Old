/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
click to show spoilers.
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
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
	int reverse(int x)
	{
		if (x == 0 || x / 10 == 0)
			return x;
		long long res = 0;
		while (x != 0)
		{
			res = res * 10 + x % 10; //-1%10 = -1 因此这里是对的
			bool overFlow = false;
			if (isOverFlow(res))
				return 0;
			x /= 10;
		}
		return res;
	}

	bool isOverFlow(long long res)
	{
		if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
			return true;
		return false;
	}
};
int main() 
{
	Solution s;
	assert(s.reverse(123) == 321);
	assert(s.reverse(-123) == -321);
	assert(s.reverse(-1230) == -321);
	
	int a1 = -11 % 10; //C语言里面-11%10 = -1的，python里面等于9
	int a2 = -1 % 10;

	return 0;
}