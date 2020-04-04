/*
����һ���ַ���str������ַ���str�е�����������ִ�
��������:
�������������1������������һ���ַ���str�����Ȳ�����255��
�������:
��һ�������str��������������ִ���
ʾ��1
����
����
abcd12345ed125ss123456789
���
����
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

