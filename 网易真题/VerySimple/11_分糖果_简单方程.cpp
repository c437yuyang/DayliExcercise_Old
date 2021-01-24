/*
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
输入描述:
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在-30到30之间(闭区间)。
输出描述:
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例1
输入
1 -2 3 4
输出
2 1 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;
bool isInteger(double x);
void solve(int n1, int n2, int n3, int n4)
{
	double A = (n1 + n3) / 2.0;
	if (!isInteger(A))
	{
		cout << "No" << endl;
		return;
	}
	double B1 = A - n1;

	double B2 = (n2 + n4) / 2.0;
	if (!isInteger(B2) || B1 != B2)
	{
		cout << "No" << endl;
		return;
	}
	double C = n4 - B2;

	cout << (int)A << " " << (int)B2 << " " << (int)C << endl;

}

bool isInteger(double x)
{
	if (x - floor(x) == 0.0)
		return true;
	return false;
}


int main()
{
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;
	solve(n1, n2, n3, n4);

	return 0;
}