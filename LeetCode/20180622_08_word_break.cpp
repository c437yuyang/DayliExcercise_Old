/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].

A solution is["cats and dog", "cat sand dog"].
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
using namespace std;

//没过这道题，
//dfs超时
class Solution1
{
public:
	std::vector<std::string> wordBreak(std::string s, std::unordered_set<std::string> &dict)
	{
		if (s.length() == 0)
			return{};

		if (dict.size() == 0)
			return{};

		process(s, dict, 0, "");
		return res;
	}

	//当前startidx能够匹配的开始有哪些
	void process(std::string s, std::unordered_set<std::string> &dict, int startIdx, std::string curRes)
	{
		if (startIdx == s.length())
		{
			curRes.pop_back(); //去除尾部" "
			res.push_back(curRes);
			return;
		}

		//遍历进行匹配
		//for (int j = s.length() - 1; j >= startIdx; --j)
		for (int j = startIdx; j < s.length(); ++j)
		{
			std::string tmp = s.substr(startIdx, j - startIdx + 1);
			if (dict.find(tmp) != dict.end())
			{
				std::string tmpRes = curRes;
				tmpRes += tmp + " ";
				process(s, dict, j + 1, tmpRes);
			}
		}
	}



private:
	std::vector<std::string> res;
};

//牛客看到的，没看太明白
class Solution2
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		dp = new vector<bool>[s.size()];

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				dp[i].push_back(match(s.substr(i, j - i + 1), dict));
			}
		}
		/*
		for (int i = 0; i < s.size(); i++)
		{
		for (int j = 0; j < dp[i].size(); j++)
		{
		cout << dp[i][j] << " ";
		}
		cout << endl;
		}
		*/
		output(s.size() - 1, s);

		return result;
	}
	bool match(string s, unordered_set<string> &dict)
	{
		if (dict.find(s) != dict.end()) return true;
		else return false;
	}
	void output(int i, string s)
	{
		if (i == -1)    //递归退出条件
		{
			string str;
			for (int j = curRes.size() - 1; j >= 0; j--)
			{
				str += curRes[j];
				if (j != 0) str += " ";
			}
			result.push_back(str);
		}
		else
		{
			for (int k = 0; k <= i; k++) //error!!!  for (int k = 0; k < i; k++)
			{
				if (dp[k][i - k])       //dp[k][i-k]:偏移为k，截断长度i-k+1
				{
					curRes.push_back(s.substr(k, i - k + 1));
					output(k - 1, s);   //递归:dp[0][i]:偏移为0，截断长度i+1      i=k-1,则截断长度为k,与递归前偏移k互补
					curRes.pop_back();
				}
			}
		}
	}
	vector<string> result;
	vector<string> curRes;
	vector<bool> *dp;
};


int main()
{
	std::string s = "catsanddog";
	std::unordered_set<std::string> dict{ "cat", "cats", "and", "sand", "dog" };

	auto res = Solution1().wordBreak(s, dict);
	std::reverse(res.begin(), res.end());

	return 0;
}