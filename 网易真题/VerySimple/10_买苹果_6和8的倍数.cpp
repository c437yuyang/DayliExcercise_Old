/*
题目描述
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果
输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1
示例1
输入
20
输出
3
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;
void dfs(int left, int curRes, int &res);
int solve(int n)
{
	int res = std::numeric_limits<int>::max();
	dfs(n, 0, res);
	return res == std::numeric_limits<int>::max() ? -1 : res;
}

void dfs(int left, int curRes, int &res)
{
	if (left == 0)
	{
		res = std::min(res, curRes);
		return;
	}

	if (curRes == res)
		return;

	if (left < 6)
		return;

	dfs(left - 6, curRes + 1, res);
	dfs(left - 8, curRes + 1, res);

}

//dp版本
int solve1(int n)
{
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < 6; ++i)
		dp[i] = INT_MAX;
	for (int i = 6; i <= n; i += 6)
		dp[i] = i / 6;
	for (int i = 8; i <= n; i += 8)
		dp[i] = i / 8;

	for (int i = 9; i <= n; ++i)
	{
		if (dp[i - 6] != INT_MAX)
			dp[i] = std::min(dp[i - 6] + 1, dp[i]);
		if (dp[i - 8] != INT_MAX)
			dp[i] = std::min(dp[i - 8] + 1, dp[i]);
	}

	return dp[n]==INT_MAX?-1:dp[n];
}


//复杂度O(1)方法
//import java.util.*;
//public class Main
//{
//	public static void main(String args[])
//	{
//		Scanner in = new Scanner(System.in);
//		while (in.hasNextInt())
//		{
//			int n = in.nextInt();
//			System.out.println(count(n));
//		}
//	}
//	public static int count(int n)
//	{
//		if (n % 2 != 0 || n == 10 || n < 6) return -1;//一定是偶数（6，8都是）,最小是6，10以上偶数都可以；
//		if (n % 8 == 0) return n / 8;//如果拿八个拿完最好
//		return 1 + n / 8;//对于10以上的偶数，只要对8取余数不为0，就要从前面的1或者2个8中拿出2个，把余数补为6（本来余数就是6，就不用拿）。所以+1；
//	}
//}
//如20,除8余4，那么从前面的8拿一个2，把4补成6即可

int main()
{
	int n;
	cin >> n;
	//cout << solve(n) << endl;
	cout << solve1(n) << endl;


	return 0;
}