/*
尽管是一个CS专业的学生，小B的数学基础很好并对数值计算有着特别的兴趣，喜欢用计算机程序来解决数学问题，现在，她正在玩一个数值变换的游戏。她发现计算机中经常用不同的进制表示一个数，如十进制数123表达为16进制时只包含两位数7、11（B），用八进制表示为三位数1、7、3，按不同进制表达时，各个位数的和也不同，如上述例子中十六进制和八进制中各位数的和分别是18和11,。 小B感兴趣的是，一个数A如果按2到A-1进制表达时，各个位数之和的均值是多少？她希望你能帮她解决这个问题？ 所有的计算均基于十进制进行，结果也用十进制表示为不可约简的分数形式。
输入描述:
输入中有多组测试数据，每组测试数据为一个整数A(1 ≤ A ≤ 5000).
输出描述:
对每组测试数据，在单独的行中以X/Y的形式输出结果。
示例1
输入

5
3
输出

7/3
2/1
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

long long calcDecimalSum(int num, int decimal) {
	long long res = 0;
	while (num != 0) { //只是计算和，不管顺序
		res += num%decimal;
		num /= decimal;
	}
	return res;
}

long long gcd(long long m, long long n) {
	//return n == 0 ? m : gcd(n, m % n);
	//非递归版本
	while (m%n != 0) {
		int c = m%n;
		m = n;
		n = c;
	}
	return n;
}


std::string simpifyFraction(long long m, long long n) {
	if (m%n == 0)
		return to_string(m / n) + "/1";

	//找最大公约数,笨办法:
	//for (long long i = sqrt(n); i >= 2; --i) {
	//	if ((n%i == 0 && m%i == 0)) {
	//		m /= i; n /= i;
	//	}
	//	if ((n % (n / i) == 0 && m % (n / i) == 0)) {
	//		m /= (n / i);
	//		n /= (n / i);
	//	}
	//}

	long long g = gcd(m, n);

	return to_string(m / g) + "/" + to_string(n / g);
}

void solve(int num) {

	long long res = 0;
	for (int i = 2; i <= num - 1; ++i) {
		res += calcDecimalSum(num, i);
	}
	cout << simpifyFraction(res, num - 2) << endl;
}


int main() {

	int m;
	while (cin >> m) {
		solve(m);
	}
	return 0;
}

