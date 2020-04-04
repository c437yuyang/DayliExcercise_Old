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
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		if (n <= 1)
			return A[0] == target ? 0 : -1;
		int left = 0; int right = n - 1;
		while (left <= right) {

			int mid = left + ((right - left) >> 1);
			if (A[mid] == target) {
				return mid;
			} else if (A[mid] >= A[left]) {//中间大于左边，说明现在上半部分是有序的可以确定,这里必须带上等号，考虑[3,1],找1
				if (A[left] <= target && target < A[mid]) { //现在可以对上半部分执行二分
					right = mid - 1; //mid还是mid-1
				} else { //否则的话，下半部分递归，不是进行二分
					left = mid + 1;
				}
			} else { //中间小于左边，只能确定下半部分是有序的
				if (A[mid] < target && target <= A[right]) { //右边继续
					left = mid + 1;
				} else { //左边继续
					right = mid - 1;
				}
			}
		}

		return -1;
	}

	//另一个版本
	//先判断是否发生旋转，判断旋转的依据就是数组的第一个值大于最后一个值。
	//如果没有发生旋转，直接用二分查找
	//如果发生了旋转，找出旋转点，确定了两个有序的子数组，然后在有序的子数组中进行二分查找。while循环结束，
	//begin对应的是最大值，end对应的是最小值。
	int search1(int* A, int n, int target) {
		if (A == nullptr || n == 0) {
			return -1;
		}
		int begin = 0;
		int end = n - 1;
		if (A[begin] < A[end]) {
			return binarysearch(A, begin, end, target);
		} else {
			while (A[begin] > A[end]) {
				if (end - begin == 1) {
					break;
				}
				int mid = (begin + end) / 2;
				if (A[mid] > A[begin]) {
					begin = mid;
				} else {
					end = mid;
				}
			}
			if (target >= A[0]) { //现在begin就是反转点
				return binarysearch(A, 0, begin, target);
			} else {
				return binarysearch(A, begin + 1, n - 1, target);
			}
		}

	}

	int binarysearch(int* A, int begin, int end, int target) {
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (A[mid] > target) {
				end = mid - 1;
			} else if (A[mid] < target) {
				begin = mid + 1;
			} else {
				return mid;
			}
		}
		return -1;
	}

};

int main() {
	vector<int> v = { 4,5,6,7,0,1,2 };
	Solution s;
	for (auto i = 0; i < v.size(); ++i) {
		assert(s.search(&v[0], v.size(), v[i]) == i);
		assert(s.search1(&v[0], v.size(), v[i]) == i);
	}
	assert(s.search(&v[0], v.size(), 8) == -1);

	return 0;
}