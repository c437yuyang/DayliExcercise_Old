/*
现在有一张半径为r的圆桌，其中心位于(x,y)，现在他想把圆桌的中心移到(x1,y1)。每次移动一步，都必须在圆桌边缘固定一个点然后将圆桌绕这个点旋转。问最少需要移动几步。
输入描述:
一行五个整数r,x,y,x1,y1(1≤r≤100000,-100000≤x,y,x1,y1≤100000)
输出描述:
输出一个整数，表示答案
示例1
输入

2 0 0 0 4
输出

1
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

//就是每次都只能沿着x或y周移动2r距离，因此就看x,y共需要多少次搬移
int solve(int r, int x, int y, int x1, int y1) {
	return abs(x1 - x) / (r * 2) + abs(y1 - y) / (r * 2);
}

int main() {

	int r; int x; int y; int x1; int y1;
	while (cin >> r >> x >> y >> x1 >> y1) {
		cout << solve(r, x, y, x1, y1) << endl;
	}
	return 0;
}