/*

小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
复制
4 24
输出
复制
5
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
void dfs(int src, int dst, int curRes, int &res);

int solve(int src, int dst)
{
	int res = std::numeric_limits<int>::max();
	dfs(src, dst, 0, res);
	return res == std::numeric_limits<int>::max() ? -1 : res;
}

vector<int> getFactors(int num);

//dfs只能过60%,超时
void dfs(int src, int dst, int curRes, int &res)
{
	if (dst == src)
	{
		res = std::min(res, curRes);
		return;
	}

	if (src > dst)
		return;

	if (curRes == res)
	{
		return;
	}

	//for (int i = src - 1; i >= 2; --i) //从大到小循环，更好，30%->60%
	//for (int i = src / 2; i >= 2; --i) //约数一定是从除2开始的
	//{
	//	if (src % i == 0 && src + i <= dst) //限制加上<=dst
	//		dfs(src + i, dst, curRes + 1, res);
	//}

	//因数必须这样求

	auto factors = getFactors(src);
	for (int i = 0; i < factors.size(); ++i)
	{
		dfs(src + factors[i], dst, curRes + 1, res);
	}

}

//动态规划
int solveDp(int src, int dst)
{
	std::vector<int> dp(dst + 1, std::numeric_limits<int>::max());
	dp[dst] = 0;

	for (int curPos = dst - 1; curPos >= src; --curPos)
	{
		auto factors = getFactors(curPos);
		for (int j = 0; j < factors.size(); ++j)
		{
			if (curPos + factors[j] <= dst &&
				dp[curPos + factors[j]] != std::numeric_limits<int>::max())
			{
				dp[curPos] = std::min(dp[curPos], dp[curPos + factors[j]] + 1);
			}
		}
	}

	return dp[src] == std::numeric_limits<int>::max() ? -1 : dp[src];
}

vector<int> getFactors(int num) //因数必须这样求，才能过，不能从除以2开始求
{
	vector<int> res;
	//求约数
	for (int i = sqrt(num); i >= 2; --i)
	{
		if (num % i == 0)
		{
			res.push_back(i);
			if (num / i != i)
				res.push_back(num / i);
		}
	}
	return res;
}


int main()
{
	/*int src, dst;
	cin >> src >> dst;

	cout << solveDp(src, dst) << endl;*/
	//cout << sovleDp(4, 24) << endl;

	cout << solveDp(4, 24) << endl;
	cout << solveDp(8, 85678) << endl;
	//cout << solve(8, 85678) << endl; //dfs跑这个用例，出不来




	return 0;
}