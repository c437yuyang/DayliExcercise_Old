/*
小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。 例如： 如果{2,1,2,7}是你有的一系列数，小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，他说的数字是6，那么你没有办法拼凑出和为6 现在小易给你n个数，让你找出无法从n个数中选取部分求和的数字中的最小数（从1开始）。
输入描述:
输入第一行为数字个数n (n ≤ 20)
第二行为n个数xi (1 ≤ xi ≤ 100000)
输出描述:
输出最小不能由n个数选取求和组成的数
示例1
输入
3
5 1 2
输出
4
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

void make_sum(vector<int>& nums, int i, int cursum, set<int> &s)
{
	if ((unsigned long)i == nums.size())
	{
		return;
	}

	s.insert(cursum + nums[i]);
	s.insert(cursum);
	make_sum(nums, i + 1, cursum + nums[i], s);
	make_sum(nums, i + 1, cursum, s);
}

int solve(vector<int>& nums)
{
	set<int> sum_set;
	make_sum(nums, 0, 0, sum_set);
	const int max = *(--sum_set.end());
	for (int i = 0; i < max; ++i)
	{
		if (sum_set.find(i) == sum_set.end())
			return i;
	}
	return max + 1;
}


int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	nums.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int tmp = 0;
		cin >> tmp;
		nums.push_back(tmp);
	}
	cout << solve(nums);
}