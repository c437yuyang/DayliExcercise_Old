/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A =[1,1,1,2,2,3],

Your function should return length =5, and A is now[1,1,2,2,3].


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
	int removeDuplicates(int A[], int n) {
		if (n <= 2) {
			return n;
		}

		int newIdx = 1; //当前新数需要插入的位置，第一个数一定要，从1开始
		int cnt = 1; //累计几个一样的
		for (int i = 1; i < n; ++i) {
			if (A[i] == A[newIdx - 1]) {
				++cnt;
				if (cnt <= 2) {
					A[newIdx] = A[i];
					++newIdx;
				} //>2 continue
			} else {
				cnt = 1;
				A[newIdx] = A[i];
				++newIdx;
			}
		}
		return newIdx;

	}
};



int main() {
	vector<int> v = { 1,1,1,2,2,3,4,4,4,5,5,5 };
	Solution s;
	auto res = s.removeDuplicates(&v[0],v.size());

	return 0;
}