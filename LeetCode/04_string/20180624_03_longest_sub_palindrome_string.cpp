/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists 
one unique longest palindromic substring.
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
	std::string longestPalindrome(const std::string &str)
	{
		if (str.length() == 0)
			return "";

		int maxLen = 0, left, right;
		size_t leftBound = -1;
		for (size_t i = 0; i < str.length(); ++i) //每个位置开始
		{	//从任意位置往外扩
			left = i, right = i;//bab，这时从a往外扩
			while (left >= 0 && right < str.length()
				&& str[left] == str[right])
			{
				if (right - left + 1 >= maxLen)
				{
					leftBound = left;
					maxLen = right - left + 1;
				}
				--left;
				++right;
			}

			left = i, right = i + 1; //bb,从b,b往外扩
			while (left >= 0 && right < str.length()
				&& str[left] == str[right])
			{
				if (right - left + 1 >= maxLen)
				{
					leftBound = left;
					maxLen = right - left + 1;
				}
				--left;
				++right;
			}
		}
		return  str.substr(leftBound, maxLen);
	}
};


int main()
{
	std::string str = "abcba";

	Solution s;
	std::cout << s.longestPalindrome(str) << std::endl;

	str = "abccba";
	std::cout << s.longestPalindrome(str) << std::endl;

	str = "abb";
	std::cout << s.longestPalindrome(str) << std::endl;

	str = "cc";
	std::cout << s.longestPalindrome(str) << std::endl;

	return 0;
}