#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

using namespace std;
void rotate(vector<vector<int>>& matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = matrix.size() - 1;
	int dC = matrix[0].size() - 1;
	while (tR < dR)
	{
		rotateEdge(matrix, tR++, tC++, dR--, dC--);
	}
}

void rotateEdge(vector<vector<int>>& m, int tR, int tC, int dR, int dC)
{
	int times = dC - tC;
	int tmp = 0;
	for (int i = 0; i != times; i++)
	{
		tmp = m[tR][tC + i];
		m[tR][tC + i] = m[dR - i][tC]; //第一个数，是等于和它同列的最下面的数(指定了圈的)
		m[dR - i][tC] = m[dR][dC - i]; //然后这个数又等于和它同行的最右边的数
		m[dR][dC - i] = m[tR + i][dC]; //然后这个数又等于和它同列的，最上面的数
		m[tR + i][dC] = tmp; //最后这个数又等于和它同行，最左边的数
	}
}


//牛客看到的更厉害
//做两次翻转，先沿右上-左下的对角线翻转，再沿水平中线上下翻转
class Solution
{
public:
	void rotate(vector<vector<int> > &matrix)
	{
		//对角线翻转
		const int n = matrix.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - i; j++)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
};


int main()
{


	return 0;
}