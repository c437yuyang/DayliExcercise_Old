/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
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
	void merge(int A[], int m, int B[], int n)
	{
		if (A == nullptr)
			return;
		if (B == nullptr || n == 0)
			return;
		if (m == 0)
		{
			memcpy(A, B, sizeof(int)*n);
			return;
		}

		int idxA = m - 1, idxB = n - 1, idxDst = m + n - 1;
		while (idxA >= 0 && idxB >= 0)
			A[idxDst--] = A[idxA] > B[idxB] ? A[idxA--] : B[idxB--];

		while (idxA >= 0)
			A[idxDst--] = A[idxA--];
		while (idxB >= 0)
			A[idxDst--] = B[idxB--];
	}
};
int main()
{
	Solution s;

	int arr1[] = { 1,5,7,0,0,0 };
	int arr2[] = { 2,3,4 };

	s.merge(arr1,3 ,arr2,3);
	
	ArrayHelper::printArr(arr1,6);

	

	return 0;
}