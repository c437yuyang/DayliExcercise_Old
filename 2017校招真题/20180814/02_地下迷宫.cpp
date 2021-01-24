/*
С������һ�첻С��������һ�������Թ�,С����ϣ�����Լ���ʣ������ֵP������������Թ���Ϊ���������,��������һ��n*m�ĸ����Թ�,�Թ�ÿ��λ��Ϊ0����1,0�������λ�����ϰ���,С���ܴﵽ�������λ��;1����С���ܿ��Դﵽ��λ�á�С���ܳ�ʼ��(0,0)λ��,�����Թ��ĳ�����(0,m-1)(��֤������λ�ö���1,���ұ�֤һ������㵽�յ�ɴ��·��),С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ,������һ����λ������Ҫ����3����λ������ֵ,�����ƶ�����������ֵ,��С���ܵ�����ֵ����0��ʱ��û�е������,С���ܽ��޷������Թ���������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0,m-1)λ��)��
��������:
�������n+1��:
��һ��Ϊ��������n,m(3 <= m,n <= 10),P(1 <= P <= 100)
��������n��:
ÿ��m��0����1,�Կո�ָ�
�������:
����������Թ�,�����һ������������С��·��,�����ʽ��������ʾ;������������Թ�,�����"Can not escape!"�� �������ݱ�֤��Ψһ
ʾ��1
����
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
���
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
struct Point
{
	int row; int col;
	Point(int r, int c) :row(r), col(c) {}
};

//15.32 AC
void dfs(vector < vector<int>> &mat, int restenergy, vector<vector<bool>> &checked,
	int currow, int curcol, vector<Point> &curres, vector<Point> &res, int &maxrestenergy);

void solve(vector<vector<int>> &mat, int energy)
{
	vector<Point> res, curRes = { {0,0} };
	vector<vector<bool>> checked(mat.size(), vector<bool>(mat[0].size(), false));
	int max = std::numeric_limits<int>::min();
	dfs(mat, energy, checked, 0, 0, curRes, res, max);


	if (max == std::numeric_limits<int>::min())
	{
		cout << "Can not escape!" << endl;
		return;
	}

	for (int i = 0; i < res.size(); ++i)
	{
		cout << "[" << res[i].row << "," << res[i].col << "]";
		if (i != res.size() - 1)
			cout << ",";
	}


}


void dfs(vector < vector<int>> &mat, int restenergy, vector<vector<bool>> &checked,
	int currow, int curcol, vector<Point> &curres, vector<Point> &res, int &maxrestenergy)
{
	if (restenergy < 0)
		return;

	if (currow == 0 && curcol == mat[0].size() - 1)
	{
		if (restenergy > maxrestenergy)
		{
			res = curres;
			maxrestenergy = restenergy;
		}
		return;
	}

	checked[currow][curcol] = true;
	if (restenergy >= 1)
	{
		if (curcol < mat[0].size() - 1 && checked[currow][curcol + 1] == false && mat[currow][curcol + 1] == 1)
		{
			curres.push_back(Point(currow, curcol + 1));
			dfs(mat, restenergy - 1, checked, currow, curcol + 1, curres, res, maxrestenergy);
			curres.pop_back();
		}

		if (curcol > 0 && checked[currow][curcol - 1] == false && mat[currow][curcol - 1] == 1)
		{
			curres.push_back(Point(currow, curcol - 1));
			dfs(mat, restenergy - 1, checked, currow, curcol - 1, curres, res, maxrestenergy);
			curres.pop_back();
		}
	}

	if (currow < mat.size() - 1 && checked[currow + 1][curcol] == false && mat[currow + 1][curcol] == 1)
	{
		curres.push_back(Point(currow + 1, curcol));

		dfs(mat, restenergy, checked, currow + 1, curcol, curres, res, maxrestenergy);
		curres.pop_back();
	}

	if (restenergy >= 3)
	{
		if (currow > 0 && checked[currow - 1][curcol] == false && mat[currow - 1][curcol] == 1)
		{
			curres.push_back(Point(currow - 1, curcol));
			dfs(mat, restenergy - 3, checked, currow - 1, curcol, curres, res, maxrestenergy);
			curres.pop_back();
		}
	}
	checked[currow][curcol] = false;
}

int main()
{
	int rows; int cols;

	int energy;
	cin >> rows >> cols >> energy;
	vector<vector<int>> mat(rows, vector<int>(cols, 0));
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> mat[i][j];
		}
	}

	 solve(mat, energy);


	return 0;
}
