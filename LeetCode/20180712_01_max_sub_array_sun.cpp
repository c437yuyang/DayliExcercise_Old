/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array[−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray[4,−1,2,1]has the largest sum =6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution
{
  public:
    int maxSubArray(int A[], int n)
    {
        if (A == nullptr || n <= 0)
            return 0;
        int max = std::numeric_limits<int>::min();
        int cur = 0; //可以加上两个idx就能记录位置了，如果max更新了就更新idx
        for (int i = 0; i < n; ++i)
        {
            cur += A[i];
            max = std::max(cur, max);
            if (cur < 0)
                cur = 0;
        }
        return max;
    }
};