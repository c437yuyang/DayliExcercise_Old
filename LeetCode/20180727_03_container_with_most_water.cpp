/*
Given n non-negative integers a1 , a2 , ..., an , where each represents a point at coordinate (i, ai ). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai ) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

/*
     * 贪心算法：从两边开始向中间缩小;每一步比较左右边界高度,高度小的那个向里走一步
     * 
     * 这个贪心算法,为什么最优解不会被错过？         反证法 假设会被错过。
     *         假设最优解是横坐标为x1,x2(x2在右边)的这两个点组成的
     *               只考虑扫描到x2时,x1被错过的情况(x2被错过同理)：
     *         被错过指的是 当右指针向左扫描经过x2之后,左指针还在x1的左边P处时,x1被错过。
     * 
     *                     情况一   x2>p:  x2会被保留,然后左指针向右移动到x1,x1不会被错过
     *                     情况二   x2<p:  小情况一：height[p]>height[x1]    则最优解为 p,x2而不是 x1,x2。  假设不成立
     *                                   小情况二：p<=x1  最优解还是p,x2。 假设不成立
     *                             //因为x2比p和x1都小,所以容器高度取决于x2,而p比x1偏左,所以p,x2比x1,x2面积大
     */

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
            return 0;
        int left = 0, right = height.size() - 1;
        int max = std::numeric_limits<int>::min();
        while (left < right)
        {
            max = std::max(max, std::min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
            {
                left++;
            }
            else
                --right;
        }
        return max;
    }
};