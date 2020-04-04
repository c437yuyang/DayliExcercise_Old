/*
Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
			return std::numeric_limits<long long>::max();
		if (dividend == 0)
			return 0;
		bool neg = false;
		if ((dividend > 0 && divisor < 0)
			|| (dividend < 0 && divisor>0))
		{
			neg = true;
		}

		long long res = process(labs(dividend), labs(divisor)); //一定要转换先，不然会出现溢出值，然后就会超时
		if (neg && -res < std::numeric_limits<int>::min())
			return std::numeric_limits<int>::min();
		if (!neg&& res > std::numeric_limits<int>::max())
			return std::numeric_limits<int>::max();
		return neg ? -res : res;
	}

	long long process(long long dividend, long long divisor)
	{
		if (dividend < divisor)
			return 0;
		long long res = 1;
		long long sum = divisor;
		while ((sum << 1) <= dividend) //就是两倍两倍的翻，看啥时候停，停了把余下的再递归求解加上
		{
			sum <<= 1;
			res <<= 1;
		}
		return res + process((dividend - sum), divisor);
	}

};

//以及加减乘的实现如下:
int add(int a, int b)
{
	int sum = a;
	int carry = b;// 表示进位,一开始就是把b当做进位来看
	while (carry != 0) //直到没有进位了为止
	{
		sum = a ^ b; //直接相加
		carry = (a & b) << 1; //进位，会产生进位的就是都为1的位置，进位的话就是向上一位进位
		a = sum;
		b = carry;
	}
	return sum;
}

int minus(int a, int b)
{
	// b为减数,先变成负数
	b = add(~b, 1);
	return add(a, b);
}

int mult(int a, int b)
{
	int res = 0;
	while (b != 0)
	{
		res += b & (1) ? a : 0; //取b最右一位
		a <<= 1;
		b = ((unsigned int)b) >> 1; //C++做无符号数移位要先转换成无符号数，这样右移左边补0而不是符号位
	}
	return res;
}

int main()
{
	Solution s;
	assert(s.divide(0, 1) == 0);
	assert(s.divide(9, 3) == 3);
	assert(s.divide(9, 2) == 4);
	assert(s.divide(9, 5) == 1);
	assert(s.divide(9, 6) == 1);
	assert(s.divide(9, 10) == 0);

	assert(add(5, 3) == 8);
	assert(add(0, 3) == 3);
	assert(add(11, 3) == 14);
	assert(add(-1, 3) == 2);


	assert(mult(5, 3) == 15);
	assert(mult(5, -3) == -15);

	return 0;
}



