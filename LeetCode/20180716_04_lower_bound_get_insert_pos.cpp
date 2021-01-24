#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
public:
	int searchInsert(int A[], int n, int target)
	{
		int left = 0;
		int right = n - 1;
		int lastBig = -1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (A[mid] >= target)
			{
				lastBig = mid;
				right = mid - 1; //继续往前找大于等于target的
			}
			else 
			{
				left = mid + 1; //小于了就只能往后找
			}
		}
		return lastBig == -1 ? n : lastBig;
	}


	int searchInsert1(int A[], int n, int target)
	{
		return std::lower_bound(A, A + n, target) - A;
	}
};


int main()
{
	Solution s;

	std::vector<int> arr = { 1,3,5,6 };
	assert(s.searchInsert(&(arr[0]), arr.size(), 5) == 2);
	assert(s.searchInsert(&(arr[0]), arr.size(), 2) == 1);
	assert(s.searchInsert(&(arr[0]), arr.size(), 7) == 4);
	assert(s.searchInsert(&(arr[0]), arr.size(), 0) == 0);

	return 0;
}