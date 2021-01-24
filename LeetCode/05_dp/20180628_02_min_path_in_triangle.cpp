/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
Note: 
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/

class Solution
{
  public:
    //递归版本
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        return minPath(triangle, 0, 0);
    }

    int minPath(vector<vector<int>> &nums, int i, int j)
    {
        if (i == nums.size() - 1)
            return nums[i][j];
        int min = std::numeric_limits<int>::max();
        for (size_t col = j; col <= j + 1; ++col)
        {
            min = std::min(min, nums[i][j] + minPath(nums, i + 1, col));
        }
        return min;
    }

   //动态规划
    int minimumTotal(vector<vector<int>> &triangle)
    {
        auto dp = triangle;
        for (int i = triangle.size() - 2; i >= 0; --i)
        {
            for (size_t j = 0; j < triangle[i].size(); ++j)
            {
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};