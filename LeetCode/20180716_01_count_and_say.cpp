/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1is read off as"one 1"or11.
11is read off as"two 1s"or21.
21is read off as"one 2, thenone 1"or1211.

Given an integer n, generate the n th sequence.

Note: The sequence of integers will be represented as a string.

// 思路：n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，所以输出11；
// n=3时，由于上次字符是11，有2个1，所以输出21；
// n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。
// 依次类推，写个countAndSay(n)函数返回字符串。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
//10.50

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n <= 0)
			return "";
		if (n == 1)
			return "1";

		string cur = "1";
		for (int i = 2; i <= n; ++i)
			cur = getNext(cur);
		return cur;
	}

	string getNext(string &cur)
	{
		string res;
		int prePos = 0;
		char preCh = cur[0];
		for (int i = 1; i < cur.size(); ++i)
		{
			if (cur[i] != preCh)
			{
				res += ch2str((i - 1 - prePos + 1) + '0') + ch2str(preCh);
				preCh = cur[i];
				prePos = i;
			}
		}
		res += ch2str((char)(cur.length() - 1 - prePos + 1) + '0') + ch2str(preCh);
		return res;
	}

	string ch2str(char c)
	{
		return std::string(1, c);
	}

};

int main()
{
	Solution s;
	auto res = s.countAndSay(5);
	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << s.countAndSay(i) << endl;
	//}


	return 0;
}