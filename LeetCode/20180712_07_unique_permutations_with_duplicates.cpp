/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2]have the following unique permutations:
[1,1,2],[1,2,1], and[2,1,1].
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <set>
using namespace std;
class Solution
{
public:
	vector<vector<int> > permutations(vector<int> &num)
	{
		std::vector<std::vector<int>> res;
		std::set<std::vector<int>> set;
		permutationProcess(num, 0, res, set);
		return res;
	}

	void permutationProcess(std::vector<int>&nums, int i,
		std::vector<std::vector<int>> &res, std::set<std::vector<int>>& set)
	{
		if (i == nums.size() - 1)
		{
			std::vector<int> curRes(nums.begin(), nums.end());
			if (set.find(curRes) == set.end())
				res.push_back(curRes);
			set.insert(curRes);
		}
		else
		{
			for (size_t j = i; j < nums.size(); ++j)
			{
				keepOrderSwap1(nums, i, j);
				permutationProcess(nums, i + 1, res, set);
				keepOrderSwap2(nums, i, j);
			}
		}
	}

	template<class T>
	void keepOrderSwap1(std::vector<T>&arr, size_t i, size_t j)
	{
		char tmp = arr[j];
		for (size_t i1 = j; i1 > i; --i1)
			arr[i1] = arr[i1 - 1];
		arr[i] = tmp;
	}

	//从后往前移动
	template<class T>
	void keepOrderSwap2(std::vector<T>&arr, size_t i, size_t j)
	{
		char tmp = arr[i];
		for (size_t i1 = i; i1 < j; ++i1)
			arr[i1] = arr[i1 + 1];
		arr[j] = tmp;
	}

};

int main()
{
	std::vector<int> v = { 1,1,2 };
	Solution s;
	auto res = s.permutations(v);

	return 0;
}