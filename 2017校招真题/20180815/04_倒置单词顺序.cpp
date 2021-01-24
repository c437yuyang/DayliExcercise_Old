/*
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
示例1
输入
复制
I like beijing.
输出
复制
beijing. like I
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <stack>
#include <sstream>
using namespace std;

//这个是翻转里面每个单词内字母的顺序了
//std::string reverseWords(const std::string&str)
//{
//	std::stringstream ss(str);
//	std::string word;
//	std::string res;
//	while (std::getline(ss, word, ' '))
//	{
//		if (!isalpha(word.back()))
//			std::reverse(word.begin(), word.end() - 1);
//		else
//			std::reverse(word.begin(), word.end());
//		res += word + " ";
//	}
//	res.pop_back();
//	return res;
//}

std::string reverseWords(const std::string&str)
{
	std::stringstream ss(str);
	std::string word;
	std::string res;
	std::stack<std::string> stack;
	while (std::getline(ss, word, ' '))
		stack.push(word);
	while (!stack.empty())
	{
		res += stack.top() + " ";
		stack.pop();
	}
	res.pop_back();
	return res;
}


int main()
{
	std::string str;
	getline(cin, str);
	cout << reverseWords(str) << endl;

	return 0;
}

