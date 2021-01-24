/*
小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。

并且小Q对于能否被3整除这个性质很感兴趣。

小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。


输入描述:
输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。


输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。

输入例子1:
2 5

输出例子1:
3

例子说明1:
12, 123, 1234, 12345...
其中12, 123, 12345能被3整除。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

//我的做法，就是单纯的累加起来
void solve1(int L, int R)
{
	int res = 0;
	int curNum = 0;
	long long curSum = 0;
	for (int i = 0; i < L; ++i)
	{
		++curNum;
		curSum += curNum;
	}

	for (int i = L; i <= R; ++i)
	{
		if (curSum % 3 == 0)
			++res;
		++curNum;
		curSum += curNum;
	}
	std::cout << res << std::endl;
}

//网上看到的，其实就是一个等差数列
void solve(int L, int R)
{
	long long sum = 0;
	for (long long i = L; i <= R; i++)
		if (((i + 1)*i / 2) % 3 == 0)
			sum++;
	std::cout << sum << std::endl;
}

int main()
{
	int L, R;
	while (std::cin >> L >> R) //这样写可以避免输入空测试用例的OJ
		solve(L, R);
	return 0;
}