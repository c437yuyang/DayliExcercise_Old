/*
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"）， 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。
输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
示例1
输入
4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO
输出
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
要先依次解码具有独一无二字符的数字，具有这样特点的数字有五个分别是FOUR(U), SIX(X),
TWO(W), EIGHT(G), ZERO(Z), 可以根据独特字符的个数直接判断有多少个相应的数字，例如有
3个U那么就一定有3个FOUR..., 解码完成这五个数字之后另外的数字也会由于这些数字的移除
而具有了独一无二的字符，这样的数字有FIVE(F)，THREE(T), FIVE找到之后，只有SEVEN含
有V, 所以又可以依据V字符的个数解码SEVEN的个数，最后剩下的ONE和NINE也具有了自己的
标志性字符分别是ONE(O), NINE(I)，需要注意的是原始数字和最终出现的数字还有一个转换
的过程（加8取个位数），所以还要相应转换回去。最后要注意的是，要求每行字符串对应的
分身前的最小电话号码，不要傻傻的按照字典序排序，这样时间复杂度过高，对于这个问题
可以用桶排序，10个bucket分别用于统计0 - 9出现的次数，最终桶中存储的结果依次输出就是
所有组合中最小的数字。
*/

//牛客看到的
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


//我的做法超时,而且可能是错的
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
	//8对应原来0，最小，排在最前面，这样拿可能出错，应该要DFS考虑所有情况才行
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