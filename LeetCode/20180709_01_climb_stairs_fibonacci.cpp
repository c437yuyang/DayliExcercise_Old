/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
//就是斐波那契数列
class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int pre1 = 1;
        int pre2 = 2;
        int res;
        for (int i = 3; i <= n; ++i)
        {
            res = pre1 + pre2;
            pre1 = pre2;
            pre2 = res;
        }
        return res;
    }
};