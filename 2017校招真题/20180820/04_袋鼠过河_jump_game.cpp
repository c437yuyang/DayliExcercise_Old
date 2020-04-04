/*
一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1
输入描述:
输入分两行，第一行是数组长度N (1 ≤ N ≤ 10000)，第二行是每一项的值，用空格分隔。
输出描述:
输出最少的跳数，无法到达输出-1
示例1
输入
复制
5
2 0 1 1 1
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
				if (i + j <= nums.size() - 1 && dp[i + j] != intmax) //i+j<=nums.size()-1别忘了
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