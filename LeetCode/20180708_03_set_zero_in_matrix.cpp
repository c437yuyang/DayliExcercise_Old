/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(m n) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

class Solution
{
public:
	void setZeroes(std::vector<std::vector<int> > &matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		//判断第一行和第一列是否有0
		bool firstColZero = false, firstRowZero = false;
		for (int i = 0; i < m; ++i)
			if (matrix[i][0] == 0)
			{
				firstColZero = true;
				break;
			}

		for (int i = 0; i < n; ++i)
			if (matrix[0][i] == 0)
			{
				firstRowZero = true;
				break;
			}

		//用第一行和第一列做记录，如果任何一个位置出现0，那么所在行所在列就归为0
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		//根据记录进行恢复
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
		if (firstColZero)
			for (int i = 0; i < m; ++i)
				matrix[i][0] = 0;
		if (firstRowZero)
			for (int i = 0; i < n; ++i)
				matrix[0][i] = 0;
	}
};

