/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example,
If S =[1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

*/

#include <YXPUtility>
using namespace yxp_utility;
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
  public:
	vector<vector<int>> subsetsWithDup(vector<int> &S)
	{
		if (S.empty())
			return {};
		vector<vector<int>> res;
		vector<int> curRes;
		sort(S.begin(), S.end()); //OJ的原因必须先排序
		dfs(S, 0, curRes, res);
		std::sort(res.begin(), res.end()); //OJ的原因必须先排序
		return res;
	}

	void dfs(vector<int> &nums, int i, vector<int> &curRes, vector<vector<int>> &res)
	{
		if (i == nums.size())
		{
			if (!checkContains(res, curRes))
				res.push_back(curRes);
			return;
		}

		dfs(nums, i + 1, curRes, res);
		curRes.push_back(nums[i]);
		dfs(nums, i + 1, curRes, res);
		curRes.pop_back();
	}

	//比较其实可以先建立一个set<vector<int>>,比hashset方便，不用自己重写hash函数，set就是直接用的operator==
	bool checkContains(vector<vector<int>> &res, vector<int> &cur)
	{
		for (size_t i = 0; i < res.size(); ++i)
			if (res[i] == cur)
				return true;
		return false;
	}
};

int main()
{
	auto v = Solution().subsetsWithDup(std::vector<int>{1, 2, 2});

	return 0;
}