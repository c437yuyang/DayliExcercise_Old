/*
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
输入描述:
输入包括n+1行:
第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
接下来的n行:
每行m个0或者1,以空格分隔
输出描述:
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。 测试数据保证答案唯一
示例1
输入
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
输出
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
