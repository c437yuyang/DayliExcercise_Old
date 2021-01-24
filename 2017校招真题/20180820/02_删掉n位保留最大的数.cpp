/*
��Ŀ����
����һ��ʮ���Ƶ�������number��ѡ�������ȥ��һ�������֣�ϣ������������������ɵ����������
��������:
����Ϊ�������ݣ���һ����������number��1 �� length(number) �� 50000���ڶ�����ϣ��ȥ������������cnt 1 �� cnt < length(number)��
�������:
������������Ľ����
ʾ��1
����
325 1
���
35
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
using namespace std;

//ţ�Ϳ����Ľⷨ:
//˼·��ÿ��ɾ����һ����ǰ�ַ�С�ں�һ���ַ����ַ�
string solve(string &number, int cnt) {
	int i = 0;
	while (i < cnt) {
		int j = 0;
		while (j < number.size() - 1 && number[j] >= number[j + 1]) {
			++j;
		}
		number.erase(j, 1); //���û���ҵ��Ļ�����ɾ�����һ������Ϊ���һ��������С��
		++i;
	}
	return number;
}



//dfs�϶���ʱ
void dfs(string &number, int cnt, string&res) {
	if (cnt == 0) {
		if (atoi(res.c_str()) < atoi(number.c_str())) {
			res = number;
		}
		return;
	}
	for (int i = 0; i < number.length(); ++i) {
		char c = number[i];
		number.erase(number.begin() + i);
		dfs(number, cnt - 1, res);
		number.insert(number.begin() + i, c);
	}
}

string solve1(string &number, int cnt) {

	if (number.length() <= cnt)
		return "0";
	string res = "0";
	dfs(number, cnt, res);
	return res;
}



int main() {

	string number;
	int cnt;
	while (cin >> number >> cnt)
		cout << solve(number, cnt) << endl;

	return 0;
}