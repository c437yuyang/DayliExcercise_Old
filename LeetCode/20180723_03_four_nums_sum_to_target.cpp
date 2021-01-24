/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
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

	vector<vector<int> > fourSum(vector<int> &num, int target)
	{
		vector<vector<int>> res;
		int len = num.size();
		sort(num.begin(), num.end());
		for (int i = 0; i < len - 3; ++i)
		{
			for (int i1 = i + 1; i1 < len - 2; ++i1)
			{
				for (int i2 = i1 + 1; i2 < len - 1; ++i2)
				{
					for (int i3 = i2 + 1; i3 < len; ++i3)
					{
						if (num[i] + num[i1] + num[i2] + num[i3] == target)
						{
							vector<int> tmp = { num[i],num[i1],num[i2],num[i3] };
							if (find(res.begin(), res.end(), tmp) == res.end())
							{
								res.push_back(tmp);
							}
						}
					}
				}
			}
		}
		std::sort(res.begin(), res.end());
		return res;

	}

	//自己的dfs版本，过不了，超时
	vector<vector<int> > fourSum1(vector<int> &num, int target)
	{
		vector<vector<int>>res;
		vector<int> curRes;
		std::sort(num.begin(), num.end());
		dfs(num, 0, target, 0, curRes, res);
		std::sort(res.begin(), res.end());
		return res;
	}

	void dfs(vector<int>&nums, int i, int target, int curSum, vector<int>& curRes, vector<vector<int>>&res)
	{
		if (curRes.size() == 4 && curSum == target)
		{
			if (std::find(res.begin(), res.end(), curRes) == res.end())
				res.push_back(curRes);
			return;
		}
		if (curRes.size() == 4)
			return;

		if (i >= nums.size())
			return;

		if (nums.size() - i + curRes.size() < 4)
			return;

		dfs(nums, i + 1, target, curSum, curRes, res);
		curRes.push_back(nums[i]);
		curSum += nums[i];
		dfs(nums, i + 1, target, curSum, curRes, res);
		curRes.pop_back();
		curSum -= nums[i];
	}


	//牛客看到的，双指针版本，其实复杂度和第一种方法直接遍历没啥差了，就只在处理相同元素的时候，避免了排序的代价
	//先排序，再转化为twoSum问题，然后定义两个指针，采用左右逼近的方法去解决。
	vector<vector<int> > fourSum2(vector<int> &num, int target)
	{
		vector<vector<int>> res;
		if (num.size() < 4) return res;

		sort(num.begin(), num.end()); //将原数组排序
		for (int i = 0; i < num.size(); i++)
		{
			int target_3 = target - num[i]; //转化为threeSum问题
			for (int j = i + 1; j < num.size(); j++)
			{
				int target_2 = target_3 - num[j];  //进一步转化为twoSum问题

													//采用双指针，left和right分别初始化为指向j的下一个元素和数组的最后一个元素
				int left = j + 1;
				int right = num.size() - 1;
				while (left < right)  //左右逼近
				{
					if (num[left] + num[right] > target_2) right--;
					else if (num[left] + num[right] < target_2) left++;
					else
					{
						vector<int> tmp(4);
						tmp[0] = num[i];
						tmp[1] = num[j];
						tmp[2] = num[left];
						tmp[3] = num[right];
						res.push_back(tmp);

						//处理元素4重复问题
						while (num[right] == tmp[3])  right--;
						//处理元素3重复问题
						while (num[left] == tmp[2])  left++;
					}
				}
				//处理元素2重复问题
				while (j + 1 < num.size() && num[j + 1] == num[j])  j++;
			}
			//处理元素1重复问题
			while (i + 1 < num.size() && num[i + 1] == num[i])  i++;
		}
		return res;
	}



};

int main()
{
	Solution s;
	vector<int> nums = { 1,0,-1,0,-2,2 };
	auto res = s.fourSum(nums, 0);



	return 0;
}