/*
��Ŀ����
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
��������:
ÿ�������������2���ַ���
�������:
���ɾ������ַ���
ʾ��1
����
����
They are students. aeiou
���
����
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