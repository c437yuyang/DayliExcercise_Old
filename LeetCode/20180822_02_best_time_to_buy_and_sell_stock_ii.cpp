/*
Say you have an array for which the i-th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie,
buyoneandselloneshareofthestockmultipletimes). However, youmaynotengageinmultipletransactions
at the same time (ie, you must sell the stock before you buy again).
*/

/*
贪心法，低进高出，把所有正的价格差价相加起来。
把原始价格序列变成差分序列，本题也可以做是最大 m 子段和，m = 数组长度。
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int n = prices.size();
        for(int i=1;i<n;++i){
            int diff = prices[i]-prices[i-1];
            if(diff>0)
                res += diff;
        }
        return res;
    }
};