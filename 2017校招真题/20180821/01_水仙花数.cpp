/*
春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的： “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。 现在要求输出所有在m和n范围内的水仙花数。
输入描述:
输入数据有多组，每组占一行，包括两个整数m和n（100 ≤ m ≤ n ≤ 999）。
输出描述:
对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
如果给定的范围内不存在水仙花数，则输出no;
每个测试实例的输出占一行。
示例1
输入
复制
100 120
300 380
输出
复制
no
370 371
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

bool isShuiXianNum(int num) {
	int numsave = num;
	vector<int> digits;
	while (num != 0) {
		digits.push_back(num % 10);
		num /= 10;
	}
	int res = 0;
	for (int i = 0; i < digits.size(); ++i) {
		res += (int)pow(digits[i], 3);
	}
	return res == numsave;
}


void solve(int m, int n) {
	vector<int> res;
	for (int i = m; i <= n; ++i) {
		if (isShuiXianNum(i))
			res.push_back(i);
	}

	if (res.empty()) {
		cout << "no" << endl;
		return;
	}

	for (int i=0;i<res.size();++i)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}

}


int main() {

	int m, n;
	while (cin >> m >> n) {
		solve(m, n);
	}

	return 0;
}