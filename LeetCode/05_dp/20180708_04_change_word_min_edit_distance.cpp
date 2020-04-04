/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <YXPUtility>
using namespace yxp_utility;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int m = word1.length();
		int n = word2.length();
		//从头开始,word1为i长度,word2为j长度的子串进行转换的最小步数
		std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			dp[i][0] = i;
		for (int j = 1; j <= n; j++)
			dp[0][j] = j;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1]) //当前字符(下标就是i-1,j-1)如果相等，则直接和前面的一样
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = std::min(dp[i - 1][j] + 1, std::min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1)); //插入，删除，替换三选一
			}
		return dp[m][n];
	}
};

int main()
{




	return 0;
}