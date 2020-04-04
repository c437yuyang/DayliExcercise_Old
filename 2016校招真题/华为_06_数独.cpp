#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
//#include <YXPUtility>
using namespace std;

//83% 应该是对的，题目给的用例有多解

vector<vector<char>> res;
bool finded = false;

//检查当前行，当前列是否合法
bool checkValid(vector<vector<char>> &board, int row, int col) {
	for (int i = 0; i < 9; ++i) {
		if (i == row)
			continue;
		if (board[row][col] == board[i][col])
			return false;
	}

	for (int j = 0; j < 9; ++j) {
		if (j == col)
			continue;
		if (board[row][col] == board[row][j])
			return false;
	}

	//九宫格的下标
	int matIdx = row / 3 * 3 + col / 3;
	//每个九宫格9个点
	for (int idx = 0; idx < 9; ++idx) {
		int rowIdx = matIdx / 3 * 3 + idx / 3;
		int colIdx = matIdx % 3 * 3 + idx % 3;
		if (rowIdx == row && colIdx == col)
			continue;
		if (board[rowIdx][colIdx] == board[row][col])
			return false;
	}
	return true;
}


void dfs(vector<vector<char>> &board, int idx) {
	if (finded)
		return;

	int row = idx / 9; int col = idx % 9;

	if (idx == 81) {
		res = board;
		finded = true;
		return;
	}

	if (idx > 81)
		return;

	if (board[row][col] != '0')
		dfs(board, idx + 1);
	else {
		for (char c = '1'; c <= '9'; ++c) {
			board[row][col] = c;
			if (checkValid(board, row, col)) {
				dfs(board, idx + 1);
			}
			board[row][col] = '0';
		}
	}

}


void solveSudoku(vector<vector<char> > &board) {

	dfs(board, 0);
	board = res;
}




int main() {

	vector<vector<char>> board(9, vector<char>(9, '0'));

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
		}
	}




	solveSudoku(board);

	//yxp_utility::ArrayHelper::printMatrix(board);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << board[i][j];
			if (j != 8)
				cout << " ";
		}
		if (i != 8)
			cout << endl;
	}


	return 0;
}