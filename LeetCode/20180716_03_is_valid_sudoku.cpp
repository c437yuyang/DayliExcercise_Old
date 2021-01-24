/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character'.'.


*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
using namespace std;



class Solution
{
public:

    //另一种做法，其实这里直接用哈希表，就省去了检查是自己一个位置的操作了
    bool isValidSudoku(const vector<vector<char> > &board)
	{
		int n = board.size();
		if (board.empty() || n == 0 || n != 9)
			return false;
		for (int i = 0; i < n; ++i)
		{
			std::unordered_set<char> row;
			std::unordered_set<char> col;
			std::unordered_set<char> rect; //9宫格

			for (int j = 0; j < n; ++j)
			{
				char ch = board[i][j];
				//i当做rowIdx,j当做colIdx
				if (ch != '.' && row.find(ch) != row.end())
					return false;
				row.insert(ch);

				ch = board[j][i];
				//i当做colIdx,j当做rowIdx
				if (ch != '.' && col.find(ch) != col.end())
					return false;
				col.insert(ch);

				ch = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
				//i当做九宫格的坐标(一共9个),j当做九宫格内的坐标
				//i*3/n 就是第i个九宫格的左上角的rowIdx,i*3%n就是...的colIdx
				if (ch != '.' && rect.find(ch) != rect.end())
					return false;
				rect.insert(ch);
			}
		}
		return true;
	}


    //检查是不是合理的，其实就是直接检查当前是否符合条件就可以了
	bool isValidSudoku1(const vector<vector<char> > &board)
	{
		int n = board.size();
		if (board.empty() || n == 0 || n != 9)
			return false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) //对于每一个位置，判断是否合理
			{
				if (!isValid(board, i, j, board[i][j]))
					return false;
			}
		}
		return true;
	}

	//检查同行同列以及九宫格有没有一样的
	bool isValid(vector<vector<char> > board, int row, int col, char num)
	{
		if (num == '.') //直接true,但是这样有问题，其实还得在判断一下，最终这个棋盘里面，至少得有9个以上不是'.'的才行!
			return true;
		int n = board.size();
		for (int i = 0; i < n; i++)
		{
			if ((board[i][col] == num && i != row) || //所在列，排除自己
				(board[row][i] == num && i != col)) //所在行
				return false;
			
			//当前自己跳过
			if(3 * (row / 3) + i / 3 == row && 3 * (col / 3) + i % 3 == col)
				continue; 
			//3*row/3 是确定九宫格的左上角的rowIdx,col同理
			//然后在这个圈内，再以i为当前idx,3和3为高宽，确定自坐标就行了
			if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num  ) //所在九宫格
				return false;
		}
		return true;
	}
};

vector<char> stringToVec(const string&str)
{
	return vector<char>(str.begin(), str.end());
}

int main()
{
	vector<vector<char>> v =
	{
		stringToVec(".87654321"),
		stringToVec("2........"),
		stringToVec("3........"),
		stringToVec("4........"),
		stringToVec("5........"),
		stringToVec("6........"),
		stringToVec("7........"),
		stringToVec("8........"),
		stringToVec("9........")
	};

	Solution s;
	bool b = s.isValidSudoku(v);
	assert(b == true);
}
