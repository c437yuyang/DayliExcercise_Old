/*
һֻ����Ҫ�Ӻ���������Ӷ԰����Ӻܿ����Ǻ��м���˺ܶ�׮�ӣ�ÿ��һ�׾���һ����ÿ��׮���϶���һ�����ɣ��������������ϾͿ������ĸ�Զ��ÿ������������ͬ����һ�����ִ������������������������Ϊ5���ʹ��������һ������ܹ���5�ף����Ϊ0���ͻ��ݽ�ȥ�޷�������Ծ������һ��N�׿������ʼλ�þ��ڵ�һ���������棬Ҫ�������һ������֮���������ˣ�����ÿ�����ɵ������������������Ҫ�������ܹ�����԰�������޷��������-1
��������:
��������У���һ�������鳤��N (1 �� N �� 10000)���ڶ�����ÿһ���ֵ���ÿո�ָ���
�������:
������ٵ��������޷��������-1
ʾ��1
����
����
5
2 0 1 1 1
���
����
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
using namespace std;

int solve(vector<int> &nums) {
	int intmax = std::numeric_limits<int>::max();
	vector<int> dp(nums.size(), intmax);
	if (nums.back() > 0)
		dp.back() = 1;

	for (int i = dp.size() - 2; i >= 0; --i) {

		if (i + nums[i] >= nums.size()) {
			dp[i] = 1;
		} else {
			for (int j = 1; j <= nums[i]; ++j) {
				if (i + j <= nums.size() - 1 && dp[i + j] != intmax) //i+j<=nums.size()-1������
					dp[i] = std::min(dp[i], 1 + dp[i + j]);
			}
		}
	}
	return dp[0] == intmax ? -1 : dp[0];
}


int main() {

	int n;
	while (cin >> n) {
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		cout << solve(nums) << endl;
	}

	return 0;
}