/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
class Solution
{
public:
	string multiply(string num1, string num2)
	{
		//去除头部的0
		while (num1.front() == '0')
			num1.erase(num1.begin());

		while (num2.front() == '0')
			num2.erase(num2.begin());

		if (num1 == "" || num2 == "")
			return "0";

		int len1 = num1.length();
		int len2 = num2.length();
		std::vector<std::string> tmpRes;
		//计算相乘的每一行结果，放到tmpRes中
		for (int i = len2 - 1; i >= 0; --i)
		{
			std::string perRes;
			int carry = 0;
			int cur2 = num2[i] - '0';
			for (int j = len1 - 1; j >= 0; --j)
			{
				int cur1 = num1[j] - '0';
				int prod = cur1 * cur2 + carry;
				carry = 0;
				if (prod >= 10)
				{
					carry = prod / 10;
					prod = prod % 10;
				}
				perRes.insert(perRes.begin(), '0' + prod);
			}
			if (carry != 0)
				perRes.insert(perRes.begin(), '0' + carry);
			tmpRes.push_back(perRes);
		}

		//给高位的后面的补零
		int carry = 0;
		std::string res = "0";
		for (int i = 1; i < tmpRes.size(); ++i)
			tmpRes[i].append(i, '0');
		//执行相加
		for (int i=0;i<tmpRes.size();++i)
			res = addTwoNum(res, tmpRes[i]);
		return res;
	}


	std::string addTwoNum(std::string num1, std::string num2)
	{
		int len1 = num1.length();
		int len2 = num2.length();
		int maxLen = std::max(len1, len2);
		if (len2 > len1)
			num1 = std::string(len2 - len1, '0') + num1;
		else
			num2 = std::string(len1 - len2, '0') + num2;

		int carry = 0;
		std::string res;
		for (int i = maxLen - 1; i >= 0; --i)
		{
			int cur = num1[i] - '0' + num2[i] - '0' + carry;
			carry = 0;
			if (cur >= 10) //一定要注意等于要带上
			{
				carry = 1;
				cur -= 10;
			}
			res.insert(res.begin(), cur + '0');
		}
		if(carry > 0)
			res.insert(res.begin(), '1');
		return res;
	}
};
Solution s;


void test1()
{
	string s1 = "34";
	string s2 = "56";
	assert(s.multiply(s1, s2) == "1904");
}

void test2()
{
	string s1 = "498828660196";
	string s2 = "840477629533";
	assert(s.multiply(s1, s2) == "419254329864656431168468");
}

void test3()
{
	string s1 = "123";
	string s2 = "456";
	assert(s.multiply(s1, s2) == "56088");
}

int main()
{
	test1();
	test2();
	test3();



	return 0;
}