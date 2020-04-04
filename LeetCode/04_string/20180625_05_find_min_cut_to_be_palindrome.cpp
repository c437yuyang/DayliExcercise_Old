/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s ="aab",
Return 1 since the palindrome partitioning["aa","b"]could be produced using 1 cut.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
  public:
	/// <summary>
	/// O(n^3)
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	int minCut2(const std::string &str)
	{
		//dp[i]表示，从0-i位置，成为回文最小需要切多少刀
		int *dp = new int[str.length()];

		for (int i = 0; i < str.length(); i++)
		{
			dp[i] = isPalindrome(str.substr(0, i + 1)) ? 0 : i; //初始时如果是回文，就不用切，如果不是就假设最多切i刀
			if (dp[i] == 0)										//不切已经是回文了，不用再判断
				continue;
			for (int j = 1; j <= i; j++) //找以i结尾的每个子串(i=0已经由dp[i]求得了所以从1开始)最少需要切多少刀
			{
				if (isPalindrome(str.substr(j, i - j + 1))) //判断j->i位置是否回文
					dp[i] = std::min(dp[i], dp[j - 1] + 1); //是的话，那么就可能成为最小，就是0->j-1,j->i切一刀，然后j-1自己的切的再加上
				else
					dp[i] = std::min(dp[i], dp[j - 1] + i - j + 1); //不是的话，就按照最大情况考虑
			}
		}
		return dp[str.length() - 1];
	}
	//判断回文
	bool isPalindrome(const std::string &s)
	{
		bool flag = true;
		for (int i = 0, j = s.length() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
			{
				flag = false;
				break;
			}
		}
		return flag;
	}

	/**
	* 回文的最小分割数
	* 1.dp[i]表示当前i到len-1这段的最小分割数
	* 2.dp[i]=min{dp[j+1]+1}（i=<j<len）其中str[i..j]必须是回文、
	* 3.p[i][j]=true表示str[i..j]是回文
	* 4.p[i][j]=s.charAt(i)==s.charAt(j) && (j-i<2||p[i+1][j-1])
	* O(N^2)
	*/
	int minCut(const std::string &s)
	{
		int *dp = new int[s.length() + 1];

		std::vector<std::vector<bool>> p(s.length(), std::vector<bool>(s.length(), false));

		dp[s.length()] = -1;					  //确保dp[s.length()-1]=0
		for (int i = s.length() - 1; i >= 0; i--) //以每一个位置开头
		{
			dp[i] = std::numeric_limits<int>::max();
			for (int j = i; j < s.length(); j++) //到每一个位置结尾
			{
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) //如果当前i-j形成了回文，就可能产生最小切割
				{
					p[i][j] = true;
					dp[i] = std::min(dp[i], dp[j + 1] + 1); //当前i-j是回文，因此就是1+dp[j-1],dp[j+1]是j+1到结尾需要多少刀成为回文
				}
			}
		}
		int res = dp[0];
		delete[] dp;
		return res;
	}
};

int main()
{
	Solution s;
	//assert(s.isPalindrome(9999) == true);
	//assert(s.isPalindrome(1000000001) == true);
	//assert(s.isPalindrome(1000110001) == true);
	assert(s.minCut("aab") == 1);   //aa,b
	assert(s.minCut("aabb") == 1);  //aa,bb
	assert(s.minCut("aabbc") == 2); //aa,bb,c
	assert(s.minCut("abccba") == 0);

	return 0;
}