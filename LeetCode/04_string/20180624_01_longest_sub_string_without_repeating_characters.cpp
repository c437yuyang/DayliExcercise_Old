/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		if (s == "")
			return 0;
		int maxLen = 1;
		int curMax = 1;
		size_t curStart = 0;
		std::unordered_map<char, size_t> chIdxMap;
		std::unordered_map<size_t, char> idxChMap;
		chIdxMap.insert({ s[0], 0 });
		idxChMap.insert({ 0, s[0] });
		for (size_t i = 1; i < s.length(); ++i)
		{
			if (chIdxMap.find(s[i]) == chIdxMap.end())
			{
				chIdxMap.insert({ s[i], i });
				idxChMap.insert({ i, s[i] });
			}
			else
			{
				size_t extIdx = chIdxMap[s[i]];

				//抹掉curStart到extIdx的所有
				for (size_t i = curStart; i <= extIdx; ++i)
				{
					char ch = idxChMap[i];
					chIdxMap.erase(ch);
					idxChMap.erase(i);
				}
				curStart = extIdx + 1; //更新curStart
				chIdxMap.insert({ s[i], i });
				idxChMap.insert({ i, s[i] });
			}
			curMax = i - curStart + 1;
			maxLen = std::max(curMax, maxLen);
		}
		return maxLen;
	}

	//牛客看到的，不用两个map，一个就够了
	int lengthOfLongestSubstring1(std::string s)
	{
		if (s == "")
			return 0;
		int maxLen = 1;
		int curMax = 1;
		size_t curStart = 0;
		std::unordered_map<char, size_t> chIdxMap;
		chIdxMap.insert({ s[0], 0 });
		for (size_t i = 1; i < s.length(); ++i)
		{
			if (chIdxMap.find(s[i]) == chIdxMap.end()) //找不到
				chIdxMap.insert({ s[i], i });
			else
			{
				curStart = std::max(curStart, chIdxMap[s[i]] + 1); //就是窗口在右移其实，必须右移到重复字符的右边+1
																   //只用关心curStart的更新就可以了其实。。,并且curStart是不会回退的
																   //具体的可以考虑abcbadef这个例子，当第二次到a的时候，因为已经有了map['a']了且=0，因此不能回退
				chIdxMap[s[i]] = i;
			}
			curMax = i - curStart + 1;
			maxLen = std::max(curMax, maxLen);
		}
		return maxLen;
	}

	//下面这个方法也是滑窗思想，但是因为没有记录每个字符的位置，因此头每次只能往右移动1，然后窗口大小重新归1来开始计算，因此复杂度高一些
	int lengthOfLongestSubstring2(std::string s)
	{
		if (s == "")
			return 0;
		int maxLen = 1;
		int curStart = 0;
		std::unordered_set<char> chset;
		chset.insert(s[0]);
		int curIdx = 1;
		while (curStart < s.length() && curIdx < s.length())
		{
			if (chset.find(s[curIdx]) == chset.end()) //找不到
			{
				maxLen = std::max(curIdx - curStart + 1, maxLen);
				chset.insert(s[curIdx++]);
			}
			else
			{
				chset.erase(s[curStart]);
				curStart = curStart + 1; //头部右移1,但是尾部curIdx没移动，因此如果移出去的不是头部下次迭代还会继续移动，比如abcdb,到达b的时候，先移出a,再移出b会
			}
		}
		return maxLen;
	}
};
int main()
{
	Solution s;
	assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
	assert(s.lengthOfLongestSubstring("abcad") == 4);
	assert(s.lengthOfLongestSubstring("abcbdef") == 5);
	// std::cout << s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << std::endl;
	assert(s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") == 12);

	assert(s.lengthOfLongestSubstring1("abcabcbb") == 3);
	assert(s.lengthOfLongestSubstring1("abcad") == 4);
	assert(s.lengthOfLongestSubstring1("abcbdef") == 5);
	assert(s.lengthOfLongestSubstring1("abcbadef") == 6);
	std::cout << s.lengthOfLongestSubstring1("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << std::endl;
	assert(s.lengthOfLongestSubstring1("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") == 12);


	assert(s.lengthOfLongestSubstring2("abcabcbb") == 3);
	assert(s.lengthOfLongestSubstring2("abcad") == 4);
	assert(s.lengthOfLongestSubstring2("abcbdef") == 5);
	assert(s.lengthOfLongestSubstring2("abcbadef") == 6);
	std::cout << s.lengthOfLongestSubstring2("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << std::endl;
	assert(s.lengthOfLongestSubstring2("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") == 12);


	return 0;
}