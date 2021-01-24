#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	unordered_map<char, string>mp = { { '2',"abc" },{ '3',"def" },{ '4',"ghi" },
	{ '5',"jkl" },{ '6',"mno" },{ '7',"pqrs" },
	{ '8',"tuv" },{ '9',"wxyz" } };

	vector<string> letterCombinations(string digits)
	{
		vector<string> res;
		string curRes;
		dfs(digits, 0, res, curRes);
		return res;
	}

	void dfs(string&digits, int i, vector<string>&res, string &curRes)
	{
		if (i == digits.size())
		{
			res.push_back(curRes);
			return;
		}
		if (digits[i] == '1')
			dfs(digits, i + 1, res, curRes);
		else
		{
			string chars = mp[digits[i]];
			for (int j=0;j<chars.size();++j)
			{
				curRes += chars[j];
				dfs(digits, i + 1, res, curRes);
				curRes.pop_back();
			}
		}
	}

	


};


int main()
{
	Solution s;
	auto res = s.letterCombinations("23");


}