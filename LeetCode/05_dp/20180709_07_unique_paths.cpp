/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		if (m == 1 || n == 1)
			return 1;
		std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

		for (int i = m - 2; i >= 0; --i)
			for (int j = n - 2; j >= 0; --j)
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1]; //可以向右也可以向下
		return dp[0][0];
	}
};

int main()
{
	Solution s;
	s.uniquePaths(3, 7);

	return 0;
}