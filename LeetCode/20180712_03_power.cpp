#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

//不能过
class Solution
{
  public:
	double pow(double x, int n)
	{
		if (n == 0)
			return 1.0;
		if (n == -1 && x == 0.0)
			return std::numeric_limits<double>::max();
		bool neg = n < 0 ? true : false;
		n = abs(n);
		return neg ? 1.0 / powProcess(x, n) : powProcess(x, n);
	}

	//正整数的幂次
	double powProcess(double x, int n)
	{
		if (n == 1) //牛客的OJ这里必须加上if(n==0) return 1.0才能过，
			return x;
		if (n == 2)
			return x * x;

		if (n & 1) //奇数次
		{
			double tmp = powProcess(x, (n - 1) / 2);
			return x * tmp * tmp;
		}
		double tmp = powProcess(x, n / 2);
		return tmp * tmp;
	}
};

//能过的版本
class Solution
{
  public:
	double pow(double x, int n)
	{
		//求 x^n = x^(n/2) + x^(n/2) + x^(n%2)
		if (n < 0)
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}

  private:
	double power(double x, int n)
	{
		if (n == 0)
			return 1; //牛客的OJ这里必须加上if(n==0)才能过，
		double tmp = power(x, n / 2);
		if (n % 2 == 0)
			return tmp * tmp;
		else
			return tmp * tmp * x;
	}
};

int main()
{
	double x = Solution().pow(5, 30);
	x = Solution().pow(5, 5);

	return 0;
}