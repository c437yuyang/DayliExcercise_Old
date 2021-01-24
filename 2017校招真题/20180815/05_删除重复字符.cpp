/*
题目描述
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入描述:
每个测试输入包含2个字符串
输出描述:
输出删除后的字符串
示例1
输入
复制
They are students. aeiou
输出
复制
Thy r stdnts.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;

std::string deleteCommonChars(const std::string &str1, const std::string&str2)
{
	if (str2 == "")
		return str1;

	std::unordered_set<char> set(str2.begin(), str2.end());
	std::string res;
	for (int i = 0; i < str1.length(); ++i)
	{
		if (set.find(str1[i]) == set.end())
			res.append(1, str1[i]);
	}

	return res;

}


int main()
{
	std::string str1, str2;
	std::getline(std::cin, str1);
	std::getline(std::cin, str2);
	std::cout << deleteCommonChars(str1, str2) << std::endl;

	return 0;
}