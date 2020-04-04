/*
现在有一个城市销售经理，需要从公司出发，去拜访市内的商家，已知他的位置以及商家的位置，但是由于城市道路交通的原因，他只能在左右中选择一个方向，在上下中选择一个方向，现在问他有多少种方案到达商家地址。

给定一个地图map及它的长宽n和m，其中1代表经理位置，2代表商家位置，-1代表不能经过的地区，0代表可以经过的地区，请返回方案数，保证一定存在合法路径。保证矩阵的长宽都小于等于10。

测试样例：
[[0,1,0],[2,0,0]],2,3
返回：2
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

//因为只能选上下左右各一个方向，因此就直接看初始的，就能确定上下左右能走的方向
class Visit {
public:
	int countPath(vector<vector<int> > map, int rows, int cols) { //
		// write code here
		vector<int> startPos(2);
		vector<int> endPos(2);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (map[i][j] == 1) {
					startPos[0] = i;
					startPos[1] = j;
				}

				if (map[i][j] == 2) {
					endPos[0] = i;
					endPos[1] = j;
				}
			}
		}
		//同行
		if (startPos[0] == endPos[0]) {
			return 1;
		} else if (startPos[1] == endPos[1]) {
			return 1; //同列也只有一种情况，只能直接朝着终点走，不能左右走
		}
		//不同行且不同列
		else {
			//全部转化成从左往右的情况,可能从上往下也可能从下往上
			if (startPos[1] > endPos[1]) {
				std::swap(startPos, endPos);
			}
		}

		//现在就两种情况，一种往右上走，一种往右下走
		
		vector<vector<int>> dp(rows, vector<int>(cols, 0));

		int r1 = startPos[0], c1 = startPos[1];
		int r2 = endPos[0], c2 = endPos[1];
		bool up = true; //从下往上
		if (r1 < r2)
			up = false;

		//就全是坐标运算了，就是计算路径数目的dp了
		if (!up) {
			for (int i = r2 - 1; i >= r1; --i) {
				if (map[i][c2] != -1)
					dp[i][c2] = 1;
				else break;
			}
			for (int j = c2 - 1; j >= c1; --j) {
				if (map[r2][j] != -1)
					dp[r2][j] = 1;
				else break;
			}
			for (int i = r2 - 1; i >= r1; --i) {
				for (int j = c2 - 1; j >= c1; --j) {
					dp[i][j] = map[i][j] == -1 ? 0 : dp[i + 1][j] + dp[i][j + 1];
				}
			}
			return dp[r1][c1];
		} else {
			for (int i = r2 + 1; i <= r1; ++i) {
				if (map[i][c2] != -1)
					dp[i][c2] = 1;
				else break;
			}
			for (int j = c2 - 1; j >= c1; --j) {
				if (map[r2][j] != -1)
					dp[r2][j] = 1;
				else break;
			}

			for (int i = r2 + 1; i <= r1; ++i) {
				for (int j = c2 - 1; j >= c1; --j) {
					dp[i][j] = map[i][j] == -1 ? 0 : dp[i - 1][j] + dp[i][j + 1];
				}
			}
			return dp[r1][c1];
		}
	}
};


int main() {

	vector<vector<int>> map = {
		{0,1,0 }, {2, 0, 0}
	};
	Visit v;
	auto res = v.countPath(map, 2, 3);


	return 0;
}