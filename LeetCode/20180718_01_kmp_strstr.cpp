#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>

class Solution
{
public:
	char *strStr(char *haystack, char *needle)
	{
		int l1 = strlen(haystack), l2 = strlen(needle);
		if (l1 < l2)
			return NULL;
		if (l1 == 0 || l2 == 0) //其实就是l2==""（空字符串）的时候，要直接返回l1
			return haystack;

		//if (haystack == nullptr || needle == nullptr || strlen(haystack) < strlen(needle))
		//	return nullptr;//这样是错的

		int pos = kmp(haystack, needle);
		return pos == -1 ? nullptr : haystack + pos;
	}

	int kmp(const std::string&str, const std::string&pattern)
	{
		std::vector<int> next = getNextArr(pattern);

		int idx1 = 0, idx2 = 0;
		while (idx1 < (int)str.length() && idx2 < (int)pattern.length())
		{
			if (str[idx1] == pattern[idx2])
			{
				++idx1;
				++idx2;
			}
			else if (next[idx2] == -1)
			{
				idx1++;
			}
			else
			{
				idx2 = next[idx2];
			}
		}

		return idx2 == (int)pattern.length() ? idx1 - pattern.length() : -1;
	}


	std::vector<int> getNextArr(const std::string &str)
	{
		int pos = 2;
		std::vector<int> nextArr(str.length());
		nextArr[0] = -1;
		if (str.length() > 1)
			nextArr[1] = 0;
		int cn = 0;
		while (pos < (int)str.length())
		{
			if (str[pos - 1] == str[cn])
			{
				nextArr[pos++] = ++cn;
			}
			else if (nextArr[cn] == -1)
			{
				nextArr[pos++] = 0;
			}
			else
			{
				cn = nextArr[cn];
			}
		}
		return nextArr;

	}

};

int main()
{
	Solution s;
	std::cout << s.strStr("abcdefg", "e") << std::endl;
	std::cout << s.strStr("abcdefg", "ef") << std::endl;
	//std::cout << s.strStr("abcdefg", "ea") << std::endl;
	std::cout << s.strStr("a", "ea") << std::endl;

	return 0;
}