/*
题目描述
请设计一个高效算法，再给定的字符串数组中，找到包含"Coder"的字符串(不区分大小写)，并将其作为一个新的数组返回。结果字符串的顺序按照"Coder"出现的次数递减排列，若两个串中"Coder"出现的次数相同，则保持他们在原数组中的位置关系。

给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300,其中每个串的长度小于等于200。同时保证一定存在包含coder的字符串。

测试样例：
["i am a coder","Coder Coder","Code"],3
返回：["Coder Coder","i am a coder"]
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

class Coder {
public:

	struct data {
		std::string str;
		int cnt;
		int pos; //记录先后次序
	};

	//void to_lower(std::string &str) {
	//	for (int i = 0; i < str.length(); ++i) {
	//		str[i] = tolower(str[i]);
	//	}
	//}

	int getcnt(string&str) {
		string copy = str;
		std::transform(copy.begin(), copy.end(), copy.begin(), tolower); //GCC过不了，就自己写了个方法,GCC下面tolower有问题，自己用lambda就行了
		//to_lower(copy);

		int pos = 0;
		int res = 0;
		while (pos < copy.length()) {
			pos = copy.find("coder", pos);
			if (pos == -1)
				break;

			++res;
			pos += 5;
		}
		return res;

	}

	vector<string> findCoder(vector<string> A, int n) {
		// write code here
		vector<data> res;
		for (int i = 0; i < A.size(); ++i) {
			std::string str = A[i];
			int cnt = getcnt(str);
			if (cnt > 0)
				res.push_back({ str,getcnt(str),i });
		}

		std::sort(res.begin(), res.end(), [](const data&d1, const data&d2) {
			if (d1.cnt == d2.cnt)
				return d1.pos < d2.pos;
			return d1.cnt > d2.cnt;
		});

		vector <string> ret;
		for (int i = 0; i < res.size(); ++i) {
			ret.push_back(res[i].str);
		}
		return ret;

	}
};


int main() {

	Coder c;
	vector<string> v = { "i am a coder","Coder Coder","Code" };
	int n = 3;
	auto res = c.findCoder(v, 3);
	//std::for_each()


	return 0;
}


