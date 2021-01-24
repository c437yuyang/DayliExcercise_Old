/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e.,0 1 2 4 5 6 7might become4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>


class Solution
{
public:
	int search(int arr[], int n, int target)
	{
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) / 2);
			if (arr[mid] == target)
				return mid;

			if (arr[mid] > arr[left]) //左边部分有序,如:4 5 6 7 0 1 2
			{
				if (arr[mid] > target && target >= arr[left]) //比如找5
					right = mid - 1;
				else//比如找2
					left = mid + 1;
			}
			else //右边有序，如:7,1,2,3,4,5,6
			{
				if (arr[mid] < target && target <= arr[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};
int main()
{
	std::vector<int> arr = { 4, 5, 6 ,7 ,0 ,1 ,2 };
	Solution s;
	assert(s.search(&arr[0], arr.size(), 2) == arr.size() - 1);
	assert(s.search(&arr[0], arr.size(), 1) == arr.size() - 2);
	assert(s.search(&arr[0], arr.size(), 4) == 0);
	assert(s.search(&arr[0], arr.size(), 5) == 1);
	assert(s.search(&arr[0], arr.size(), 6) == 2);
	assert(s.search(&arr[0], arr.size(), 7) == 3);

	return 0;
}