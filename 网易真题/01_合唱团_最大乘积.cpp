
/*
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1
输入
复制
3
7 4 7
2 50
输出
复制
49
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

//dfs版本，AC 80%
void dfs(vector<int > &capacitys, int  curPos, int  k, int  maxDist, long long  &res, long long  curRes);
long long  solve(vector<int > &capacitys, int  k, long long  maxDist)
{
	long long  res = std::numeric_limits<long long >::min();
	long long  curRes = 1;

	for (long long i = 0; i < capacitys.size(); ++i)
	{
		dfs(capacitys, i, k, maxDist, res, curRes);
	}
	return res;
}

void dfs(vector<int > &capacitys, int  curPos, int  k, int  maxDist, long long  &res, long long  curRes)
{
	if (k == 0)
	{
		if (curRes > res)
			res = curRes;
		return;
	}

	if (curPos >= capacitys.size())
		return;
	curRes *= capacitys[curPos];
	for (int i = curPos + 1; i <= curPos + maxDist; ++i)
	{
		dfs(capacitys, i, k - 1, maxDist, res, curRes);
	}
}

int solve1(vector<int> a, int k, int d)
{
	int n = a.size();
	vector<vector<long long>> dp_max(n, vector<long long>(k + 1, std::numeric_limits<long long>::min()));
	vector<vector<long long>> dp_min(n, vector<long long>(k + 1, std::numeric_limits<long long>::max()));
	for (int i = 0; i < n; i++)
	{
		dp_max[i][1] = a[i];
		dp_min[i][1] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			for (int m = max(0, i - d); m <= i - 1; m++)
			{
				dp_max[i][j] = std::max(dp_max[i][j], std::max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i])); //这里之所以还必须和dp_max[i][j]比较，因为现在是固定了i,j，然后看在d的范围内可能出现的情况，因此上一种情况的肯定的记下啊
				dp_min[i][j] = std::min(dp_min[i][j], std::min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
			}
		}
	}
	long long max_value = dp_max[k - 1][k];
	for (int i = k; i < n; i++)
	{
		max_value = max(max_value, dp_max[i][k]);
	}
	return max_value;
}


int main()
{
	std::vector<int> capacities = { 7,4,7,8,9 };
	int res = solve(capacities, 2, 50);
	//assert(res == 72);

	capacities = { 7,4,7 };
	res = solve1(capacities, 2, 50);
	assert(res == 49);

	capacities = { 7,4,7,1,1,1,1,1,1,1,1,1,8 };
	res = solve(capacities, 2, 5);
	assert(res == 49);


	/*long long  n;
	cin >> n;
	std::vector<long long > capacities(n);
	for (long long  i=0;i<n;++i)
	{
		cin >> capacities[i];
	}

	long long  k, d;
	cin >> k >> d;

	cout << solve(capacities, k, d) << endl;*/


	return 0;
}