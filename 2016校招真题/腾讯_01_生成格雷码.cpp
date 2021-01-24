/*
在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。

给定一个整数n，请返回n位的格雷码，顺序为从0开始。

测试样例：
1
返回：["0","1"]
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
#include <iterator>
using namespace std;

class GrayCode {
public:


	//非递归版本
	vector<string> getGray_NoRecur(int n) {
		vector<string> res = { "0","1" };
		if (n == 1) {
			return res;
		}

		for (int i = 2; i <= n; ++i) {
			vector<string> cur1 = res;
			vector<string> cur2 = res;
			for (int i = 0; i < res.size(); ++i) {
				cur1[i] = std::string(1, '0') + cur1[i];
				cur2[i] = std::string(1, '1') + cur2[i];
			}
			res = cur1;
			for (int i = cur2.size() - 1; i >= 0; --i) {
				res.push_back(cur2[i]);
			}
		}
		return res;
	}

	vector<string> getGray(int n) {
		// write code here
		vector<string> res;
		process(n, 0, res);
		return res;
	}

	//题目要求必须写递归。。
	void process(int allStep, int curStep, vector<string>& res) {
		if (curStep == allStep) {
			return;
		}

		if (curStep == 0) {
			res = { "0","1" };
			process(allStep, curStep + 1, res);
			return;
		}

		vector<string> v = res;
		vector<string> v1 = res;
		for (int i = 0; i < v.size(); ++i) {
			v[i].insert(v[i].begin(), '0');
		}

		for (int i = 0; i < v1.size(); ++i) {
			v1[i].insert(v1[i].begin(), '1');
		}
		vector<string> curRes;
		for (int i = 0; i < res.size(); ++i) {
			curRes.push_back(v[i]);
		}
		for (int i = 0; i < res.size(); ++i) {
			curRes.push_back(v1[v1.size() - 1 - i]);
		}

		res = curRes;
		process(allStep, curStep + 1, res);
	}


	//这个和题目无关，只是放在这里，是生成数字的格雷码
	vector<int> grayCode(int n) {
		int size = (int)pow(2, n);
		vector<int> res(size);
		for (int i = 0; i < size; ++i) {
			res[i] = i ^ (i / 2);
		}
		return res;
	}

};

int main() {
	GrayCode gc;
	vector<int> res = gc.grayCode(3);
	vector<string> res1 = gc.getGray(3);
	vector<string> res2 = gc.getGray_NoRecur(3);

	return 0;
}