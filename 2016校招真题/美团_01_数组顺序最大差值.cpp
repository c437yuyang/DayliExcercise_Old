/*
有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。

给定数组A及它的大小n，请返回最大差值。

测试样例：
[10,5],2
返回：0
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

class LongestDistance {
public:
	//我的做法
	int getDis1(vector<int> A, int n) {
		// write code here
		int max = std::numeric_limits<int>::min();
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				max = std::max(max, A[j] - A[i]);
			}
		}
		return max;
	}

	//牛客看到的
	int getDis(vector<int> A, int n) {
		if (n == 1)
			return 0;
		int min = A[0];
		int max = 0;
		for (int i = 1; i < n; ++i) { //就是每次都更新min和dis即可，一趟就能完成
			int dis = A[i] - min;
			if (dis > max)
				max = dis;
			else if (A[i] < min) {
				min = A[i];
			}
		}
		return max;
	}

};

int main() {


	return 0;
}
