/*
��Ŀ����
��һ����ɫ��ʯ���������ɺܶ��ֲ�ͬ�ı�ʯ��ɵģ������챦ʯ������ʯ����ʯ����䣬����ȡ���һ������������ʹ͸���һ��ѧ�ߣ�������˵������Դ����������������������ϲ���챦ʯ������ʯ����ˮ����������ʯ�����֣���Ҫ��������н�ȡ������һС�λ����ң���һ���б���������е������ֱ�ʯ��ʣ�µĲ�������Դ��ߡ�����޷��ҵ���һ��Ҳ�޷����ߡ������ѧ���ҳ�����з��������ܹ��õ����ı�ʯ��
��������:
������ÿ���ַ�����һ�ֱ�ʯ��A��ʾ�챦ʯ��B��ʾ����ʯ��C������ˮ����D������䣬E������ʯ��F������ʯ��G�������ȵȣ�������һ��ȫ��Ϊ��д��ĸ���ַ����б�ʾ�����ı�ʯ���У�ע����������β��ӵġ�ÿ�д���һ�������
�������:
���ѧ���ܹ��õ������ı�ʯ������ÿ��һ��
ʾ��1
����
ABCYDYE
ATTMBQECPD
���
1
3
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

bool checkContains(vector<int>&res) {
	int cnt = count_if(res.begin(), res.end(), [](int val) {return val < 1; });
	return cnt == 5;
}

//��д����������⣬����������Ȼ���Ӷ�һ����������ÿ����ͷ��ÿ������
//����Ӧ������5���ȿ�ʼ�ģ�Ȼ�����������ҵ�С���˾�ֱ��return��
int solve(std::string& str) {
	vector<int> cnt(5, 1);
	int res = 0;
	for (int i = 0; i < str.length(); ++i) {
		vector<int> cntcopy = cnt;
		bool first = true;
		for (int j = i; j != i || first;) {
			if (str[j] >= 'A' && str[j] <= 'E')
				cntcopy[str[j] - 'A'] -= 1;
			first = false;
			if (checkContains(cntcopy)) {
				if (i > j)
					res = std::max(i - j - 1, res);
				else {
					res = std::max((int)str.length() - j - 1, res);
				}
			}
			++j;
			if (j == str.length())
				j = 0;
		}
	}
	return res;
}




//ţ�Ϳ����ģ����Ĵ���ܻ���,����汾Ҳ������ÿ����ʼ�����ȴ�5������Ч�����
bool isPerfect(string str, int start, int length) {
	vector<bool> vec(5, false);//5��bool���ABCDE�Ƿ��ҵ�
	for (int i = 0; i < length; i++) {
		int index = str[start + i] - 'A';
		if (index < 5)
			vec[index] = true;
	}
	return vec[0] && vec[1] && vec[2] && vec[3] && vec[4];
}

int solve1(std::string&str) {
	int n = str.size();
	if (n <= 5) {
		return 0;
	}
	str = str + str;//ʡȥ������
	for (int length = 5; length <= n; length++) {//����
		for (int i = 0; i < n; i++) {//���
			if (isPerfect(str, i, length)) {
				return n - length; //�ҵ���һ���������
			}
		}
	}
	return 0;
}


//��һ���汾��˫ָ��ķ�����Ч�ʻ���û���ϸ��汾��
int solve2(std::string&s) {
	int len = s.length();
	s = s + s; //������
	int right = 0, left = 0, num = 0;
	int Min = len;
	map<char, int> book;
	while (true) {
		while (right < s.length() && num < 5) {
			if ((s[right] == 'A' || s[right] == 'B' || s[right] == 'C' || s[right] == 'D' || s[right] == 'E')
				&& book[s[right]]++ == 0)
				num++; //num��¼abcde��������Ŀ
			right++;
		} //�ҵ�������ABCDE�Ļ��߽�βΪֹ
		if (num < 5) break; //�����Ͳ�����
		Min = min(Min, right - left);
		if ((s[left] == 'A' || s[left] == 'B' || s[left] == 'C' || s[left] == 'D' || s[left] == 'E')
			&& --book[s[left]] == 0) 
			num--; //�Ƴ�ȥ��������֮һ������num
		left++; //��ָ���ƶ�
	}
	return  len - Min;
}

int main() {
	std::string str;
	while (cin >> str) {
		cout << solve1(str) << endl;
	}


	return 0;
}