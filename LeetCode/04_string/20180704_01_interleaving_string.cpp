/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 ="aabcc",
s2 ="dbbca",

When s3 ="aadbbcbcac", return true.
When s3 ="aadbbbaccc", return false.
*/

// #include <YXPUtility>
// using namespace yxp_utility;
#include <string>
#include <vector>
#include <cassert>
using namespace std;
class Solution
{
public:
	vector<vector<bool> > dp;
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s3 == "" && s1 == "" && s2 == "")
			return true;
		if (s3 == "")
			return false;
		if (s1 == "")
			return s3 == s2;
		if (s2 == "")
			return s3 == s1;
		if (s1.length() + s2.length() != s3.length())
			return false;

		return isInterleaveProcess(s1, s2, s3, 0, 0, 0);
	}

	bool isInterleaveProcess(const std::string& s1, const std::string& s2, const std::string& s3,
		size_t idx1, size_t idx2, size_t idx3)
	{
		if (idx3 == s3.length())
			return true;
		if (idx1 == s1.length())
			return s2.substr(idx2) == s3.substr(idx3);
		if (idx2 == s2.length())
			return s1.substr(idx1) == s3.substr(idx3);

		if (s1[idx1] != s3[idx3] && s2[idx2] != s3[idx3])
			return false;
		bool b1 = false;
		if (s1[idx1] == s3[idx3])
			b1 = isInterleaveProcess(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
		bool b2 = false;
		if (s2[idx2] == s3[idx3])
			b2 = isInterleaveProcess(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
		return b1 || b2;
	}

    //dp版
	bool isInterleave1(string s1, string s2, string s3)
	{
		if (s3 == "" && s1 == "" && s2 == "")
			return true;
		if (s3 == "")
			return false;
		if (s1 == "")
			return s3 == s2;
		if (s2 == "")
			return s3 == s1;
		if (s1.length() + s2.length() != s3.length())
			return false;

		//意义:s1,s2从i,j位置开始取,是否能够构成s3[i+j]往后取
		std::vector<std::vector<bool>> dp(s1.length() + 1, std::vector<bool>(s2.length() + 1, false));

		dp[s1.length()][s2.length()] = true; //终点位置为true,相当于"","",""
		for (int i = s1.length() - 1; i >= 0; --i) //反着推边界
			dp[i][s2.length()] = dp[i + 1][s2.length()] && s1[i] == s3[s2.length() + i];

		for (int i = s2.length() - 1; i >= 0; --i)
			dp[s1.length()][i] = dp[s1.length()][i + 1] && s2[i] == s3[s1.length() + i];

		for (int i = s1.length() - 1; i >= 0; --i)
		{
			for (int j = s2.length() - 1; j >= 0; --j)
			{
				dp[i][j] = (dp[i + 1][j] && s1[i] == s3[i + j]) ||
					(dp[i][j + 1] && s2[j] == s3[i + j]);
			}
		}
		return dp[0][0];
	}

};

int main()
{


	Solution s;
	assert(s.isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
	assert(s.isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
	assert(s.isInterleave1("aabcc", "dbbca", "aadbbcbcac") == true);
	assert(s.isInterleave1("aabcc", "dbbca", "aadbbbaccc") == false);
	assert(s.isInterleave1("bbbcc", "bbaccbbbabcacc", "bbbbacbcccbcbabbacc") == false);
	assert(s.isInterleave1("aa", "ab", "abaa") == true);


	return 0;
}