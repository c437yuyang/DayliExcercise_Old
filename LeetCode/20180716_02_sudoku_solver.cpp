#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <YXPUtility>

using namespace std;


/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character'.'.

You may assume that there will be only one unique solution.



玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个粗线宫（3*3）内的数字均含1-9，不重复。

一开始题意都理解错了,一定是9x9并且除了行和列不能出现重复的，九宫格也不能出现。。

*/
//11.17

class Solution
{
public:
	void solveSudoku(vector<vector<char> > &board)
	{
		int n = board.size();
		if (board.empty() || n == 0)
			return;
		//solve(board);
		dfs(board, 0);
	}
	
	//牛客看到的,迭代版本，其实还是递归的
	//就是遍历每个格子，找合适的
	bool solve(vector<vector<char> > &board)
	{
		int n = board.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] == '.')
				{
					for (char c = '1'; c <= '9'; c++)
						if (isValid(board, i, j, c))
						{
							board[i][j] = c;
							if (solve(board)) //虽然递归里面套了循环，但是
								return true;
							else //如果不符，设置回来
								board[i][j] = '.';
						}
					return false;
				}
		return true;
	}

	//我改的dfs版本
	bool dfs(vector<vector<char>> &board,int idx) 
	{
		if (idx == board.size()*board.size())
			return true;
		int row = idx / board.size();
		int col = idx % board.size();
		if (board[row][col] != '.')
			return dfs(board, idx + 1);
		else
		{
			for (char ch = '1'; ch <= '9'; ++ch)
			{
				if (isValid(board, row, col, ch)) 
				{
					board[row][col] = ch;
					if (dfs(board, idx + 1)) 
						return true;
					else 
						board[row][col] = '.';
				}
			}
			return false;
		}
	}

	//检查同行同列以及九宫格有没有一样的
	bool isValid(vector<vector<char> > board, int row, int col, char num)
	{
		int n = board.size();
		for (int i = 0; i < n; i++)
		{
			if (board[i][col] == num || //所在列
				board[row][i] == num) //所在行
				return false;
			//3*row/3 是确定九宫格的左上角的rowIdx,col同理
			//然后在这个圈内，再以i为当前idx,3和3为高宽，确定自坐标就行了
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) //所在九宫格
				return false;
		}
		return true;
	}
};




int main()
{
	Solution s;

	vector<string> mat1 = {
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...8.3.2.",
		"........6",
		"...2759.."
	};

	vector<string> res1 = { "519748632",
		"783652419",
		"426139875",
		"357986241",
		"264317598",
		"198524367",
		"975863124",
		"832491756",
		"641275983" };




	return 0;
}