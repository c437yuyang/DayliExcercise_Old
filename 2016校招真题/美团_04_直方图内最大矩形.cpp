/*
有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。比如，对于直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。

给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。

测试样例：
[2,7,9,4,1],5
返回：14
*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;

//单调栈的解法:找每个位置左右第一个比它小的数的位置

class MaxInnerRec {
public:
	int countArea(vector<int> A, int n) {
		// write code here
		std::unordered_map<int, int> left, right;
		std::stack<int> stack;
		for (int i = 0; i < n; ++i) {
			while (!stack.empty() && A[i] < A[stack.top()]) {
				int cur = stack.top();
				right[cur] = i;
				stack.pop();
				if (!stack.empty())
					left[cur] = stack.top();
			}
			stack.push(i);
		}

		//结算阶段
		while (stack.size() > 1) {
			int cur = stack.top();
			stack.pop();
			left[cur] = stack.top();
			//right[cur] = null
		}
		//最后一个
		//左右都是null

		//开始计算矩形面积
		int max = std::numeric_limits<int>::min();
		for (int i = 0; i < n; ++i) {
			int leftPos = left.find(i) == left.end() ? -1 : left[i];
			int rightPos = right.find(i) == right.end() ? n : right[i];
			max = std::max((rightPos - leftPos - 1) *A[i], max);
		}

		return max;
	}
};



int main() {

	vector<int> A = { 2,7,9,4,1 };
	int n = A.size();
	MaxInnerRec m;
	auto res = m.countArea(A, n);

	return 0;
}