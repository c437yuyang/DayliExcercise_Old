/*
有一个投篮游戏。球场有p个篮筐，编号为0，1...，p-1。每个篮筐下有个袋子，每个袋子最多装一个篮球。有n个篮球，每个球编号xi 。规则是将数字为xi 的篮球投到xi 除p的余数为编号的袋里。若袋里已有篮球则球弹出游戏结束输出i，否则重复至所有球都投完。输出-1。问游戏最终的输出是什么？
输入描述:
第一行两个整数p,n（2≤p,n≤300)。p为篮筐数，n为篮球数。接着n行为篮球上的数字xi(0≤xi≤1e9)
输出描述:
输出游戏的结果
示例1
输入
复制
10 5
0
21
53
41
53
输出
复制
4
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
#include <bitset>
using namespace std;

//这道题就是考一个位图的使用，因为本身有或没有用一位就够了
int solve(int backetNum, vector<int>&balls) {
	vector<bool> backetHasBall(backetNum, false); //虽然vector<bool> 本身就是位图

	for (int i = 0; i < balls.size(); ++i) {
		int cur = balls[i] % backetNum;
		if (backetHasBall[cur])
			return i + 1;
		backetHasBall[cur] = true;
	}
	return -1;
}

//自己实现位图
int solve1(int backetNum, vector<int>&balls) {
	int cnt = backetNum / 8;
	cnt += backetNum % 8 == 0 ? 0 : 1;
	vector<char> backetHasBall(cnt, 0); //全部初始化为0

	for (int i = 0; i < balls.size(); ++i) {
		int q = balls[i] % backetNum;
		int cur = q / 8;
		int cur1 = q % 8;
		if ((backetHasBall[cur] >> cur1) & 1)
			return i + 1;
		backetHasBall[cur] |= (1 << cur1);
	}
	return -1;
}

int main() {

	int n1, n2;
	while (cin >> n1 >> n2) {
		vector<int> balls(n2);
		for (int i = 0; i < n2; ++i) {
			cin >> balls[i];
		}
		cout << solve1(n1, balls) << endl;
	}

	return 0;
}