/*
对于一个由0..n的所有数按升序组成的序列，我们要进行一些筛选，每次我们取当前所有数字中从小到大的第奇数位个的数，并将其丢弃。重复这一过程直到最后剩下一个数。请求出最后剩下的数字。
输入描述:
每组数据一行一个数字，为题目中的n(n小于等于1000)。
输出描述:
一行输出最后剩下的数字。
示例1
输入
复制
500
输出
复制
255
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
#include <list>
using namespace std;

int solve(int n) {
	std::list<int> list;
	for (int i = 0; i < n; ++i) {
		list.push_back(i);
	}

	while (list.size() > 1) {
		int idx = 0;
		auto it = list.begin();
		for (; it != list.end(); ++idx) {
			if ((idx + 1) % 2 == 1) {
				it = list.erase(it); //删除后返回下一个
			} else {
				++it;
			}
		}
	}
	return list.front();
}


int main() {

	int n;
	while (cin >> n) {
		cout << solve(n) << endl;

	}

	//cout << solve(500) << endl;

	return 0;
}