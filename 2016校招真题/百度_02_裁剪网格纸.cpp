/*
题目描述
度度熊有一张网格纸，但是纸上有一些点过的点，每个点都在网格点上，若把网格看成一个坐标轴平行于网格线的坐标系的话，每个点可以用一对整数x，y来表示。度度熊必须沿着网格线画一个正方形，使所有点在正方形的内部或者边界。然后把这个正方形剪下来。问剪掉正方形的最小面积是多少。
输入描述:
第一行一个数n(2≤n≤1000)表示点数，接下来每行一对整数xi,yi(－1e9<=xi,yi<=1e9)表示网格上的点
输出描述:
一行输出最小面积
示例1
输入
2
0 0
0 3
输出
9
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
};

//就是找最大最小的x,y，然后因为是正方形，要取长宽较大的
int solve(vector<Point> &pts) {
	int int_max = std::numeric_limits<int>::max();
	int int_min = std::numeric_limits<int>::min();
	int minx = int_max, miny = int_max, maxx = int_min, maxy = int_min;
	for (int i = 0; i < pts.size(); ++i) {
		minx = std::min(minx, pts[i].x);
		maxx = std::max(maxx, pts[i].x);
		miny = std::min(miny, pts[i].y);
		maxy = std::max(maxy, pts[i].y);
	}

	int maxWidth = std::max(maxx - minx, maxy - miny);
	return maxWidth*maxWidth;
}


int main() {
	int n;
	while (cin >> n) {
		vector<Point> pts(n);
		for (int i = 0; i < n; ++i) {
			cin >> pts[i].x >> pts[i].y;
		}
		cout << solve(pts) << endl;
	}
	
	return 0;
}