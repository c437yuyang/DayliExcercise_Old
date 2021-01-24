/*
牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。

输入描述:
输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。


输出描述:
输出一个正整数, 表示牛牛一共有多少种零食放法。

输入例子1:
3 10
1 2 4

输出例子1:
8

例子说明1:
三种零食总体积小于10,于是每种零食有放入和不放入两种情况，一共有2*2*2 = 8种情况。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <numeric>
using namespace std;

//动态规划，应该也没有错，但是capacity太大的情况没法跑
int solve(std::vector<int>& v, int capacity)
{
	vector<vector<int>> dp(v.size(), std::vector<int>(capacity + 1, 0));
	for (int c = 0; c <= capacity; ++c)
	{
		if (v.back() <= c)
			dp[v.size() - 1][c] = 2;
		else dp[v.size() - 1][c] = 1;
	}

	for (int i = v.size() - 2; i >= 0; --i)
	{
		for (int j = capacity; j >= 0; --j)
		{
			dp[i][j] = dp[i + 1][j];
			if (j - v[i] >= 0)
				dp[i][j] += dp[i + 1][j - v[i]];
		}
	}
	return dp[0][capacity];
}

//直接深度搜索,AC
void dfs(vector<int>&nums, int i, int v,  int  &res)
{
	if (i == nums.size() && v >= 0)
	{
		++res;
		return;
	}
	if (i >= nums.size() || v < 0) //这里<0了一定要终止!!!
		return;

	dfs(nums, i + 1, v - nums[i], res);
	dfs(nums, i + 1, v , res);
}

int main()
{
	//int n, capacity;
	//cin >> n >> capacity;
	//vector<int> v(n);
	//for (int i = 0; i < n; ++i)
	//	cin >> v[i];
	vector<int> v = { 1,4,5 };
	int capacity = 10;
	v = { 842104736,130059605,359419358,682646280,378385685,622124412,740110626,814007758,557557315,
		40153082,542984016,274340808,991565332,765434204,225621097,350652062,714078666,381520025,613885618,64141537,783016950
	};
	capacity = 1165911996;
	
	//capacity = 2147483647;
	long long all = 0;
	for (int i=0;i<v.size();++i)
		all += v[i];
	if (all <= capacity)
	{
		std::cout << (int)pow(2, v.size()) << std::endl;
		return 0;
	}

	
	int res = 0;
	dfs(v, 0, capacity, res);
	cout << res << endl;
	//res = solve(v, capacity);
	//cout << res << endl;
	return 0;
}