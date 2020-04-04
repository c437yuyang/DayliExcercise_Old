/*
有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
输入描述:
输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
输出描述:
输出包括一行，为走法的数目。
示例1
输入
3 2
输出
10
*/
#include <vector>
#include <iostream>
using namespace std;

int solve(int rows, int cols) {
	vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 1));
	//从i,j位置走到[rows,cols]位置的走法数目
	for (int i = rows - 1; i >= 0; --i) {
		for (int j = cols - 1; j >= 0; --j) {
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	return dp[0][0];

	//从0，0走到i,j位置的走法数目，[i,0],[0,j] 初始化为1
	//for (int i = 1; i <= rows; ++i) {
	//	for (int j = 1; j <= cols; ++j) {
	//		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	//	}
	//}
	//return dp[rows][cols];
}


int main() {
	int m, n;
	cin >> m >> n;

	cout << solve(m, n) << endl;

	return 0;
}