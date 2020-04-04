/*
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入
复制
abcd12345ed125ss123456789
输出
复制
123456789
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

std::string solve(std::string &str)
{
	int pre = -1;
	int startIdx = -1;
	int len = 0;
	int maxLen = 0;
	int maxStartIdx = -1;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '1')
		{
			startIdx = i;
			len = 1;
		}
		else if (str[i] == pre + 1)
			++len;
		if (len > maxLen)
		{
			maxLen = len;
			maxStartIdx = startIdx;
		}
		pre = str[i];
	}
	return str.substr(maxStartIdx, maxLen);
}


int main()
{
	std::string str;
	cin >> str;
	cout << solve(str) << endl;

	return 0;
}

