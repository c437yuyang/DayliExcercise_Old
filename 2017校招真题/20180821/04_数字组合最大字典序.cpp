/*
����n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
��:n=3ʱ��3������13,312,343,���ɵ��������Ϊ34331213��
��:n=4ʱ,4������7,13,4,246���ӳɵ��������Ϊ7424613��
��������:
�ж������������ÿ����������������У���һ��Ϊһ������N��N<=100�����ڶ��а���N����(ÿ����������1000���ո�ֿ�)��
�������:
ÿ���������һ����ʾ����������
ʾ��1
����

2
12 123
4
7 13 4 246
���

12312
7424613
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
using namespace std;


std::string solve(vector<string>&strs) {
	sort(strs.begin(), strs.end(), 
		[](const std::string&str1, const std::string&str2) {return str1 + str2 > str2 + str1; });
	std::string res;
	for (int i = 0; i < strs.size(); ++i)
		res += strs[i];

	return res;
}


int main() {
	int n;
	while (cin >> n) {
		vector<string> strs(n);
		for (int i = 0; i < n; ++i) {
			cin >> strs[i];
		}
		cout << solve(strs) << endl;
	}



	return 0;
}