/*
输入一个字符串，求出该字符串包含的字符集合
输入描述:
每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
输出描述:
每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
示例1
输入
abcqweracb
输出
abcqwer
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
#include <unordered_set>
#include <queue>
using namespace std;

std::string solve(std::string&str) {
	std::unordered_set<char> set;
	std::string res;

	for (int i = 0; i < str.length(); ++i) {
		if (set.find(str[i]) == set.end()) {
			res += str[i];
		}
		set.insert(str[i]);
	}
	return res;
}


int main() {
	std::string str;
	while (cin >> str) {
		cout << solve(str) << endl;
	}

	return 0;
}