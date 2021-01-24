/*
有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。
输入描述:
每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。
输出描述:
一行输出最后一个被删掉的数的原始下标位置。
示例1
输入
8
输出
6
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

//共cnt个人，编号从1开始，每m个删一个
int getLive(int cnt, int m) {
	if (cnt == 1) {
		return 1;
	}
	return (getLive(cnt - 1, m) + m - 1) % cnt + 1;
}

int main() {

	int n;
	while (cin >> n) {
		cout << (getLive(n, 3) - 1) << endl;
	}

	return 0;
}