/*
������һ�úϷ��Ķ����������Ľڵ㶼�������ֱ�ʾ�����ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
��������:
����ĵ�һ�б�ʾ�ڵ�ĸ���n��1 �� n �� 1000���ڵ�ı��Ϊ0��n-1����ɣ�
������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��
�������:
������ĸ߶ȣ�Ϊһ������
ʾ��1
����

5
0 1
0 2
1 3
1 4
���

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

//������������ǶԵģ�������Ŀ�ж����(��Զ����Ҳ�ǶԵ�)������ֻ�������ж������Ĳ���
int getheight(vector<int>&parent, vector<int>&son) {

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < parent.size(); ++i) {
		mp[parent[i]].push_back(son[i]);
	}
	std::unordered_set<int> s_set(son.begin(), son.end());
	std::unordered_set<int> p_set(parent.begin(), parent.end());
	int root = -1;
	for (auto pval : p_set) { //�ҵ�root,û�г�����son_set�о���root
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

//ȥ�����������ڵ����������
int getheight1(vector<int>&parent, vector<int>&son) {

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < parent.size(); ++i) {
		if (mp[parent[i]].size() < 2) //���������ڵ�Ͳ�Ҫ�������
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