/*
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。例如:
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？
输入描述:
输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开。
输出描述:
输出rev(rev(x) + rev(y))的值
示例1
输入
复制
123 100
输出
复制
223
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int rev(int x);
int solve(int x, int y)
{
	return rev(rev(x) + rev(y));
}

int rev(int x)
{
	int res = 0;
	while (x != 0)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}

	return res;
}

int main()
{
	//cout << solve(123, 100) << endl;


	int x, y;
	cin >> x >> y;
	cout << solve(x, y) << endl;
	return 0;
}