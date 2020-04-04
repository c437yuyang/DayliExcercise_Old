
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A =[1,1,2],

Your function should return length =2, and A is now[1,2].


*/

#include <bits/stdc++.h>
class Solution
{
  public:
    int removeDuplicates(int A[], int n)
    {
        if (A == nullptr || n <= 1)
            return n;

        int pre = A[0];
        int newIdx = 1;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] != pre)
            {
                A[newIdx++] = A[i];
            }
            pre = A[i];
        }
        return newIdx;
    }
};
int main()
{
    Solution s;
    std::vector<int> arr{1, 1, 2, 3, 3, 4, 4};
    int res = s.removeDuplicates(&arr[0], arr.size());
    std::cout << res << std::endl;
    std::for_each(arr.begin(), arr.end(), [](int val) { std::cout << val << " "; });
    std::cout << std::endl;

    arr = {1, 1, 1};
    res = s.removeDuplicates(&arr[0], arr.size());
    std::cout << res << std::endl;
    std::for_each(arr.begin(), arr.end(), [](int val) { std::cout << val << " "; });
    std::cout << std::endl;

    return 0;
}
