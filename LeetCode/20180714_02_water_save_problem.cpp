/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given[0,1,0,2,1,0,1,3,2,1,2,1], return6.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>


//我的错的
//class Solution
//{
//public:
//	int trap(int A[], int n)
//	{
//		if (n <= 3 || A == nullptr)
//			return 0;
//
//		//遍历，对每个位置，找下一个刚好大于等于它的，再结算
//		int left = -1;
//		int res = 0;
//		int waterBottom = 0;
//		for (int i = 1; i < n; ++i)
//		{
//			//找到第一个大于等于left的，结算
//			if (left != -1 && A[i] >= A[left])
//			{
//				//执行结算
//				int waterTop = std::min(A[i], A[left]);
//				for (int j = left + 1; j < i; ++j)
//					res += (waterTop - A[j]);
//				left = -1;
//			}
//			else
//			{
//				//出现下坡就开始记
//				if (A[i] < A[i - 1] && left == -1)
//				{
//					//看后面到底有没有大于等于它的，有才能成为左边的起点
//					for (int j = i; j < n; ++j)
//					{
//						if (A[j] >= A[i - 1])
//							left = i - 1;
//					}
//				}
//			}
//		}
//		return res;
//	}
//};


class Solution
{
public:
	int trap(int arr[], int n)
	{
		if (n < 3 || arr == nullptr) //至少3个才能形成水库
			return 0;

		int maxIdx = std::max_element(arr, arr + n) - arr;
		//找到最大过后，分别算两边的
		int left = 0, right = n - 1, res = 0;

		//算左边的，只要出现当前位置小于左边的边界，就结算当前位置，因为右边一定有最大值做保证
		for (int i = 0; i < maxIdx; ++i)
		{
			if (arr[i] < arr[left])
				res += arr[left] - arr[i];
			else //只要当前数大于左边界，就更新，左边界一定不会变小
				left = i;
		}

		//算右边的，同理
		for (int i = n - 1; i > maxIdx; --i)
		{
			if (arr[i] < arr[right])
				res += arr[right] - arr[i];
			else
				right = i;
		}
		return res;
	}
};

void test1()
{
	std::vector<int> arr = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	Solution s;
	assert(s.trap(&arr[0], arr.size()) == 6);
}

void test2()
{
	std::vector<int> arr = { 2,0,2};
	Solution s;
	assert(s.trap(&arr[0], arr.size()) == 2);
}

void test3()
{
	std::vector<int> arr = { 4,2,3 };
	Solution s;
	assert(s.trap(&arr[0], arr.size()) == 1);
}

int main()
{
	test1();
	test2();
	test3();


	return 0;
}