/*
Implementint sqrt(int x).
Compute and return the square root of x.
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
	int sqrt(int x)
	{
		//思路用二分法
		if (x < 2)
			return x;

		int left = 1, right = x / 2; //sqrt最大可能返回的也就是x / 2
		int lastLess;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (x / mid > mid) //mid*mid <x
			{
				left = mid + 1;
				lastLess = mid;
			}
			else if (x / mid < mid)
				right = mid - 1;
			else
				return mid;
		}
		return lastLess;
	}
};

int main()
{
	Solution s;
	for (int i = 0; i <= 100; ++i)
	{
		printf("sqrt(%d) is: %d\n", i, s.sqrt(i));
	}

	return 0;
}