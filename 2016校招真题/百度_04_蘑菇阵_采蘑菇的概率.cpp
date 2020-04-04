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
	int row;
	int col;
};

//输出是不碰蘑菇的概率
double solve(vector<Point>&pts, int rows, int cols) {

	vector<vector<int>> mat(rows, vector<int>(cols, 0));
	for (int i = 0; i < pts.size(); ++i) {
		mat[pts[i].row - 1][pts[i].col - 1] = 1;
	}

	vector<vector<double>> dp(rows, vector<double>(cols, 0.0)); //假设全部都一定会碰蘑菇
	if (mat[rows - 1][cols - 1] == 1)
		return 0.0;
	dp[rows - 1][cols - 1] = 1.0; //shit ,这里写成了mat[][]=1.0就全错了后面，调了半小时

	for (int i = rows - 1; i >= 0; --i) {
		if (mat[i][cols - 1] == 1)
			break;
		dp[i][cols - 1] = 1.0;
	}

	for (int j = cols - 1; j >= 0; --j) {
		if (mat[rows - 1][j] == 1)
			break;
		dp[rows - 1][j] = 1.0;
	}

	for (int i = rows - 2; i >= 0; --i) {
		for (int j = cols - 2; j >= 0; --j) {
			if (mat[i][j] == 1) {
				dp[i][j] = 0.0;
			} else {
				dp[i][j] = 0.5 * dp[i + 1][j] + 0.5 * dp[i][j + 1]; //就和之前的dp是一样的基本上，只是要算概率
			}
		}
	}

	return dp[0][0];
}


int main() {

	int rows, cols, n;
	while (cin >> rows >> cols >> n) {
		vector<Point> pts(n);
		for (int i = 0; i < n; ++i) {
			cin >> pts[i].row >> pts[i].col;
		}
		printf("%.2f\n", solve(pts, rows, cols));
	}

	return 0;
}