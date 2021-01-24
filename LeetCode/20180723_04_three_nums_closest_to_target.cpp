/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

class Solution
{
public:
	//固定一个数，然后双指针的方法
	int threeSumClosest(vector<int> &nums, int target)
	{
		std::sort(nums.begin(), nums.end());
		int minDiff = std::numeric_limits<int>::max();
		int res = 0;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int sum = nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int tmpSum = sum;
				tmpSum += nums[left];
				tmpSum += nums[right];

				if (abs(target - tmpSum) < minDiff)
				{
					res = tmpSum;
					minDiff = abs(target - tmpSum);
				}

				if (tmpSum < target)
					++left;
				else if (tmpSum > target)
					--right;
				else //==就是最小距离了 直接break
					return tmpSum;
			}

		}
		return res;
	}

	//直接遍历，其实差不多
	int threeSumClosest1(vector<int> &num, int target)
	{
		int len = num.size();
		int minDiff = std::numeric_limits<int>::max();
		int res = 0;
		for (int i = 0; i < len - 2; ++i)
			for (int i1 = i + 1; i1 < len - 1; ++i1)
				for (int i2 = i1 + 1; i2 < len; ++i2)
				{
					int sum = num[i] + num[i1] + num[i2];

					if (abs(target - sum) < minDiff)
					{
						res = sum;
						minDiff = abs(target - sum);
						if (minDiff == 0)
							return res;
					}
				}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { -1,2,1,-4 };
	auto res = s.threeSumClosest(nums, 1);

	nums = { 0,1,2 };
	res = s.threeSumClosest(nums, 3);

	return 0;
}