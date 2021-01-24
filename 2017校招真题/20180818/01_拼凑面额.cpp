/*
�����������1��5��10��20��50��100Ԫ��ֽ�ң�����ÿ�ֱ�ֵ���������㹻�࣬��д���������NԪ��NΪ0-10000�ķǸ��������Ĳ�ͬ��ϵĸ�����
��������:
����Ϊһ������N������Ҫƴ�յ����
�������:
���Ҳ��һ�����֣�Ϊ���N����ϸ�����
ʾ��1
����
5
���
2
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

long long solve(vector<int>&coins, int aim) {

	vector<vector<long long>> dp(aim + 1, vector<long long>(coins.size(), 0));
	int m = aim + 1;
	int n = coins.size();
	for (int j = 0; j < coins.size(); ++j)
		dp[0][j] = 1;

	for (int i = 1; i < aim + 1; ++i) {
		dp[i][n - 1] = (i % coins[n - 1]) == 0 ? 1 : 0;
	}

	for (int i = 1; i < aim + 1; ++i) {
		for (int j = n - 2; j >= 0; --j) {
			int cnt = i / coins[j];
			for (int k = 0; k <= cnt; ++k) {
				dp[i][j] += dp[i - k*coins[j]][j + 1];
			}
		}
	}

	return dp[aim][0];
}

int main() {

	int n;
	cin >> n;
	vector<int > coins = { 1,5,10,20,50,100 };
	auto res =solve(coins, n);

	cout << res << endl;
	return 0;
}

