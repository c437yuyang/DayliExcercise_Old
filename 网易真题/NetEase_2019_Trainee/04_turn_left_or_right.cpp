/*
牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。


输出描述:
输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。

输入例子1:
3
LRR

输出例子1:
E
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

void solve(string &str)
{
	char LeftTurn[5] = { "NWSE" };
	char RightTurn[5] = { "NENW" };
	int lCnt = 0, rCnt = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == 'L')
			++lCnt;
		else ++rCnt;
	}

	if (lCnt > rCnt) //说白了就是看左比右多几次，就会转几次，LR会抵消掉
		std::cout << LeftTurn[(lCnt - rCnt) % 4] << std::endl;
	else 
		std::cout << RightTurn[(rCnt - lCnt) % 4] << std::endl;
}


int main()
{
	int cnt;
	cin >> cnt;
	std::string str;
	while (cnt--)
	{
		char c;
		cin >> c;
		str += c;
	}
	solve(str);
		
	return 0;
}
