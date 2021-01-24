/*
题目描述
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
输出描述:
输出保留下来的结果。
示例1
输入
325 1
输出
35
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

//牛客看到的解法:
//思路是每次删掉第一个当前字符小于后一个字符的字符
string solve(string &number, int cnt) {
	int i = 0;
	while (i < cnt) {
		int j = 0;
		while (j < number.size() - 1 && number[j] >= number[j + 1]) {
			++j;
		}
		number.erase(j, 1); //如果没有找到的话，就删掉最后一个，因为最后一个就是最小的
		++i;
	}
	return number;
}



//dfs肯定超时
void dfs(string &number, int cnt, string&res) {
	if (cnt == 0) {
		if (atoi(res.c_str()) < atoi(number.c_str())) {
			res = number;
		}
		return;
	}
	for (int i = 0; i < number.length(); ++i) {
		char c = number[i];
		number.erase(number.begin() + i);
		dfs(number, cnt - 1, res);
		number.insert(number.begin() + i, c);
	}
}

string solve1(string &number, int cnt) {

	if (number.length() <= cnt)
		return "0";
	string res = "0";
	dfs(number, cnt, res);
	return res;
}



int main() {

	string number;
	int cnt;
	while (cin >> number >> cnt)
		cout << solve(number, cnt) << endl;

	return 0;
}