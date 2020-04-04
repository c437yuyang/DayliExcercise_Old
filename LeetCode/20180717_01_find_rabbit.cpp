/*
题目描述:

假设兔子有n个排成一排的洞，编号为1和n。兔子每天晚上跳到相邻的一个洞里住，而猎人每天白天检查其中的一个洞。猎人告诉你每天检查的洞的编号，希望你分析一下是否一定能抓到兔子。

输入描述：

首先输入n和k（n,k<1000），分别表示洞的个数和猎人；接下来输入k个整数，表示猎人每天检查的洞的编号。

输出描述：

对于每个样例，如果一定能抓到兔子，输出Yes，否则输出No。

示例：

样例1：

输入：

3  2

2  2

输出：

Yes
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

bool canFind1(int holeNum, int days, int *pos)
{
	std::vector<int> dp(holeNum, 1); //初始化所有洞为1

	for (int i = 0; i < days; ++i)
	{
		dp[pos[i] - 1] = 0; //当天的置为0
		std::vector<int> temp = dp;
		int j;

		for (j = 0; j < holeNum; ++j)
			if (temp[j] != 0)
				break;
		if (j == holeNum) //全0了
			return true;

		for (j = 0; j < holeNum; ++j)
		{
			if (j > 0 && j < holeNum - 1)
				dp[j] = std::max(temp[j - 1], temp[j + 1]);
			else if (j == 0)
				dp[j] = temp[j + 1];
			else if (j == holeNum - 1)
				dp[j] = temp[j - 1];
		}
	}
	return false;
}



#pragma region 递归dfs版
bool dfs(int curHole, int holeNum, int curDay, int days, int *no);

bool canFind(int holeNum, int days, int *no)
{
	bool res = true;
	for (int i = 1; res && i <= holeNum; ++i)
		res = res && dfs(i, holeNum, 1, days, no);
	return res;
}

bool dfs(int curHole, int holeNum, int curDay, int days, int *no)
{
	if (curHole == no[curDay - 1])
		return true;

	if (curDay == days)
		return false;

	bool res = true;
	if (curHole > 1)
		res = res && dfs(curHole - 1, holeNum, curDay + 1, days, no);
	if (res && curHole < holeNum)
		res = res && dfs(curHole + 1, holeNum, curDay + 1, days, no);
	return res;
}
#pragma endregion



void test1()
{
	int n = 3;
	int k = 2;
	std::vector<int> no = { 2,2 };
	bool res = canFind(n, k, &no[0]);
	assert(res);
	res = canFind1(n, k, &no[0]);
	assert(res);
	//std::cout << (res ? ("Yes") : ("No")) << std::endl;
}

void test2()
{
	int n = 5;
	int k = 6;
	std::vector<int> no = { 2,3,4,4,3,2 };
	bool res = canFind(n, k, &no[0]);
	assert(res);
	res = canFind1(n, k, &no[0]);
	assert(res);
	//std::cout << (res ? ("Yes") : ("No")) << std::endl;
}

void test3()
{
	int n = 3;
	int k = 2;
	std::vector<int> no = { 2,1 };
	bool res = canFind(n, k, &no[0]);
	assert(!res);
	res = canFind1(n, k, &no[0]);
	assert(!res);
	//std::cout << (res ? ("Yes") : ("No")) << std::endl;
}


int main()
{
	//int n, k;
	//std::cin >> n >> k;
	//std::vector<int> no(k);
	//for (int i = 0; i < k; ++i)
	//	std::cin >> no[i];


	test1();
	test2();
	test3();


	return 0;
}