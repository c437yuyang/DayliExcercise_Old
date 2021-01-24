#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word ="ABCCED", -> returns true,
word ="SEE", -> returns true,
word ="ABCB", -> returns false.
*/

//16.50
class Solution
{
public:
	bool exist(vector<vector<char> > &board, string word)
	{
		if (word == "")
			return false;
		if (board.size() == 0)
			return false;
		if (board[0].size() == 0)
			return false;

		bool res = false;
		std::vector<std::vector<bool>> checked(board.size(), std::vector<bool>(board[0].size(), false));
		for (size_t i = 0; i < board.size(); ++i)
			for (size_t j = 0; j < board[0].size(); ++j)
				if (board[i][j] == word[0])
				{
					res = res || dfs(board, checked, i, j, word);
					if (res)
						return true;
				}
		return false;
	}

	bool dfs(vector<vector<char>> &board, vector<vector<bool>>& checked, int  i, int j, const std::string &word)
	{
		if (word.length() == 1) //因为是检查了相等才进来的
			return true;
		checked[i][j] = true;
		if (i - 1 >= 0 && !checked[i - 1][j] && board[i - 1][j] == word[1])
		{
			if (dfs(board, checked, i - 1, j, word.substr(1)))
				return true;
		}
		if (i + 1 < board.size() && !checked[i + 1][j] && board[i + 1][j] == word[1])
		{
			if (dfs(board, checked, i + 1, j, word.substr(1)))
				return true;
		}
		if (j + 1 < board[0].size() && !checked[i][j + 1] && board[i][j + 1] == word[1])
		{
			if (dfs(board, checked, i, j + 1, word.substr(1)))
				return true;
		}
		if (j - 1 >= 0 && !checked[i][j - 1] && board[i][j - 1] == word[1])
		{
			if (dfs(board, checked, i, j - 1, word.substr(1)))
				return true;
		}
		checked[i][j] = false; //传引用的话，这里要改回来!!!
		return false;
	}
};

int main()
{
	std::vector<std::vector<char>> board;
	std::vector<char> v = { 'A','B','C','E' };
	board.push_back(v);
	v = { 'S','F','C','S' };
	board.push_back(v);
	v = { 'A','D','E','E' };
	board.push_back(v);

	Solution s;
	bool b = s.exist(board, "ABCCED");
	b = s.exist(board, "SEE");
	b = s.exist(board, "ABCB");

	return 0;
}