/*
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I
��������:
ÿ�������������1������������ I like beijing. �����������Ȳ�����100
�������:
�����������֮����ַ���,�Կո�ָ�
ʾ��1
����
����
I like beijing.
���
����
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

//����Ƿ�ת����ÿ����������ĸ��˳����
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

