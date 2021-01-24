/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s ="aab",
Return

[
["aa","b"],
["a","a","b"]
]

*/

#include <string>
#include <vector>
#include <YXPUtility>
using namespace std;
//牛客看到的，自己没做出来
class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> res;
		vector<string> cur;
		dfs(s, cur, res);
		return res;
	}

	bool isPalindrome(string s)
	{
		return s == string(s.rbegin(), s.rend());
	}

	void dfs(string s, vector<string> &cur, vector<vector<string>> &res)
	{
		if (s == "")
		{ //切分完了，且是满足条件的才会到这一步，那么就把cur添加到res中
			res.push_back(cur);
			return;
		}

		for (size_t i = 1; i <= s.length(); ++i)
		{ //找切分点在每一个位置
			string sub = s.substr(0, i); //前半段,兼容s本身是回文串的情况
			if (isPalindrome(sub))
			{ //当前切分后，前半段能够是回文，才继续下面的
				cur.push_back(sub); //前半段是回文，添加到cur中
				dfs(s.substr(i, s.length() - i), cur, res); //继续找后半段的，添加到cur中
				cur.pop_back();//恢复cur状态
			}
		}
	}
};

int main()
{
	Solution s;
	std::string str = "aab";
	yxp_utility::ArrayHelper::printMatrix(s.partition(str));

	str = "aaabb";
	yxp_utility::ArrayHelper::printMatrix(s.partition(str));

	return 0;

}