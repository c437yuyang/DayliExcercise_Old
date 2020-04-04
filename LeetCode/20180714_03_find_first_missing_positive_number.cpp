/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given[1,2,0]return3,
and[3,4,-1,1]return2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

/*
Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.

最简单也是功能最强大的算法就是基于计数排序的思路。
对0,1,2,...,n范围内的数把他放到对应的下标处。比如对于元素i放到下标i-1处，
然后对数组从前往后遍历，找到第一个不匹配的，即是最小缺失正数。

*/

class Solution
{
public:
	int firstMissingPositive(int A[], int n)
	{
		if (A == nullptr || n < 1)
			return 1;

		for (int i = 0; i < n; ++i) 
			while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) 
				std::swap(A[A[i] - 1], A[i]);
		for (int i = 0; i < n; ++i)
			if (A[i] != i + 1)
				return i + 1;
		return n + 1; //前面的都对，就返回下一个
	}
};

int main()
{


	return 0;
}