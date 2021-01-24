/*
给定一个字符串，问是否能通过添加一个字母将其变为回文串。
输入描述:
一行一个由小写字母构成的字符串，字符串长度小于等于10。
输出描述:
输出答案(YES\NO).
示例1
输入
coco
输出
YES
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

//我的思路:就是老老实实的去插
bool solve(const std::string&str) {
	for (int i = 0; i <= str.length(); ++i) {
		std::string strCopy = str;
		strCopy.insert(strCopy.begin() + i, '0'); //先随便添加一个占位
		strCopy[i] = strCopy[strCopy.length() - 1 - i]; //再找对应的位过来
		//strCopy.insert(strCopy.begin() + i, str[str.length() - 1 - i]); //这样是错的，不是原字符串的对应位
		std::string strCopy1(strCopy.rbegin(), strCopy.rend());
		if (strCopy == strCopy1) {
			return true;
		}
	}
	return false;
}

bool isPalindrome(const std::string&str) {
	return str == std::string(str.rbegin(), str.rend());
}

//牛客看到的:找到第一个前后不匹配的位置，然后检查之间的子串分别连接两端不匹配字符构成的两个串是否是回文串
bool solve1(const std::string&str) {
	if (str.length() == 1) //一个字母一定可以组成，插相同的
		return true;

	if (isPalindrome(str))
		return true; //本身是的话，加一个也肯定可以

	//找到第一个不相等的位置
	int left = 0, right = str.length() - 1;
	while (left < right && str[left] == str[right]) {
		++left;
		--right;
	}

	std::string strCopy = str;
	strCopy.insert(strCopy.begin() + left, '0'); //先随便添加一个占位
	strCopy[left] = strCopy[strCopy.length() - 1 - left]; //再找对应的位过来
	if (isPalindrome(strCopy))
		return true;

	strCopy = str;
	strCopy.insert(strCopy.begin() + right + 1, '0'); //右边要+1的位置
	strCopy[right + 1] = strCopy[strCopy.length() - 1 - (right + 1)]; //再找对应的位过来
	if (isPalindrome(strCopy))
		return true;

	return false;
}


int main() {
	std::string str;
	while (cin >> str) {
		cout << (solve1(str) ? "YES" : "NO") << endl;
	}
	return 0;
}