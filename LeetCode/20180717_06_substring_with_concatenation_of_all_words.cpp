/*

You are given a string, S, and a list of words, L, that are all of the same length.
Find all starting indices of substring(s) in S that is a concatenation
of each word in L exactly once and without any intervening characters.

For example, given:
S:"barfoothefoobarman"
L:["foo", "bar"]

You should return the indices:[0,9].
(order does not matter).

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> findSubstring(std::string str, std::vector<std::string> &words)
	{
		std::unordered_map<std::string, int> wordsCnt;
		for (int i = 0; i < words.size(); ++i)
			wordsCnt[words[i]]++;
		std::vector<int> res;
		int wordsLen = words.size() * words[0].length(); //所有words的长度
		int singleLen = words[0].length();
		for (int i = 0; i < str.length() - wordsLen + 1; ++i)
		{
			std::unordered_map<std::string, int> wordsSeen; //当前位置每个单词出现的次数
			int findCnt = 0;
			while (findCnt < words.size()) //从当前位置开始每singleLen一个单词拿进去找
			{
				std::string curWord = str.substr(i + findCnt*singleLen, singleLen); //
				if (wordsCnt.find(curWord) == wordsCnt.end()) //没找到，直接break
					break;
				wordsSeen[curWord]++;
				if (wordsSeen[curWord] > wordsCnt[curWord]) //出现次数超过直接break
					break;
				findCnt++; //一定要放到后面来
			}

			if (findCnt == words.size())
				res.push_back(i);
		}
		return res;
	}
};


int main()
{
	Solution s;
	std::vector<std::string> words = { "foo", "bar" };
	auto v = s.findSubstring("barfoothefoobarman", words);


	words = { "a", "b" };
	v = s.findSubstring("aaa", words);

	return 0;
}