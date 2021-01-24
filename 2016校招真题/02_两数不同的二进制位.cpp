class Solution {
public:
	/**
	* 获得两个整形二进制表达位数不同的数量
	*
	* @param m 整数m
	* @param n 整数n
	* @return 整型
	*/
	int countBitDiff(int m, int n) {
		int mn = m^n;
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			res += (mn >> i) & 1;
		}
		return res;
	}
};

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


int main() {

	Solution s;
	int res = s.countBitDiff(1999, 2299);

	return 0;
}