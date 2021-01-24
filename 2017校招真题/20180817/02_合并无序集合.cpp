/*
给你两个集合，要求{A} + {B}。 注：同一个集合中不会有两个相同的元素。
输入描述:
每组输入数据分为三行,第一行有两个数字n,m(0 ≤ n,m ≤ 10000)，分别表示集合A和集合B的元素个数。后两行分别表示集合A和集合B。每个元素为不超过int范围的整数,每个元素之间有个空格隔开。
输出描述:
针对每组数据输出一行数据，表示合并后的集合，要求从小到大输出，每个元素之间有一个空格隔开,行末无空格。
示例1
输入
复制
3 3
1 3 5
2 4 6
输出
复制
1 2 3 4 5 6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(std::vector<int> &v1, std::vector<int> &v2) {
	int i1 = 0, i2 = 0;
	int cnt = 0;
	std::sort(v1.begin(), v1.end());//因为原始是无序的，要先排序，但这样复杂度一下就上来了，还不如直接用set来做
	std::sort(v2.begin(), v2.end());//如果是有序的直接merge是O(n)
	v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
	v2.erase(std::unique(v2.begin(), v2.end()), v2.end());
	std::vector<int> merged(v1.size() + v2.size());
	while (i1 < v1.size() && i2 < v2.size()) {
		if (v1[i1] < v2[i2]) {
			merged[cnt++] = v1[i1++];
		} else if (v1[i1] > v2[i2]) {
			merged[cnt++] = v2[i2++];
		} else {
			merged[cnt++] = v1[i1];
			++i1;
			++i2;
		}
	}

	while (i1 < v1.size()) {
		merged[cnt++] = v1[i1++];
	}
	while (i2 < v2.size()) {
		merged[cnt++] = v2[i2++];
	}
	
	for (int i = 0; i < cnt; ++i) {
		cout << merged[i];
		if (i != cnt - 1) {
			cout << " ";
		}
	}
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	std::vector<int> v1(n1), v2(n2);
	for (int i = 0; i < n1; ++i)
		cin >> v1[i];
	for (int i = 0; i < n2; ++i)
		cin >> v2[i];

	solve(v1, v2);
	return 0;
}
