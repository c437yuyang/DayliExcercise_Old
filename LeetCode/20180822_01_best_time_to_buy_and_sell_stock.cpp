/*
Say you have an array for which the i-th element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the
stock), design an algorithm to find the maximum profit.

贪心法，分别找到价格最低和最高的一天，低进高出，注意最低的一天要在最高的一天之前。
把原始价格序列变成差分序列，本题也可以做是最大 m 子段和，m = 1。

*/

class Solution
{
  public:
    //我的方法
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        int n = prices.size();
        vector<int> min(n, prices[0]);     //从左往右，维持一个到i为止的最小值
        vector<int> max(n, prices[n - 1]); //从右往左，维持一个到i为止的最大值
        for (int i = 1; i < n; ++i)
        {
            min[i] = std::min(min[i - 1], prices[i]);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            max[i] = std::max(max[i + 1], prices[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res = std::max(res, max[i] - min[i]);
        }
        return res;
    }

    //leetcode题解
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int profit = 0;          // 差价，也就是利润
        int cur_min = prices[0]; // 当前最小
        for (int i = 1; i < prices.size(); i++) //从左往右遍历，确保在前面
        {
            profit = max(profit, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        return profit;
    }
};