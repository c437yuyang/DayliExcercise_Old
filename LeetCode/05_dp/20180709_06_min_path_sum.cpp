/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
 which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m);
        for_each(dp.begin(), dp.end(), [n](vector<int> &tmp) { tmp.resize(n); });

        dp[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int i = m - 2; i >= 0; --i)
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];

        for (int j = n - 2; j >= 0; --j)
            dp[m - 1][j] = dp[m - 1][j + 1] + grid[m - 1][j];

        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = grid[i][j] + std::min(dp[i][j + 1], dp[i + 1][j]);
        return dp[0][0];
    }
};