/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return[1,2,3,6,9,8,7,4,5].


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return{};
		std::vector<int > res;
		int lt_row = 0, lt_col = 0;
		int rb_row = matrix.size() - 1, rb_col = matrix[0].size() - 1;
		while (lt_row <= rb_row && lt_col <= rb_col)
		{
			if (lt_row == rb_row) //因为这里是正方形，其实只有lt_row==rb_row&&lt_col==rb_col的这种情况
			{
				for (int i = lt_col; i <= rb_col; ++i)
					res.push_back(matrix[lt_row][i]);
			}
			else if (lt_col == rb_col)
			{
				for (int i = lt_row; i <= rb_row; ++i)
					res.push_back(matrix[i][lt_col]);
			}
			else
			{
				int cur_row = lt_row, cur_col = lt_col;
				while (cur_col < rb_col)
					res.push_back(matrix[cur_row][cur_col++]);
				while (cur_row < rb_row)
					res.push_back(matrix[cur_row++][cur_col]);
				while (cur_col > lt_col)
					res.push_back(matrix[cur_row][cur_col--]);
				while (cur_row > lt_row)
					res.push_back(matrix[cur_row--][cur_col]);
			}
			--rb_row; --rb_col;
			++lt_row; ++lt_col;
		}
		return res;
	}
};


int main()
{
	std::vector<std::vector<int>> v = { {1,2,3},{4,5,6},{7,8,9} };
	auto var = Solution().spiralOrder(v);
	return 0;
}