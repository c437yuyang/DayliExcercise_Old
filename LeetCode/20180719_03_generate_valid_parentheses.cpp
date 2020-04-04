/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
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
	std::vector<std::string> generateParenthesis(int n)
	{
		if (n == 0)
			return{};
		if (n == 1)
			return{ "()" };

		std::string curRes = "(";
		std::vector<std::string> res;
		dfs(curRes, 1, 0, res, n);
		return res;

	}

	//关键：当前位置左括号不少于右括号
	void dfs(std::string &curRes, int leftNum, int rightNum, std::vector<std::string>& res, int n)
	{
		if (leftNum < rightNum)
			return;
		if (leftNum > n)
			return;
		if (leftNum == rightNum && leftNum + rightNum == n * 2)
		{
			res.push_back(curRes);
			return;
		}

		curRes.push_back('(');
		dfs(curRes, leftNum + 1, rightNum, res, n);
		curRes.pop_back();

		curRes.push_back(')');
		dfs(curRes, leftNum, rightNum + 1, res, n);
		curRes.pop_back();
	}
};

int main()
{
	Solution s;
	auto v = s.generateParenthesis(3);
	return 0;
}