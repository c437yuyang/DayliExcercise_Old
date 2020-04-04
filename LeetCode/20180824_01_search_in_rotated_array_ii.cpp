/*
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
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
	bool search(int A[], int n, int target) {
		if (n <= 1)
			return A[0] == target ? true : false;
		int left = 0; int right = n - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (A[mid] == target) {
				return true;
			}
			if (A[mid] > A[left]) {//中间大于左边，说明现在上半部分是有序的可以确定,
				if (A[left] <= target && target < A[mid]) { //现在可以对上半部分执行二分
					right = mid - 1; //mid还是mid-1
				} else { //否则的话，下半部分递归，不是进行二分
					left = mid + 1;
				}
			} else if (A[mid] < A[left]) { //中间小于左边，只能确定下半部分是有序的
				if (A[mid] < target && target <= A[right]) { //右边继续
					left = mid + 1;
				} else { //左边继续
					right = mid - 1;
				}
			} else { //left==mid,考虑13111,就往下走一个，可能有多个相同的，反正一直往下走就行了
				++left;
			}
		}
		return false;
	}
};

int main() {
	//vector<int> v = { 4,4,5,5,6,7,0,0,1,2 };
	//Solution s;

	//assert(s.search(&v[0], v.size(), 4) == 0);
	//assert(s.search(&v[0], v.size(), 5) == 2);
	//assert(s.search(&v[0], v.size(), 6) == 4);
	//assert(s.search(&v[0], v.size(), 7) == 5);
	//assert(s.search(&v[0], v.size(), 0) == 6);
	//assert(s.search(&v[0], v.size(), 1) == 8);
	//assert(s.search(&v[0], v.size(), 2) == 9);


	Solution s;
	vector<int> v = { 1,1 };
	auto res = s.search(&v[0], v.size(), 0);

	v = { 1,3,1,1,1 };
	res = s.search(&v[0], v.size(), 3);

	return 0;
}