/*
Given an integer n, generate a square matrix filled with elements from 1 to n 2 in spiral order.

For example,
Given n =3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
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
	vector<vector<int> > generateMatrix(int n)
	{
		if (n == 0)
			return{};
		if (n == 1)
			return std::vector<std::vector<int> >(1, std::vector<int>(1, 1));
		std::vector<std::vector<int> > res(n, std::vector<int>(n, 1));
		int lt_row = 0, lt_col = 0;
		int rb_row = n - 1, rb_col = n - 1;
		int idx = 1;
		while (lt_row <= rb_row && lt_col <= rb_col)
		{
			if (lt_row == rb_row) //因为这里是正方形，其实只有lt_row==rb_row&&lt_col==rb_col的这种情况
			{
				for (int i = lt_col; i <= rb_col; ++i)
					res[lt_row][i] = idx++;
			}
			else if (lt_col == rb_col)
			{
				for (int i = lt_row; i <= rb_row; ++i)
					res[i][lt_col] = idx++;
			}
			else
			{
				int cur_row = lt_row, cur_col = lt_col;
				while (cur_col < rb_col)
					res[cur_row][cur_col++] = idx++;
				while (cur_row < rb_row)
					res[cur_row++][cur_col] = idx++;
				while (cur_col > lt_col)
					res[cur_row][cur_col--] = idx++;
				while (cur_row > lt_row)
					res[cur_row--][cur_col] = idx++;

			}
			--rb_row; --rb_col;
			++lt_row; ++lt_col;
		}

		return res;
	}
};


int main()
{
	auto var = Solution().generateMatrix(3);
	return 0;
}