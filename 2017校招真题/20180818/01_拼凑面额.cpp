/*
给你六种面额1、5、10、20、50、100元的纸币，假设每种币值的数量都足够多，编写程序求组成N元（N为0-10000的非负整数）的不同组合的个数。
输入描述:
输入为一个数字N，即需要拼凑的面额
输出描述:
输出也是一个数字，为组成N的组合个数。
示例1
输入
5
输出
2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

long long solve(vector<int>&coins, int aim) {

	vector<vector<long long>> dp(aim + 1, vector<long long>(coins.size(), 0));
	int m = aim + 1;
	int n = coins.size();
	for (int j = 0; j < coins.size(); ++j)
		dp[0][j] = 1;

	for (int i = 1; i < aim + 1; ++i) {
		dp[i][n - 1] = (i % coins[n - 1]) == 0 ? 1 : 0;
	}

	for (int i = 1; i < aim + 1; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			int cnt = i / coins[j];
			for (int k = 0; k <= cnt; ++k) {
				dp[i][j] += dp[i - k*coins[j]][j + 1];
			}
		}
	}

	return dp[aim][0];
}

int main() {

	int n;
	cin >> n;
	vector<int > coins = { 1,5,10,20,50,100 };
	auto res =solve(coins, n);

	cout << res << endl;
	return 0;
}

