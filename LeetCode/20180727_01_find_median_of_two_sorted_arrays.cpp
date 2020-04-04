/*
找两个已排序数组的中位数
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

//牛客看到的
class Solution
{
public:
	double findKth(int A[], int m, int B[], int n, int k)
	{
		if (m > n)
			return findKth(B, n, A, m, k); //始终保持元素较少的数组位于前面的位置
		if (m == 0)
			return B[k - 1]; //如果位于前面的数组为空，则直接返回后面数组的第k-1个元素
		if (k == 1)
			return min(A[0], B[0]); //如果k等于1，则返回两个数组头元素的最小值

		int pa = min(k / 2, m), pb = k - pa; //这里的边界值一定要注意!!!
		if (A[pa - 1] < B[pb - 1])
			return findKth(A + pa, m - pa, B, n, k - pa);
		else if (A[pa - 1] > B[pb - 1])
			return findKth(A, m, B + pb, n - pb, k - pb);
		else
			return A[pa - 1];
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2)
				+ findKth(A, m, B, n, total / 2 + 1)) / 2;
	}
};

int main()
{
	Solution s;
	std::vector<int> arr1 = { 1,3,5,7 };
	std::vector<int> arr2 = { 2,4,6,8 };

	double res = s.findMedianSortedArrays(&arr1[0], arr1.size(), &arr2[0], arr2.size());


	return 0;
}