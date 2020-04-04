/*
Given a string containing only digits, restore it by returning all 
possible valid IP address combinations.

For example:
Given"25525511135",

return["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <YXPUtility>
using namespace yxp_utility;
using namespace std;
class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		if (s == "" || s.length() < 4)
			return{};
		std::vector<std::string>res;
		dfs(s, 0, 4, "", res);
		return res;
	}

	//共需要生成四节
	void dfs(std::string &str, int i, int leftCnt, string curRes, std::vector<std::string>&res)
	{
		if (leftCnt == 1)
		{
			if (i > str.length() - 1)
				return;
			if (str[i] == '0' && i < str.length() - 1) //剩余0xx这种，只能以单个0结尾
				return;
			if (i < str.length() - 3) //剩余三位以上,溢出的也就考虑进去了(比如剩余了一个大于int_max的值来进行比较会溢出,无符号数和有符号数)
				return;
			if (std::atoi(str.substr(i).c_str()) <= 255)
			{
				curRes += "." + str.substr(i);
				res.push_back(curRes);
			}
			return;
		}

		if (str[i] == '0') //以0开头，必须单独一个0
		{
			dfs(str, i + 1, leftCnt - 1, i == 0 ? "0" : curRes + ".0", res);
			return;
		}

		for (int j = i; j < str.length() && j < i + 3; ++j)
		{
			string tmp = curRes;
			if (std::atoi(str.substr(i, j - i + 1).c_str()) <= 255)
			{
				if (tmp.length() > 0)
					tmp += "." + str.substr(i, j - i + 1);
				else 
					tmp += str.substr(i, j - i + 1);
				dfs(str, j + 1, leftCnt - 1, tmp, res);
			}
		}
	}
};

int main()
{
	TreeNode *root = GetExampleTree();

	Solution s;
	auto v = s.restoreIpAddresses("25525511135");
	v = s.restoreIpAddresses("2525511135");
	v = s.restoreIpAddresses("010010");


	return 0;
}