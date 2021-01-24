#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//BF算法，二维循环匹配
int Search(const string &S, const string &T)
{

    int i = 0;
    int j = 0;

    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 1; //这里因为用的两个while，就有点不懂，看下面两个for的版本
            j = 0;
        }
    }

    if (T[j] == '\0')
        return i - j;

    //for循环的版本，复杂度:O(n*(n-m+1)) n=S.length(),m=T.length()
    for (int i = 0; i < S.length(); ++i)
    {
        int j = 0;
        for (; j < T.length() && S[i + j] == T[j]; ++j)
            ;
        if (j == T.length())
            return i;
    }

    return -1;
}


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

//Sunday算法
/*
匹配失败时关注的是主串中参加匹配的最末位字符的下一位字符。

如果该字符没有在模式串中出现则直接跳过，即移动位数 = 模式串长度 + 1；
否则，其移动位数 = 模式串长度 - 该字符最右出现的位置(以0开始) = 模式串中该字符最右出现的位置到尾部的距离 + 1。
*/
char *strStr(char *str1, char *str2)
{
	int len1 = strlen(str1), len2 = strlen(str2);
	if (len2 == 0) return str1;
	if (len2 > len1) return NULL;
	//用map保存str2中每个字符从后往前第一次出现的位置
	std::unordered_map<char, int> pos;
	for (int i = len2 - 1; i >= 0; --i)
	{
		if (pos.find(str2[i]) == pos.end())
			pos[str2[i]] = i;
	}
	int i = 0, j = 0;
	while (i < len1 && j < len2)
	{
		if (str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else
		{
			int index = pos[str1[i + len2 - j]]; //如果map里面没有的话，会默认生成0
			i = i + len2 - j - index;
			j = 0;
		}
		if (j == len2)
			return &str1[i - len2];
	}
	return NULL;
}
