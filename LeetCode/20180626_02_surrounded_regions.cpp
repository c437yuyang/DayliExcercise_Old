/*
Given a 2D board containing'X'and'O', capture all regions surrounded by'X'.

A region is captured by flipping all'O's into'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
class Solution
{
public:
	void solve(std::vector<std::vector<char>> &board)
	{
		if (board.size() == 0)
			return;

		size_t m = board.size();
		size_t n = board[0].size();
		//我的思路是，找所有跟边界相连的'O'
		std::vector<std::vector<bool>> traversed(m, std::vector<bool>(n, false));
		//用感染函数的方法
		//先找在四个边界上的然后进行感染
		for (size_t i = 0; i < m; ++i)
		{
			if (board[i][0] == 'O')
				inject(board, i, 0, traversed);

			if (board[i][n - 1] == 'O')
				inject(board, i, n - 1, traversed);
		}

		for (size_t j = 0; j < n; ++j)
		{
			if (board[0][j] == 'O')
				inject(board, 0, j, traversed);

			if (board[m - 1][j] == 'O')
				inject(board, m - 1, j, traversed);
		}

		//然后就看哪些是边界上的O
		for (size_t i = 0; i < m; ++i)
		{
			for (size_t j = 0; j < n; ++j)
			{
				if (board[i][j] != '*')
					board[i][j] = 'X'; //不是边界上的'O'全部置为'X'
				else
					board[i][j] = 'O';
			}
		}

	}

	//进了函数再感染
	void inject(std::vector<std::vector<char>> &board, size_t i, size_t j, std::vector<std::vector<bool>> &traversed)
	{
		if (traversed[i][j] || board[i][j] != 'O')
			return;

		traversed[i][j] = true;
		board[i][j] = '*'; //边界感染后的O全部变成其他符号
		if (i < board.size() - 1) //不用判断j的区间了，肯定符合
			inject(board, i + 1, j, traversed);
		if (j < board[0].size() - 1)
			inject(board, i, j + 1, traversed);
		if (i > 0)
			inject(board, i - 1, j, traversed);
		if (j > 0)
			inject(board, i, j - 1, traversed);
	}

};

int main()
{
	Solution s;

	std::vector<std::vector<char>> c;
	c.push_back({ 'X','X','X' ,'X' });
	c.push_back({ 'X','O','O' ,'X' });
	c.push_back({ 'X','X','O' ,'X' });
	c.push_back({ 'X','O','X' ,'X' });

	yxp_utility::ArrayHelper::printMatrix(c);

	s.solve(c);

	yxp_utility::ArrayHelper::printMatrix(c);

	return 0;
}