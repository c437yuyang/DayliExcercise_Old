/*
现在我们需要查出一些作弊的问答社区中的ID，作弊有两种：1.A回答了B的问题，同时B回答了A的问题。那么A和B都是作弊。2.作弊ID用户A和作弊ID用户B同时回答了C的问题，那么C也是作弊。已知每个用户的ID是一串数字，一个问题可能有多个人回答。
输入描述:
每组数据第一行为总问题数N(N小于等于200000)，第二行开始每行一个问题，第一个数字为提问人ID，第二个数字为回答人数，后面则为所有回答人的ID。(ID均为0-1000000的整数)
输出描述:
第一行为作弊ID数量，第二行开始为从小到大的每行一个作弊ID。
示例1
输入
复制
3
1 1 2
2 1 1
3 2 1 2
输出
复制
3
1 2 3
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
#include <unordered_set>
using namespace std;

struct Question {
	int queMan;
	vector<int> ansMan;
};

//其实题目很简单，就是遍历第一遍，看第一条规则，AB互相答题，用数据结构记录
//第二遍，看第二条规则，两个作弊的一起答第三个人的题
vector<int> solve(vector<Question> &quesions) {
	std::unordered_set<int> crimes;
	std::unordered_map<int, std::unordered_set<int>> mp;
	for (int i = 0; i < quesions.size(); ++i) {
		int queMan = quesions[i].queMan;
		for (int j = 0; j < quesions[i].ansMan.size(); ++j) {
			int ansMan = quesions[i].ansMan[j];
			if (queMan == ansMan)
				continue;
			mp[queMan].insert(ansMan);
			if (mp[ansMan].find(queMan) != mp[ansMan].end()) {
				crimes.insert(queMan);
				crimes.insert(ansMan);
			}
		}
	}
	if (crimes.size() >= 2) {
		for (int i = 0; i < quesions.size(); ++i) {
			int queMan = quesions[i].queMan;
			if (crimes.find(queMan) != crimes.end())
				continue;
			if (quesions[i].ansMan.size() > 1) {
				int cnt = 0;
				for (int j = 0; j < quesions[i].ansMan.size(); ++j) {
					int ansMan = quesions[i].ansMan[j];
					if (crimes.find(ansMan) != crimes.end()) {
						++cnt;
					}
				}
				if (cnt >= 2) {
					crimes.insert(queMan);
				}
			}
		}
	}
	set<int> s(crimes.begin(), crimes.end());
	return vector<int>(s.begin(), s.end());
}

int main() {
	int n;
	while (cin >> n) {
		vector<Question> questions(n);
		for (int i = 0; i < n; ++i) {
			cin >> questions[i].queMan;
			int queCnt = 0;
			cin >> queCnt;
			vector<int> ansMan(queCnt);
			for (int j = 0; j < queCnt; ++j) {
				cin >> ansMan[j];
			}
			questions[i].ansMan = ansMan;
		}
		auto res = solve(questions);
		cout << res.size() << endl;
		if (!res.empty()) {
			for (int i = 0; i < res.size(); ++i) {
				cout << res[i];
				if (i != res.size() - 1) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}