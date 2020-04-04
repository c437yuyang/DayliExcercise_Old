/*
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
输入描述:
每个测试输入包含2个整数,n和m
输出描述:
按每个组合的字典序排列输出,每行输出一种组合
示例1
输入

5 5
输出

1 4
2 3
5
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;


//dfs的做法
void dfs(int maxNum, int curNum, int curSum, int target, std::vector<int> &curRes, std::vector<std::vector<int>> &res);
std::vector<std::vector<int>> getSum(int maxNum, int targetsum)
{

	if (maxNum == 0)
		return{};

	std::vector<int> curres;
	std::vector<std::vector<int>> res;

	dfs(maxNum, 1, 0, targetsum, curres, res);

	return res;
}


void dfs(int maxNum, int curNum, int curSum, int target, std::vector<int> &curRes, std::vector<std::vector<int>> &res)
{
	if (curSum == target)
	{
		if (std::find(res.begin(), res.end(), curRes) == res.end())
			res.push_back(curRes);
		return;
	}
	if (curSum > target)
		return;
	if (curNum == maxNum)
		return;

	for (int i = curNum; i <= maxNum; ++i)
	{
		int tmpCurSum = curSum + i;
		curRes.push_back(i);
		dfs(maxNum, i + 1, tmpCurSum, target, curRes, res);
		curRes.pop_back();
	}
}


//这个方法不对，只能找到两个数相加等于target的，多个数还是只能dfs
std::vector<std::vector<int>> getSum1(int maxNum, int targetsum)
{

	if (maxNum == 0)
		return{};

	std::vector<int> curres;
	std::vector<std::vector<int>> res;

	for (int i = 1; i <= targetsum / 2; ++i)
	{
		int left = targetsum - i;
		if (left != i && left <= maxNum && std::find(res.begin(), res.end(),
			std::vector<int>{i, left}) == res.end())
			res.push_back({ i,left });
	}
	if (maxNum >= targetsum)
		res.push_back({ targetsum });

	return res;
}

int main()
{
	//auto v = getSum(5, 5);

	int n, m;
	cin >> n >> m;
	//auto  v = getSum(n, m);
	auto  v = getSum1(n, m);
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j];
			if (j != v[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}


	return 0;
}

