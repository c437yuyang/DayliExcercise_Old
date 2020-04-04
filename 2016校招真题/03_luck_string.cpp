/*
A string s is LUCKY if and only if the number of different characters in s is a fibonacci number.
Given a string consisting of only lower case letters , output all its lucky non-empty substrings in lexicographical order. Same substrings should be printed once.
输入描述:
a string consisting no more than 100 lower case letters.
输出描述:
output the lucky substrings in lexicographical order.one per line. Same substrings should be printed once.
示例1
输入

aabcd
输出

a
aa
aab
aabc
ab
abc
b
bc
bcd
c
cd
d
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
#include <set>
using namespace std;

std::unordered_set<int> getFibonacciNumbers() {
	std::unordered_set<int> res;
	res.insert(1);
	int i1 = 1, i2 = 1; int i3 = 0;
	for (; i1 + i2 <= 100;) {
		i3 = i2 + i1;
		res.insert(i3);
		i1 = i2;
		i2 = i3;
	}
	return res;
}

//就是遍历每个子串
set<std::string> getAllLuckString(const std::string&str) {
	auto fibonacci = getFibonacciNumbers();
	set<std::string> res;
	for (int i = 0; i < str.length(); ++i) {
		std::unordered_set<char> diffSet;
		diffSet.insert(str[i]);

		for (int j = i; j < str.length(); ++j) {
			diffSet.insert(str[j]);
			if (fibonacci.find(diffSet.size()) != fibonacci.end()) {
				res.insert(str.substr(i, j - i + 1));
			}
		}
	}
	return res;

}


int main() {

	std::string str;
	cin >> str;
	auto res = getAllLuckString(str);
	for (auto s : res) {
		cout << s << endl;
	}

	return 0;
}