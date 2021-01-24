/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	//��ϣ��ķ���
	vector<vector<int> > threeSum(vector<int> &nums)
	{
		if (nums.size() < 3)
			return{}; //Ҫ���ϣ���Ȼ�δ���
		sort(nums.begin(), nums.end());
		unordered_multimap<int, int> map;
		for (int i = 0; i < nums.size(); ++i)
			map.insert({ nums[i],i });
		vector<vector<int> > res;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			for (int i1 = i + 1; i1 < nums.size() - 1; ++i1)
			{
				int aim = -nums[i] - nums[i1];
				if (map.find(aim) == map.end())
					continue;
				int cnt = map.count(aim);
				auto it = map.find(aim);
				for (int j = 0; j < cnt; ++j)
				{
					if (it->second > i && it->second > i1)
					{
						vector<int> tmp = { nums[i],nums[i1],aim };
						if (find(res.begin(), res.end(), tmp) == res.end())
							res.push_back(tmp);
						break; //ֻ���һ�ξ����ˣ�������Ҳ����ȵ�������
					}
					++it;
				}
			}
		}
		return res;
	}



	//�̶�һ������Ȼ��˫ָ��ķ���,��������һЩ
	vector<vector<int> > threeSum1(vector<int> &nums)
	{
		if (nums.size() < 3)
			return{}; //Ҫ���ϣ���Ȼ��ʱ��û�㶮���OJ
		std::sort(nums.begin(), nums.end());
		vector<vector<int> > res;
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
				if (tmpSum < 0)
				{
					while (left < right && nums[left] == nums[left + 1])
						++left; //ȥ���ظ�,ʱ���нϴ��Ż�
					++left;
				}
				else if (tmpSum > 0)
				{
					while (right > left && nums[right] == nums[right - 1])
						--right;
					--right;
				}
				else
				{
					vector<int> tmp = { nums[i],nums[left],nums[right] };
					if (find(res.begin(), res.end(), tmp) == res.end())
						res.push_back(tmp);
					while (left < right && nums[left] == nums[left + 1])
						++left; //ȥ���ظ�,ʱ���нϴ��Ż�
					while (right > left && nums[right] == nums[right - 1])
						--right;
					--right; //��ȵ�ʱ�����Ҷ��ƶ�
					++left;
				}
			}
		}
		return res;
	}


};

int main()
{
	Solution s;
	vector<int> nums = { -1,0,-2,2,-1,-4 };
	auto res = s.threeSum(nums);


	nums = { -1,0,-1,-4 };
	res = s.threeSum(nums);

	nums = { 0,0,0,0 };
	res = s.threeSum(nums);

	return 0;
}