/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
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
	int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
	{
		if (obstacleGrid.size() == 1) //一行,有任何一个是障碍就是0了
		{
			for (size_t i = 0; i < obstacleGrid[0].size(); ++i)
				if (obstacleGrid[0][i] == 1)
					return 0;
			return 1;
		}
		if (obstacleGrid[0].size() == 1) //一列
		{
			for (size_t i = 0; i < obstacleGrid.size(); ++i)
				if (obstacleGrid[i][0] == 1)
					return 0;
			return 1;
		}
		size_t m = obstacleGrid.size();
		size_t n = obstacleGrid[0].size();
		std::vector<std::vector<int>> dp(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), 0));

		//最后一行和最后一列赋值，遇到路障后就全部是0
		for (size_t i = obstacleGrid[0].size(); i > 0; --i) //这里只是尝试一下用size_t类型倒着循环而已
		{
			if (obstacleGrid[m - 1][i - 1] == 1) //最后一行
				break;
			dp[m - 1][i - 1] = 1;
		}

		for (size_t i = obstacleGrid.size(); i > 0; --i)
		{
			if (obstacleGrid[i - 1][n - 1] == 1)
				break;
			dp[i - 1][n - 1] = 1;
		}

		for (int i = dp.size() - 2; i >= 0; --i)
			for (int j = dp[0].size() - 2; j >= 0; --j)
			{
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1]; //一样的，因为如果grid[i+1][j]==1的话，dp[i+1][j]==0,加了也没事
			}

		return dp[0][0];
	}
};

int main()
{
	std::vector<std::vector<int>> mat(3, std::vector<int>(4, 0));
	mat[1][1] = 1;
	Solution s;
	auto res = s.uniquePathsWithObstacles(mat);
	return 0;
}