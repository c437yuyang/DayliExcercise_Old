/*
小易有一个圆心在坐标原点的圆，小易知道圆的半径的平方。小易认为在圆上的点而且横纵坐标都是整数的点是优雅的，小易现在想寻找一个算法计算出优雅的点的个数，请你来帮帮他。
例如：半径的平方如果为25
优雅的点就有：(+/-3, +/-4), (+/-4, +/-3), (0, +/-5) (+/-5, 0)，一共12个点。
输入描述:
输入为一个整数，即为圆半径的平方,范围在32位int范围内。
输出描述:
输出为一个整数，即为优雅的点的个数
示例1
输入
25
输出
12
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;

bool isInteger(double x)
{
	if (x - floor(x) == 0.0)
		return true;
	return false;
}

int solve(int radis2)
{
	double radis = sqrt(radis2);
	int res = 0; 
	if (isInteger(radis))
		res += 4;//(0,+-radis)(+-radis,0)
	
	for (int i = 1; i < radis; ++i)
	{
		double other = sqrt(radis2 - (int)pow(i, 2));
		if (isInteger(other))
			res += 4;
	}

	return res;
}

int main()
{
	int x;
	cin >> x;
	cout << solve(x) << endl;
	//cout << solve(5) << endl;
	return 0;
}