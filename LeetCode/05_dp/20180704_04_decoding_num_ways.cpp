/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message"12", it could be decoded as"AB"(1 2) or"L"(12).

The number of ways decoding"12"is 2.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

//16.15,16.24
class Solution
{
public:
	//dfs版本，超时
	int numDecodings(string s)
	{
		if (s == "")
			return 0;
		return numDecodingsProcess(s, 0);
	}

	int numDecodingsProcess(std::string &s, int i)
	{
		if (i > s.length())
			return 0;
		if (i == s.length())
			return 1;
		if (s[i] == '0')
			return 0;

		int res = 0;
		res += numDecodingsProcess(s, i + 1);
		int num = stoi(s.substr(i, 2));
		if (num <= 26 && num >= 1)
			res += numDecodingsProcess(s, i + 2);

		return res;
	}


	//DP版本
	//主要就是注意一下，比如102这种，当s[i]=0的时候,dp[i]=0,然后s[i]=1的时候，加上dp[i+1]是等于0的，就只用加上dp[i+2]了
	int numDecodings1(std::string &s)
	{
		if (s == "" || s[0] == '0')
			return 0;

		int *dp = new int[s.length() + 1](); //从i位置开始编码的编码数
		dp[s.length()] = 1; //边界
		dp[s.length() - 1] = s[s.length() - 1] == '0' ? 0 : 1;//如果最后一个值是0，就不能编码
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (s[i] == '0') //如果当前位置为0，那么可编码数一定为0
				dp[i] = 0;
			else
			{
				dp[i] = dp[i + 1]; //不为0的话，首先自己单独成一个字符，就等于dp[i+1]种
				int num = stoi(s.substr(i, 2));
				if (s[i] > '0' &&  num <= 26 && num > 0) //以及从i位置取两个数,如果满足1-26的话，可以再加上dp[i+2]
					dp[i] += dp[i + 2];
			}
		}
		int ret = dp[0];
		delete[] dp;
		dp = nullptr;
		return ret;
	}
};


int main()
{
	Solution s;
	std::string str = "12";
	auto ret = s.numDecodings(str);
	ret = s.numDecodings1(str);


	str = "101";
	ret = s.numDecodings(str);
	ret = s.numDecodings1(str);

	str = "0";
	ret = s.numDecodings(str);
	ret = s.numDecodings1(str);

	//"26":2
	//"101":1
	return 0;
}