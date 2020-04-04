/*
现在有一个字符串列表，和一个关键词列表，请设计一个高效算法，检测出含关键字列表中关键字(一个或多个)的字符串。

给定字符串数组A及它的大小n以及关键词数组key及它的大小m，请返回一个排好序的含关键词的字符串序号的列表。保证所有字符串长度小于等于100，关键词个数小于等于100，字符串个数小于等于200。保证所有字符串全部由小写英文字符组成。若不存在含关键字的字符串，请返回一个只含-1的数组。

测试样例：
["nowcoder","hello","now"],3,["coder",now],2
返回：[0,2]
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
#include <set>
using namespace std;

//就是暴力解，没啥意思
class KeywordDetect {
public:
	vector<int> containKeyword(vector<string> arr, int n, vector<string> keys, int m) {
		// write code here
		set<int> res;

		for (int i = 0; i < arr.size(); ++i) {
			for (int j=0;j<keys.size();++j)
			{
				if (arr[i].find(keys[j]) != string::npos) {
					res.insert(i);
					break;
				}
			}
		}

		if (res.empty()) {
			return{ -1 };
		}

		return vector<int>(res.begin(), res.end());

	}
};

int main() {

	vector<string> arr = { "nowcoder","hello","now" };
	vector<string> keys = { "coder","now" };

	KeywordDetect k;
	auto res = k.containKeyword(arr, arr.size(), keys, keys.size());

	return 0;
}