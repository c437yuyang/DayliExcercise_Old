/*
题目描述
有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。有一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到最多的宝石。
输入描述:
我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。每行代表一种情况。
输出描述:
输出学者能够拿到的最多的宝石数量。每行一个
示例1
输入
ABCYDYE
ATTMBQECPD
输出
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

//我写的这个有问题，而且慢，虽然复杂度一样，都是找每个开头，每个长度
//但是应该先找5长度开始的，然后增大，这样找到小的了就直接return了
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




//牛客看到的，环的处理很机智,这个版本也就是找每个开始，长度从5递增，效率最高
bool isPerfect(string str, int start, int length) {
	vector<bool> vec(5, false);//5个bool标记ABCDE是否找到
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
	str = str + str;//省去环处理
	for (int length = 5; length <= n; length++) {//长度
		for (int i = 0; i < n; i++) {//起点
			if (isPerfect(str, i, length)) {
				return n - length; //找到第一个就是最长的
			}
		}
	}
	return 0;
}


//另一个版本，双指针的方法，效率还是没有上个版本高
int solve2(std::string&s) {
	int len = s.length();
	s = s + s; //环处理
	int right = 0, left = 0, num = 0;
	int Min = len;
	map<char, int> book;
	while (true) {
		while (right < s.length() && num < 5) {
			if ((s[right] == 'A' || s[right] == 'B' || s[right] == 'C' || s[right] == 'D' || s[right] == 'E')
				&& book[s[right]]++ == 0)
				num++; //num记录abcde包含的数目
			right++;
		} //找到包含完ABCDE的或者结尾为止
		if (num < 5) break; //根本就不包含
		Min = min(Min, right - left);
		if ((s[left] == 'A' || s[left] == 'B' || s[left] == 'C' || s[left] == 'D' || s[left] == 'E')
			&& --book[s[left]] == 0) 
			num--; //移出去的是其中之一，更新num
		left++; //左指针移动
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