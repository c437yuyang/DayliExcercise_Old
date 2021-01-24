/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A =[2,3,1,1,4], returntrue.

A =[3,2,1,0,4], returnfalse.
*/

//my
class Solution
{
  public:
    bool canJump(int A[], int n)
    {
        if (A == nullptr)
            return false;
        if (n <= 1)
            return true;
        return process(A, 0, n);
    }

    bool process(int A[], int i, int n)
    {
        if (i > n - 1)
            return false;
        if (i == n - 1)
            return true;
        bool res = false;
        for (int j = A[i]; j >= 1; --j)
        {
            res = res || process(A, i + j, n);
        }
        return res;
    }
};
//牛客看到的
//因为是任意选n步，因此可以这样
bool canJump(int A[], int n)
{
    int maxReach = 0;
    for (int i = 0; i < n && i <= maxReach; i++) //这里的i<=maxReach限制了，必须能到才能继续下面的判定
        maxReach = std::max(maxReach, i + A[i]); /// 跳到该点后还能到达的极限
    if (maxReach < n - 1)
        return false;
    return true;
}

//这个dp版本也行，其实本质是一样的

bool canJump(int A[], int n)
{
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 0; i < n && dp[i]; i++)
    {
        for (int j = 0; j <= A[i]; j++)
            dp[i + j] = true;
    }
    return dp[n - 1];
}