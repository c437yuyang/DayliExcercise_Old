/*
最长重复子串（子串中有重复子串，且首尾相连）长度 （ abcab   , 0；   abccab   ,2 ;   abbbcbbc   ,6）
*/
#include <iostream>
#include <string>
using namespace std;



int getCommLen(string str)
{
	int npos;
	if (str.size() % 2 == 0)
	{
		npos = str.size() / 2;
		if (str.substr(0, npos) == str.substr(npos, npos))
			return npos * 2;
	}
	return 0;
}

int main()
{
	//string str = "abbbcbbc";
	string str = "acbab";
	int maxLen = 0;
	//所以其实就是简单的,看每个位置开始，每个位置结束，送进去，看是不是满足条件就行了
	for (int i = str.size(); i >= 1; --i)
	{
		for (int j = 0; str.size() - j >= i; ++j)
		{
			string str1 = str.substr(j, i);
			maxLen = getCommLen(str1);
			if (maxLen)
			{
				cout << maxLen << endl;
				return maxLen; //这里不用std::max(maxLen,curMax),因为长度是从外向里找的，只会越来越小，当前找到了就是最大
			}
		}
	}
	cout << maxLen << endl;
	return 0;
}