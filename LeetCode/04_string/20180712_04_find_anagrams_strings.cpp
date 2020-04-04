/*

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

For example:

Input:  ["tea","and","ate","eat","den"]

Output:   ["ate","eat","tea"] //输出字典序

Input:  ["tea","and","ate","eat","dan"]

Output:   ["and","ate","dan","eat","tea"]

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
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		if (strs.empty())
			return{};
		if (strs[0] == "" && strs[1] == "")
			return strs;
		std::map<std::vector<int>, int> mapFirstIdx;
		std::map<std::vector<int>, bool> mapInserted;
		std::vector<std::string> res;
		std::multiset<std::string> findedSet;
		for (size_t i = 0; i < strs.size(); ++i) {
			std::vector<int> hist(26, 0);
			for (size_t j = 0; j < strs[i].size(); ++j)
				++hist[strs[i][j] - 'a'];
			if (mapFirstIdx.find(hist) == mapFirstIdx.end()) {
				mapFirstIdx[hist] = i;
				mapInserted[hist] = false;
			} else {//重复出现了
				if (mapInserted[hist] == false) //第一次出现的也加进去，只加一次 
					findedSet.insert(strs[mapFirstIdx[hist]]);
				findedSet.insert(strs[i]);
				mapInserted[hist] = true;
			}
		}

		for (auto it = findedSet.begin(); it != findedSet.end(); ++it)
			res.push_back(*it);
		return res;
	}
};

//牛客看到的更简单的做法
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> mp;
		for (int i = 0; i < strs.size(); ++i) {
			string key = strs[i];
			sort(key.begin(), key.end());
			mp[key].push_back(strs[i]); //anagrams字典序排序后都是一样的，加入到同一个key下面
		}
		vector<string> res;
		for (auto it : mp) {
			if ((it.second).size() > 1) {//存在兄弟词汇
				res.insert(res.end(), it.second.begin(), it.second.end());
			}
		}

		sort(res.begin(), res.end()); //输出是字典序
		return res;
	}
};


int main() {

	Solution s;

	std::vector<std::string> input = { "tea","and","ate","eat","den" };
	auto v = s.anagrams(input);

	input = { "tea","and","ate","eat","dan" };
	v = s.anagrams(input);

	input = { "c","c" };
	v = s.anagrams(input);

	input = { "","" };
	v = s.anagrams(input);

	return 0;
}