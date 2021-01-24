#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <unordered_map>
using namespace std;

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S ="ADOBECODEBANC"
T ="ABC"

Minimum window is"BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string"".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

//15.52
class Solution
{
public:
	//思路1:找到所有A,B,C的位置，然后多重循环就解决了，但是T有重复字符就不对了
	//思路2:牛客看到的，滑窗
	string minWindow(string S, string T)
	{
		if (T == "" || S == "" || T.length() > S.length())
			return "";
		std::unordered_map<char, int> map;
		for (size_t i = 0; i < T.length(); ++i)
			++map[T[i]];

		size_t left = 0, right = 0;
		size_t minLeft = 0, minRight = 0;
		int min = std::numeric_limits<int>::max();

		if (map.find(S[0]) != map.end())
			--map[S[0]];

		while (left <= right && right < S.length())
		{
			if (!allInWindow(map)) //用一个map记录所有数的出现次数，初始为T中需要找到的频数,若=0了就是找到了
			{
				++right; //窗口内没有涵盖完就往右走
				if (map.find(S[right]) != map.end())
					--map[S[right]];
			}
			else//全部涵盖了就往左走，尽可能的小让其
			{
				if ((int)(right - left + 1) < min)
				{
					min = (int)(right - left + 1);
					minLeft = left;
					minRight = right;
				}
				if (map.find(S[left]) != map.end())
					++map[S[left]];
				++left;
			}
		}
		if (min != std::numeric_limits<int>::max())
			return S.substr(minLeft, minRight - minLeft + 1);
		return "";
	}

	bool allInWindow(const std::unordered_map<char, int> &map)
	{
		for (auto it = map.begin(); it != map.end(); ++it)
		{
			if (it->second > 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	auto str = s.minWindow("B", "A");
	str = s.minWindow("ADOBECODEBANC", "ABC");

	return 0;
}