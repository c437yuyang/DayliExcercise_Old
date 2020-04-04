#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>


class Solution
{
public:

	std::vector<int> searchRange(int A[], int n, int target)
	{
		int left = 0, right = n - 1;
		int retA = -1, retB = -1;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);

			if (A[mid] == target)
			{
				int left1 = mid, right1 = mid;
				while (left1 >= 0 && A[left1] == target)
					--left1;
				while (right1 < n && A[right1] == target)
					++right1;
				retA = left1 + 1;
				retB = right1 - 1;
				break;
			}
			else if (A[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
			
		}
		return{ retA,retB };
	}

	std::vector<int> searchRange1(int A[], int n, int target)
	{
		auto ret = std::equal_range(A, A + n, target);
		if ((*ret.first) != target) //stl的算法，没找到的话，会指向第一个可以插入的位置
			return{ -1,-1 };
		int a = ret.first - A;
		int b = ret.second - A - 1;
		return{ a,b };
	}
};




int main()
{
	Solution s;


	std::vector<int> arr = { 5, 7, 7, 8, 8, 10 };
	auto res = s.searchRange(&arr[0], arr.size(), 8);
	std::vector<int> res1 = { 3,4 };
	assert(res == res1);
	arr = { 1 };
	res = s.searchRange(&arr[0], arr.size(), 0);
	res1 = { -1,-1 };
	assert(res == res1);


	return 0;
}