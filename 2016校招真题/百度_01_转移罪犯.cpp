/*
C市现在要转移一批罪犯到D市，C市有n名罪犯，按照入狱时间有顺序，另外每个罪犯有一个罪行值，值越大罪越重。现在为了方便管理，市长决定转移入狱时间连续的c名犯人，同时要求转移犯人的罪行值之和不超过t，问有多少种选择的方式（一组测试用例可能包含多组数据，请注意处理）？
输入描述:
第一行数据三个整数:n，t，c(1≤n≤2e5,0≤t≤1e9,1≤c≤n)，第二行按入狱时间给出每个犯人的罪行值ai(0≤ai≤1e9)
输出描述:
一行输出答案。
示例1
输入
3 100 2
1 2 3
输出
2
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

//就是一个滑窗，然后看满足大小的有多少
long long solve(vector<int> & crimes, int maxCrime, int cnt) {
	long long sum = 0;
	int left = 0;
	int right = cnt - 1;
	for (int i = left; i <= right; ++i) {
		sum += crimes[i];
	}
	long long res = sum <= maxCrime ? 1 : 0;
	for (left += 1, right += 1; left <= crimes.size() - cnt; ++left, ++right) {
		sum += crimes[right];
		sum -= crimes[left - 1];
		res += sum <= maxCrime ? 1 : 0;
	}
	return res;
}

int main() {
	int n; int maxCrime; int cnt;
	while (cin >> n >> maxCrime >> cnt) {
		vector<int> crimes(n);
		for (int i = 0; i < n; ++i) {
			cin >> crimes[i];
		}
		cout << solve(crimes, maxCrime, cnt) << endl;
	}
	return 0;
}