/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where'Q'and'.'both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <set>
using namespace std;
class Solution
{
public:
	vector<vector<string> > res;
	vector<vector<string> > solveNQueens(int n)
	{
		if (n == 1)
			return{ {"Q"} };
		if (n < 4)
			return{};
		std::vector<int> colIdxs(n + 1, 0); //在每行的坐标
		std::set<int> colIdxSet; //初始全部都有(1-n)，然后每次移出去,用unordered_set更快，但是oj输出顺序是错的
		for (int i = 1; i <= n; ++i)
			colIdxSet.insert(i);
		dfs(1, n, colIdxs, colIdxSet);
		return res;
	}

	//i从1开始
	void dfs(int i, int n, std::vector<int> &colIdxs, std::set<int> colIdxSet)
	{
		if (i == n)
		{
			//只剩一个了
			colIdxs[i] = *colIdxSet.begin();
			if (checkLegal(colIdxs, i))
			{
				//执行输出
				res.push_back(getQueens(colIdxs));
			}
			return;
		}

		auto it = colIdxSet.begin();
		for (; it != colIdxSet.end();++it)
		{
			int tmpIdx = *it;
			colIdxs[i] = tmpIdx;
			auto tmpIdxSet = colIdxSet; //这里传引用暂时做不到
			tmpIdxSet.erase(tmpIdx);
			if (checkLegal(colIdxs, i))
				dfs(i + 1, n, colIdxs, tmpIdxSet);
			colIdxs[i] = 0;
		}

	}

	//当前到了第几行
	bool checkLegal(std::vector<int> &colIdxs, int n)
	{
		if (n == 1)
			return true;
		std::unordered_set<int> s;
		for (size_t i = 1; i <= n; ++i) //检查每一列是否满足
			s.insert(colIdxs[i]);
		if (s.size() != n)
			return false;

		//检查对角线是否满足
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j)
				if (i != j && abs(colIdxs[j] - colIdxs[i]) == abs(j - i))
					return false;

		return true;
	}

	std::vector<std::string> getQueens(std::vector<int> & queens)
	{
		std::vector<std::string> curRes;
		for (size_t i = 1; i < queens.size(); ++i)
		{
			std::string curLine = "";
			for (size_t j = 1; j < queens.size(); ++j)
			{
				if (j == queens[i])
					curLine += "Q";
				else curLine += ".";
			}
			curRes.push_back(curLine);
		}
		return curRes;
	}

};

int main()
{
	Solution s;
	auto v = s.solveNQueens(4);
	 v = s.solveNQueens(5);

	return 0;
}