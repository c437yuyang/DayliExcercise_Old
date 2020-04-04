/*
��MIUI8�Ƴ��ֻ�������֮��MIUI9�ƻ��Ƴ�һ���绰�������Ĺ��ܣ����Ƚ��绰�����е�ÿ�����ּ���8ȡ��λ��Ȼ��ʹ�ö�Ӧ�Ĵ�д��ĸ���� ��"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"���� Ȼ�����������Щ��ĸ�������ɵ��ַ�����Ϊ�绰�����Ӧ�ķ���
��������:
��һ����һ������T��1 �� T �� 100)��ʾ������������������T�У�ÿ�и���һ�������ĵ绰����ķ���������3��10000֮�䣩��
�������:
���T�У��ֱ��Ӧ������ÿ���ַ�����Ӧ�ķ���ǰ����С�绰���루����ǰ��0����
ʾ��1
����
4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO
���
0
234
345
0345
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


/*
Ҫ�����ν�����ж�һ�޶��ַ������֣����������ص������������ֱ���FOUR(U), SIX(X),
TWO(W), EIGHT(G), ZERO(Z), ���Ը��ݶ����ַ��ĸ���ֱ���ж��ж��ٸ���Ӧ�����֣�������
3��U��ô��һ����3��FOUR..., ����������������֮�����������Ҳ��������Щ���ֵ��Ƴ�
�������˶�һ�޶����ַ���������������FIVE(F)��THREE(T), FIVE�ҵ�֮��ֻ��SEVEN��
��V, �����ֿ�������V�ַ��ĸ�������SEVEN�ĸ��������ʣ�µ�ONE��NINEҲ�������Լ���
��־���ַ��ֱ���ONE(O), NINE(I)����Ҫע�����ԭʼ���ֺ����ճ��ֵ����ֻ���һ��ת��
�Ĺ��̣���8ȡ��λ���������Ի�Ҫ��Ӧת����ȥ�����Ҫע����ǣ�Ҫ��ÿ���ַ�����Ӧ��
����ǰ����С�绰���룬��Ҫɵɵ�İ����ֵ�����������ʱ�临�Ӷȹ��ߣ������������
������Ͱ����10��bucket�ֱ�����ͳ��0 - 9���ֵĴ���������Ͱ�д洢�Ľ�������������
�����������С�����֡�
*/

//ţ�Ϳ�����
void solve1(string s) {
	int j = 0;
	vector<int> iimap(256);
	for (j = 0; j < s.size(); j++) {
		iimap[s[j]]++;
	}
	vector<int> res(10);
	int count = iimap['U'];
	res[6] = count; //6+8=14 -> four
	iimap['F'] -= count;
	iimap['O'] -= count;
	iimap['U'] -= count;
	iimap['R'] -= count;

	count = iimap['X'];
	res[8] = count;
	iimap['S'] -= count;
	iimap['I'] -= count;
	iimap['X'] -= count;

	count = iimap['W'];
	res[4] = count;
	iimap['T'] -= count;
	iimap['W'] -= count;
	iimap['O'] -= count;

	count = iimap['G'];
	res[0] = count;
	iimap['E'] -= count;
	iimap['I'] -= count;
	iimap['G'] -= count;
	iimap['H'] -= count;
	iimap['T'] -= count;

	count = iimap['Z'];
	res[2] = count;
	iimap['Z'] -= count;
	iimap['E'] -= count;
	iimap['R'] -= count;
	iimap['O'] -= count;

	count = iimap['F'];
	res[7] = count;
	iimap['F'] -= count;
	iimap['I'] -= count;
	iimap['V'] -= count;
	iimap['E'] -= count;

	count = iimap['V'];
	res[9] = count;
	iimap['S'] -= count;
	iimap['E'] -= count;
	iimap['V'] -= count;
	iimap['E'] -= count;
	iimap['N'] -= count;

	count = iimap['T'];
	res[5] = count;
	iimap['T'] -= count;
	iimap['H'] -= count;
	iimap['R'] -= count;
	iimap['E'] -= count;
	iimap['E'] -= count;

	count = iimap['O'];
	res[3] = count;
	iimap['O'] -= count;
	iimap['N'] -= count;
	iimap['E'] -= count;

	count = iimap['I'];
	res[1] = count;
	iimap['N'] -= count;
	iimap['I'] -= count;
	iimap['N'] -= count;
	iimap['E'] -= count;

	for (int k = 0; k < res.size(); k++) {
		for (int l = 0; l < res[k]; l++)
			cout << k;
	}
	cout << endl;

}


//�ҵ�������ʱ,���ҿ����Ǵ��
bool checkContains(string&word, unordered_map<char, int> &mp, unordered_map<string, unordered_map<char, int>>& wordsmp) {
	bool sat = true;
	for (auto it = wordsmp[word].begin(); it != wordsmp[word].end(); ++it) {
		if (mp[it->first] < it->second) {
			sat = false;
			break;
		}
	}
	if (sat) {
		for (auto it = wordsmp[word].begin(); it != wordsmp[word].end(); ++it) {
			mp[it->first] -= it->second;
		}
		return true;
	}
	return false;
}

string solve(std::string& str) {
	unordered_map<char, int> mp;
	for (auto c : str) {
		++mp[c];
	}
	//8��Ӧԭ��0����С��������ǰ�棬�����ÿ��ܳ���Ӧ��ҪDFS���������������
	vector<string> words = { "EIGHT", "NINE" , "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN" };
	unordered_map<string, unordered_map<char, int>> wordsmp;
	for (auto word : words)
		for (auto c : word)
			++wordsmp[word][c];

	int solvedLen = 0;
	std::string res = "";
	while (solvedLen < str.length()) {
		for (int i = 0; i < words.size(); ++i) {
			if (checkContains(words[i], mp, wordsmp)) {
				solvedLen += words[i].length();
				res += to_string(i);
				break;
			}
		}
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		std::string str;
		cin >> str;
		//cout << solve(str) << endl;
		solve1(str);
	}

	return 0;
}