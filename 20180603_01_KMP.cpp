#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

std::vector<int> GetNextArray(const std::string& pattern);
int KMP(const std::string& str1, const std::string&str2)
{
	std::string str = str1;
	std::string pattern = str2;
	std::vector<int> next_arr = GetNextArray(pattern);
	int idx1 = 0, idx2 = 0;
	while (idx1 < str1.length() && idx2 < str2.length())
	{
		if (str[idx1] == pattern[idx2])
		{
			++idx1;
			++idx2;
		}
		else if (next_arr[idx2] == -1)
			idx1++;
		else
			idx2 = next_arr[idx2];
	}

	return idx2 == pattern.length() ? idx1 - pattern.length() : -1; //因为比较完了后
}

std::vector<int> GetNextArray(const std::string& pattern)
{
	int cn = 0;
	int pos = 2;
	std::vector<int> next(pattern.size(), 0);
	next[0] = -1;
	while (pos < pattern.size())
	{
		if (pattern[cn] == pattern[pos - 1])
			next[pos++] = ++cn;
		else if (next[cn] == -1) //其实就是cn==0,只有0这一个位置会出现-1值
			next[pos++] = 0;
		else //cn>0
			cn = next[cn];
	}
	return next;
}

int main()
{
	std::string str = "ababcabcacbab";
	std::string pattern = "abcac";
	std::cout << KMP(str, pattern) << std::endl;

	str = "abcabcababaccc";
	pattern = "ababa";
	std::cout << KMP(str, pattern) << std::endl;

	str = "ababcabcacbab";
	pattern = "abcac";
	KMP(str,pattern);


	return 0;
}