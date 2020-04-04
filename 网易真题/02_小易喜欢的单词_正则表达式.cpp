/*
小易喜欢的单词具有以下特性：
1.单词每个字母都是大写字母
2.单词没有连续相等的字母
3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
例如：
小易不喜欢"ABBA"，因为这里有两个连续的'B'
小易不喜欢"THETXH"，因为这里包含子序列"THTH"
小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
小易喜欢"A","ABA"和"ABCBA"这些单词
给你一个单词，你要回答小易是否会喜欢这个单词（只要不是不喜欢，就是喜欢）。
输入描述:
输入为一个字符串，都由大写字母组成，长度小于100
输出描述:
如果小易喜欢输出"Likes",不喜欢输出"Dislikes"
示例1
输入
复制
AAA
输出
复制
Dislikes
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <regex>
using namespace std;

bool likeWord(const std::string &word)
{
	for (int i = 0; i < word.size() - 1; ++i)
	{
		if (word[i] == word[i + 1])
			return false;
	}

	std::unordered_map<char, int> hist;
	for (int i = 0; i < word.size(); ++i)
	{
		if (word[i] > 'Z' || word[i] < 'A')
			return false;
		hist[word[i]]++;
		if (hist[word[i]] >= 4)
			return false;
	}

	
	std::string pattern = "([A-Z])[A-Z]*([A-Z])[A-Z]*\\1[A-Z]*\\2"; //\\1代表第一个分组，\\2代表第二个分组
	std::regex s(pattern);
	std::smatch match_result;
	
	if (std::regex_search(word.cbegin(), word.cend(), match_result, s))
	{
		return false;
	}

	return true;
}


int main()
{
	int n;
	std::string str;
	while (cin >> str)
	{
		if (likeWord(str))
			cout << "Likes" << endl;
		else
			cout << "Dislikes" << endl;
	}





	return 0;
}