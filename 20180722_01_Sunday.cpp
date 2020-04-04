//https://blog.csdn.net/q547550831/article/details/51860017 图例看这个帖子
#include <iostream>
#include <string>
#include <unordered_map>
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

/**
IN
at the thought of
though

OUT
7
**/
int main()
{
	char str1[] = "substring searching";
	char str2[] = "search";

	std::cout << strStr(str1, str2) << std::endl;

	return 0;
}


