/*
Given a set of candidate numbers ( C ) and a target number ( T ), find all unique combinations in C where the candidate numbers sums to T .

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a 1, a 2, … , a k) must be in non-descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set2,3,6,7and target7, 
A solution set is: 
[7]
[2, 2, 3]

这道题就是拿硬币，然后硬币随便用多少次，来凑成aim
不过输出不是方案的数目，而是怎么拿的方案,因此不能改成动态规划
*/

//这是我的做法
class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> curRes;
        sort(candidates.begin(), candidates.end());
		process(candidates, 0, target, curRes, res);
		return res;
	}

	void process(vector<int>&nums, int i, int target, vector<int> curRes, vector<vector<int>>&res)
	{;
		if (target == 0)
		{
			res.push_back(curRes);
			return;
		}
		if (i > nums.size() - 1 || target < 0)
			return;
		int maxNum = target / nums[i];
		for (int j = maxNum; j >=0; --j) //注意输出顺序，说白了就是要尽可能的把当前数多拿
		{
            auto tmpRes = curRes;
            for(int k=0;k<j;++k)
			    tmpRes.push_back(nums[i]);
			process(nums, i + 1, target - j*nums[i], tmpRes, res);
		}
	}
};