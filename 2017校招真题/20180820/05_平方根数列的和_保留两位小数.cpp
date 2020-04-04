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

//保留两位小数
//其实可以直接printf("%.2lf\n")就可以了
std::string f(long double num) {
	num *= 100;
	num = round(num);
	std::string str = to_string(num);
	int pos = str.find('.');
	if (pos != -1) { //always true
		str = str.substr(0, pos);
	}
	str.insert(str.begin() + str.length() - 2, '.');
	return str;
}


std::string solve(int n, int m) {
	long double cur = n;
	long double res = 0;
	for (int i = 0; i < m; ++i) {
		res += cur;
		cur = sqrt(cur);
	}
	return f(res);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << solve(n, m) << endl;
		//cout << f(sqrt(n)) << endl;
	}

	return 0;
}