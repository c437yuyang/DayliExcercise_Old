/*
一条长l的笔直的街道上有n个路灯，若这条街的起点为0，终点为l，第i个路灯坐标为ai ，每盏灯可以覆盖到的最远距离为d，为了照明需求，所有灯的灯光必须覆盖整条街，但是为了省电，要使这个d最小，请找到这个最小的d。
输入描述:
每组数据第一行两个整数n和l（n大于0小于等于1000，l小于等于1000000000大于0）。第二行有n个整数(均大于等于0小于等于l)，为每盏灯的坐标，多个路灯可以在同一点。
输出描述:
输出答案，保留两位小数。
示例1
输入
复制
7 15
15 5 3 7 9 14 0
输出
复制
2.50
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

double solve(vector<int>& lights, int steetLen) {

	//需要考虑边界问题，第一个灯到0的距离，和最后一个灯到末尾的距离，是不用除2 的
	std::sort(lights.begin(), lights.end());
	double maxDiff = -1.0;
	maxDiff = lights[0];
	for (int i = 0; i < lights.size() - 1; ++i) {
		maxDiff = std::max(maxDiff, (lights[i + 1] - lights[i]) / 2.0);
	}
	maxDiff = std::max(maxDiff, (steetLen - lights.back())*1.0);
	return maxDiff;
}


int main() {

	int n, l;

	while (cin >> n >> l) {
		vector<int> lights(n);
		for (int i = 0; i < n; ++i) {
			cin >> lights[i];
		}
		printf("%.2f\n", solve(lights, l));
	}

	return 0;
}