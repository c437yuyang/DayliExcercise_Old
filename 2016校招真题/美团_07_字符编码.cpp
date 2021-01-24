/*
请设计一个算法，给一个字符串进行二进制编码，使得编码后字符串的长度最短。
输入描述:
每组数据一行，为待编码的字符串。保证字符串长度小于等于1000。
输出描述:
一行输出最短的编码后长度。
示例1
输入
复制
MT-TECH-TEAM
输出
复制
33
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
#include <functional>
#include <queue>
using namespace std;

int solve(std::string &str) {

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::unordered_map<char, int> hist;
	for (auto c : str) {
		++hist[c];
	}
	for (auto it : hist) {
		pq.push(it.second);
	}
	int res = 0;
	while (pq.size() > 1) {
		int cur1 = pq.top(); pq.pop();
		int cur2 = pq.top(); pq.pop();
		int cur = cur1 + cur2;
		pq.push(cur);
		res += cur;
	}
	return res;
}

int main() {
	string str;
	while (cin >> str) {
		cout << solve(str) << endl;
	}
	return 0;
}

