/*
ss请cc来家里钓鱼，鱼塘可划分为n＊m的格子，每个格子有不同的概率钓上鱼，cc一直在坐标(x,y)的格子钓鱼，而ss每分钟随机钓一个格子。问t分钟后他们谁至少钓到一条鱼的概率大？为多少？
输入描述:
第一行五个整数n,m,x,y,t(1≤n,m,t≤1000,1≤x≤n,1≤y≤m);
接下来为一个n＊m的矩阵，每行m个一位小数，共n行，第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1)
输出描述:
输出两行。第一行为概率大的人的名字(cc/ss/equal),第二行为这个概率(保留2位小数)
示例1
输入
2 2 1 1 1
0.2 0.1
0.1 0.4
输出
equal
0.20
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

double removeFraction(double num, int digit) {
	int factor = pow(10, digit);
	num *= factor;

	return (num - floor(num)) / factor;
}

void solve(vector<vector<double>> &pools, int x, int y, int t) {

	int m = pools.size();
	int n = pools[0].size();
	double p = 0.0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			p += 1.0 - pools[i][j];
		}
	}

	p /= (m*n);
	double ss = 1 - pow(p, t);
	double cc = 1 - pow((1.0 - pools[x - 1][y - 1]), t); //这里的x,y是反的

	if (abs(ss - cc) < 1e-13) {
		cout << "equal" << endl;
		printf("%.2f\n", ss);
	} else if (ss > cc) {
		printf("ss\n%.2f\n", ss);
	} else {
		printf("cc\n%.2f\n", cc);
	}


}


int main() {

	int m; int n;
	int x; int y; int t;
	while (cin >> m >> n >> x >> y >> t) {
		vector<vector<double>> pools(m, vector<double>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> pools[i][j];
			}
		}
		solve(pools, x, y, t);
	}

	return 0;
}