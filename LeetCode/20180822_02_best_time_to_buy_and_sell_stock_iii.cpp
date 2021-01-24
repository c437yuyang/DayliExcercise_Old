/*
描述
Say you have an array for which the i-th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before
you buy again).
分析
设状态 f(i)，表示区间 [0,i](0 ≤ i ≤ n−1) 的最大利润，状态 g(i)，表示区间 [i,n−1](0 ≤ i ≤
n − 1) 的最大利润，则最终答案为 max{f(i) + g(i)},0 ≤ i ≤ n − 1。
允许在一天内买进又卖出，相当于不交易，因为题目的规定是最多两次，而不是一定要两次。
将 原 数 组 变 成 差 分 数 组， 本 题 也 可 以 看 做 是 最 大 m 子 段 和，m = 2， 参 考 代 码：
*/

/*
*思路:
    可以将两次买股票看做数列中两组"递增"(不是真的递增) 数列
    相当于求解一个index, 将数组分为两部分, 满足
    max(prices[0:index)) - min(prices[0:index)) +
    max(prices[index:len]) - min(prices[index:len])
    最大;
     
    设left[index]为index天前获得的最大利润
    则有 left[index] = max(left[index -1], prices[index] - min); //min 为前index天最低价
    设right[index] 为index天后获得的最大列润
    则有 right[index] = max(right[index + 1], max - prices[index]) //max  为后index天最高价
 
    找到另 right[index] + left[index] 取最大值得index即可
 
*/

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        const int n = prices.size();

        vector<int> f(n, 0);
        vector<int> g(n, 0);
        int min = prices[0];
        for (int i = 1; i < n; ++i)
        {
            min = std::min(min, prices[i]);
            f[i] = std::max(f[i - 1], prices[i] - min);
        }

        int max = prices[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            max = std::max(max, prices[i]);
            g[i] = std::max(g[i + 1], max - prices[i]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            res = std::max(res, f[i] + g[i]);
        
        return res;
    }
};