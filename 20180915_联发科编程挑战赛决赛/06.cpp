/*
最美字符串
题目描述
字符串有很多格式，我们定义最美字符串为:能够对称的 
比如“CBABC“， 因为字符串本身和它的反转字符串是相同的，也即字符串以中间字符为轴心呈对称展开。 
现在需要您帮忙提供方案能够将任一字符串经过最少切割次数使得每个子字串都是最美字符串。

输入说明
程序从当前路径下的data.txt文件中读取测试数据。 
文件内容只有一行待测字符串(只包含数字和字母，且区分大小写, 字符串长度不超过1KB)。

输出说明
向标准输出打印最少切割次数

示例1
输入：

ACDCDCDAD
最少需要切2次， 使得每个子串都变成最美字符串， 比如: A|CDCDC|DAD， 所以输出2 
输出：

2
示例2
输入：

ABA
不需要切割， 字符串本身就是对称的， 所以输出0。 
输出：

0
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <fstream>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isPalindrome(const std::string &s) {
		bool flag = true;
		for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				flag = false;
				break;
			}
		}
		return flag;
	}

	int minCut(const std::string &s) {
		if (isPalindrome(s)) {
			return 0;
		}
		std::vector<int> dp(s.length() + 1);
		std::vector<std::vector<bool>> p(s.length(), std::vector<bool>(s.length(), false));
		dp[s.length()] = -1;
		for (int i = s.length() - 1; i >= 0; i--) {
			dp[i] = std::numeric_limits<int>::max();
			for (int j = i; j < s.length(); j++) {
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
					p[i][j] = true;
					dp[i] = std::min(dp[i], dp[j + 1] + 1);
				}
			}
		}
		int res = dp[0];
		return res;
	}
};

int main() {
	Solution s;
	std::ifstream ifs("data.txt");
	std::string str;
	std::getline(ifs, str);
	std::cout << s.minCut(str) << std::endl;
	return 0;
}