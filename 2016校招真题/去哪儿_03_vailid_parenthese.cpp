/*
写一段代码，判断一个包括'{','[','(',')',']','}'的表达式是否合法(注意看样例的合法规则。)

给定一个表达式A,请返回一个bool值，代表它是否合法。

测试样例：
"[a+b*(5-4)]*{x+b+b*(({1+2)}}"
返回：true
*/

//这道题是左右不一定匹配也可以，只要是左边类型一个，右边类型一个即可，比如]可以匹配{

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

class ChkExpression {
public:
	bool chkLegal(string s) {
		string left = "([{";
		string right = ")]}";

		std::unordered_set<char> parentheseSet = { '(',')',']','[','{','}' };

		stack<char> stk;
		for (auto c : s) {
			if (parentheseSet.find(c) == parentheseSet.end())
				continue;
			if (left.find(c) != string::npos) {
				stk.push(c);
			} else {
				if (stk.empty() || right.find(c) == string::npos) //这道题是左右不一定匹配也可以，只要是左边类型一个，右边类型一个即可，比如]可以匹配{
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
	}
};

int main() {

	string str = "[a+b*(5-4)]*{x+b+b*({1+2)}}";
	ChkExpression s;
	auto res = s.chkLegal(str);

	return 0;
}