/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A =[2,3,1,1,4]

The minimum number of jumps to reach the last index is2. (Jump1step from index 0 to 1, then3steps to the last index.)


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
    //递归版本
    //int jump(int A[], int n)
    //{
    //	if (A == nullptr || n <= 1)
    //		return 0;
    //	int min = std::numeric_limits<int>::max();
    //	jumpProcess(A, 0, n, 0, min);
    //	return min;
    //}

    //void jumpProcess(int A[], int i, int n, int curStep, int &min)
    //{
    //	if (i > n - 1)
    //		return;
    //	if (curStep >= min)
    //		return;
    //	if (i == n - 1)
    //	{
    //		min = std::min(curStep, min);
    //		return;
    //	}
    //	for (int j = 1; j <= A[i]; ++j)
    //	{
    //		jumpProcess(A, i + j, n, curStep + 1, min);
    //	}
    //}

    //DP版本
    int jump(int A[], int n)
    {
        if (A == nullptr || n <= 1)
            return 0;
        std::vector<int> dp(n, std::numeric_limits<int>::max());
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 1; j <= A[i]; ++j)
            {
                if (i + j <= n - 1 && dp[i + j] != std::numeric_limits<int>::max())
                    dp[i] = std::min(dp[i], dp[i + j] + 1);
            }
        }
        return dp[0];
    }

    //牛客看到的
    // 当前能够到达的最远距离还没有到n，必须再走下一步
    int jump1(int A[], int n)
    {
        int curReach = 0, maxReach = 0, steps = 0;
        for (int i = 0; i < n && i <= maxReach; i++)
        {
            if (i > curReach) //steps-1步能够到达的距离,必须再走一步了
            {
                ++steps;
                curReach = maxReach;
            }
            maxReach = std::max(maxReach, i + A[i]); // step步最远距离
        }
        if (maxReach < n - 1)
            return -1;
        else
            return steps;
    }
};

int main()
{

    Solution s;
    std::vector<int> arr = {2, 3, 1, 1, 4};
    auto step = s.jump(&arr[0], arr.size());
    assert(step == 3);

    arr = {1, 2, 1, 1, 1};
    step = s.jump(&arr[0], arr.size());
    assert(step == 2);

    arr = {2, 0, 2, 0, 1};
    step = s.jump(&arr[0], arr.size());
    assert(step == 2);

    return 0;
}