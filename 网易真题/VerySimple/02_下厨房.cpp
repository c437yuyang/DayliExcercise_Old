/*
ţţ�볢��һЩ�µ�����ÿ��������ҪһЩ��ͬ�Ĳ��ϣ���������е�������Ҫ׼�������ֲ�ͬ�Ĳ��ϡ�
��������:
ÿ��������� 1 ������������ÿ�����������ĵ� i �У���ʾ��ɵ� i ��������Ҫ��Щ���ϣ����������ÿո����������ֻ������дӢ����ĸ�Ϳո������ļ������� 50 �У�ÿһ�в����� 50 ���ַ���
�������:
���һ��һ�����ֱ�ʾ�������������Ҫ�����ֲ�ͬ�Ĳ��ϡ�
ʾ��1
����

BUTTER FLOUR
HONEY FLOUR EGG
���

4
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;
int main() 
{
	std::string str;
	std::unordered_set<std::string> set;
	while (cin >> str) 
	{
		set.insert(str);
	}


	std::cout << set.size() << std::endl;

	return 0;
}