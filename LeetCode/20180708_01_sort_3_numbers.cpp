/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

class Solution
{
public:
	void sortColors(int A[], int n)
	{
		if (A == nullptr || n <= 0)
			return;
		//其实就是一个partition,把1当做pivot
		int less = -1, more = n;
		int curIdx = 0;
		int pivot = 1;
		while (curIdx < more)
		{
			if (A[curIdx] < pivot)
				std::swap(A[curIdx++], A[++less]);
			else if (A[curIdx] > pivot)
				std::swap(A[curIdx], A[--more]);
			else
				++curIdx;
		}
	}
};

int main()
{
	int A[] = { 2,0,1,0,1,1,2,0,1 };
	int n = sizeof(A) / sizeof(A[0]);
	Solution().sortColors(A, n);
	ArrayHelper::printArr(A, n);


	//int A[] = { 2,2 };
	//int n = sizeof(A) / sizeof(A[0]);
	//Solution().sortColors(A, n);
	//ArrayHelper::printArr(A, n);

	return 0;
}