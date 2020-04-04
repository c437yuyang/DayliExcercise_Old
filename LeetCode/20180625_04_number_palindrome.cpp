/*
Determine whether an integer is a palindrome. Do this without extra space.
click to show spoilers.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
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
	/// <summary>
	/// 我的方法，错误的，但是可以看看思路
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	bool isPalindrome2(int x)
	{
		if (x == 0)
			return true;

		if (x < 0)
			return false;

		int digits = getDigitsOfNum(x);
		int i = 0;
		while ((++i) * 2 <= digits)
		{
			int lastDigit = x % 10;
			int firstDigit = getAndRemoveHighDigit(x); //这样不行，如果中间有0，比如1000110001移掉第一位和最后一位后，就变成了11000了
			if (lastDigit != firstDigit)
				return false;
			x /= 10;
		}
		return true;
	}

	int getDigitsOfNum(int num)
	{
		if (num < 0)
			num = -num;
		if (num == 0)
			return 1;
		int res = 0;
		while (num)
		{
			num /= 10;
			++res;
		}
		return res;
	}

	int getAndRemoveHighDigit(int& value)
	{
		int div = 1;
		while (value / div >= 10)
			div *= 10;

		int res = value / div;
		value = value % div;
		return res;
	}

	/// <summary>
	/// 正确做法,牛客看到的
	/// </summary>
	/// <param name="x"></param>
	/// <returns></returns>
	bool isPalindrome(int x)
	{
		if (x == 0 || (x < 10 && x > 0))
			return true;
		if (x < 0 || x % 10 == 0)
			return false;
		int reverse = 0;
		while (x > reverse)
		{ //x的位数始终是大于等于reverse的，因此可以这样来判断
			//逐渐的把每一位逆序移动到reverse里面去
			reverse = reverse * 10 + x % 10;
			x /= 10;
		}
		return x == reverse || reverse / 10 == x; //比如121,最后reverse = 12 , x = 1
	}

};

int main()
{
	Solution s;
	assert(s.isPalindrome(9999) == true);
	assert(s.isPalindrome(1000000001) == true);
	assert(s.isPalindrome(1000110001) == true);

	return 0;
}