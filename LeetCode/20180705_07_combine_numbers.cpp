#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

//17.20
class Solution
{
public:
	vector<vector<int> > combine(int n, int k)
	{
		if (k == 0 || k > n)
			return{};
		std::vector<std::vector<int>> res;
		std::vector<int> curRes;
		dfs(1, n, k, curRes, res);
		return res;
	}

	void dfs(int i, int n, int k, std::vector<int> &curRes, std::vector<std::vector<int>> &res)
	{
		if (k == 0) //这个一定要放在i>n的判断的前面!!!
		{
			res.push_back(curRes);
			return;
		}
		if (i > n)
			return;

		curRes.push_back(i);
		dfs(i + 1, n, k - 1, curRes, res);
		curRes.pop_back();
		dfs(i + 1, n, k, curRes, res);
	}
};


int main()
{
	Solution s;
	auto v = s.combine(4, 1);
	 v = s.combine(4, 2);

	return 0;
}