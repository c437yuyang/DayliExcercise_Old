/*
Given two words (start and end), and a dictionary, 
find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start ="hit"
end ="cog"
dict =["hot","dot","dog","lot","log"]

Return

[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
using namespace std;

//错的，没做出来，牛客的答案是图论算法
class Solution
{
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
	{
		std::vector<std::string> curRes;
		std::vector<std::vector<std::string>> res;
		findAndAdd2Ladders(start, end, dict, curRes, res);
		return res;
	}

	void findAndAdd2Ladders(std::string curStr, std::string& end, unordered_set<std::string> dict, 
		std::vector<std::string> curRes,
		std::vector<std::vector<std::string>> &res)
	{
		curRes.push_back(curStr);
		if (calcDist(end, curStr)==1)
		{
			curRes.push_back(end);
			res.push_back(curRes);
			return;
		}

		if (dict.empty())
			return;

		auto dict_copy = dict;
		for (auto str : dict)
		{
			if (calcDist(str, curStr) == 1)
			{
				dict_copy.erase(str);
				curStr = str;
				findAndAdd2Ladders(curStr, end, dict_copy, curRes, res);
			}
		}
	}

	size_t calcDist(const std::string&str1, const std::string &str2)
	{
		if (str1 == "hit" && str2 == "lot")
			int j = 0;
		size_t res = 0;
		for (size_t i = 0; i < str1.length(); ++i)
		{
			res += str1[i] == str2[i] ? 0 : 1;
		}
		return res;
	}

};


int main()
{
	//std::unordered_set<int> s{ 1,2,3,4,111,222,333 };

	//for (int num : s)
	//{
	//	std::cout << num << std::endl;
	//}

	Solution s;
	std::unordered_set<std::string> dict{ "hot","dot","dog","lot","log" };
	


	auto res = s.findLadders("hit", "cog", dict);


	return 0;
}