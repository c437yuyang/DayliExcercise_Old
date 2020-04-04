/*
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入描述:
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
输出描述:
输出树的高度，为一个整数
示例1
输入

5
0 1
0 2
1 3
1 4
输出

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
#include <unordered_set>
using namespace std;



void dfs(unordered_map<int, vector<int>> &mp, int curparent, int curres, int &res) {
	if (mp.find(curparent) == mp.end()) {
		res = std::max(res, curres);
		return;
	}

	for (int i = 0; i < mp[curparent].size(); ++i) {
		dfs(mp, mp[curparent][i], curres + 1, res);
	}
}

//这个做法本身是对的，但是题目有多叉树(针对多叉树也是对的)，必须只算多叉树中二叉树的部分
int getheight(vector<int>&parent, vector<int>&son) {

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < parent.size(); ++i) {
		mp[parent[i]].push_back(son[i]);
	}
	std::unordered_set<int> s_set(son.begin(), son.end());
	std::unordered_set<int> p_set(parent.begin(), parent.end());
	int root = -1;
	for (auto pval : p_set) { //找到root,没有出现在son_set中就是root
		if (s_set.find(pval) == s_set.end()) {
			root = pval;
			break;
		}
	}
	int curres = 1;
	int res = -1;
	dfs(mp, root, curres, res);

	return res;
}

//去掉多余两个节点的其他部分
int getheight1(vector<int>&parent, vector<int>&son) {

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < parent.size(); ++i) {
		if (mp[parent[i]].size() < 2) //多余两个节点就不要后面的了
			mp[parent[i]].push_back(son[i]);
	}
	std::unordered_set<int> s_set(son.begin(), son.end());
	std::unordered_set<int> p_set(parent.begin(), parent.end());
	int root = -1;
	for (auto pval : p_set) {
		if (s_set.find(pval) == s_set.end()) {
			root = pval;
			break;
		}
	}
	int curres = 1;
	int res = -1;
	dfs(mp, root, curres, res);

	return res;
}


int main() {

	int n;
	cin >> n;
	vector<int> p, s;
	int pp, ss;
	while (cin >> pp >> ss) {
		p.push_back(pp);
		s.push_back(ss);
	}
	cout << getheight1(p, s) << endl;

	return 0;
}