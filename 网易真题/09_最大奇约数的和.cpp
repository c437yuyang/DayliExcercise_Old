/*
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题： 定义函数f(x)为x最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3).......f(N)
例如： N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21
小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。
输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)
输出描述:
输出一个整数，即为f(1) + f(2) + f(3).......f(N)
示例1
输入
7
输出
21
*/

#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;

int maxOddFactor(int n)
{
	if (n & 1)
		return n;


	//不能这样找，复杂度太高了，只能一直除以2直到是奇数就是最大奇约数
	//int max = std::numeric_limits<int>::min();
	/*for (int i = sqrt(n); i >= 1; --i)
	{
		if (n % i == 0)
		{
			if (i & 1)
				max = std::max(max, i);
			else if ((n / i) & 1)
				max = std::max(max, n / i);
		}
	}*/

	while ((n & 1) ==0)
		n /= 2;
	return n;
}

//还是会超时
long long solve(int n)
{
	long long res = 0;
	//奇数部分相加
	if (n & 1)
		res += (n + 1)*(n + 1) / 4;
	else
		res += n * n / 4;

	for (int i = 2; i <= n; i+=2) //再计算偶数部分
		res += maxOddFactor(i);
	return res;
}

//这个的思路是:每次都计算当前的奇数的等差数列和
//比如:1....10 , 第一次就算1,3,5,7,9的和
//然后2 4 6 8 10分别会除以2，成为1 2 3 4 5
//再算1 3 5的和
//2 4->1 2 算1
//2->1 算1
long long solve1(long long n)  //注意这里要是ll才行，因为int的话，中间在执行运算的时候会还是int，就会溢出
{
	long long res = 0;
	while (n)
	{
		res += ((n + 1) / 2) * ((n + 1) / 2); //注意优先级，能够保证，奇数偶数都正确
		n /= 2;
	}
	return res;
}

int main()
{
	long long n;
	cin >> n;
	cout << solve1(n) << endl;

	return 0;
}