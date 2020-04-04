#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> tmp(array.size(), 0);
        int oddCnt = std::count_if(array.begin(), array.end(), [](int val) { return val & 1; });
        int odd_cur = 0, even_cur = oddCnt;
        for (size_t i = 0; i < array.size(); ++i)
        {
            if (array[i] & 1)
                tmp[odd_cur++] = array[i];
            else
                tmp[even_cur++] = array[i];
        }
        for (size_t i = 0; i < array.size(); ++i)
        {
            array[i] = tmp[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    s.reOrderArray(arr);
    return 0;
}